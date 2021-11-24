#include <QNetworkInterface>
#include <QJsonObject>

#include "server.h"

Server::Server(QObject* parent) :
    QTcpServer(parent)
{
    if (!listen()) {
        close();
        return;
    }

    port = this->serverPort();

    QList<QHostAddress> ipList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipList.size(); i++) {
        if (ipList[i] != QHostAddress::LocalHost && ipList[i].toIPv4Address()) {
            ip = ipList[i].toString();
            break;
        }
    }
}

quint16 Server::getPort() const {return port;}
QString Server::getIP() const {return ip;}

void Server::incomingConnection(qintptr handle) {
    qDebug() << "connected";
    Worker* worker = new Worker(this);
    if (!worker->setSocketDescriptor(handle)) {
        worker->deleteLater();
        return;
    }
    connect(worker, &Worker::dataRecieved, this, std::bind(&Server::readData, this, worker, std::placeholders::_1));
    connect(worker, &Worker::clientDisconnected, this, std::bind(&Server::clientDisconnected, this, worker));
    clients.append(worker);
}

void Server::readData(Worker* client, const QJsonObject& data) {
    //server specific work here
    if (data["type"] == "newPlayer") {
        QString newName = data["name"].toString();
        if (!playerNames.contains(newName)) {
            playerNames.append(newName);

            QJsonObject newData;
            newData["type"] = "nameList";
            newData["list"] = playerNames;
            broadcast(newData);
        } else {
            QJsonObject newData;
            newData["type"] = "repeatedName";
            client->sendData(newData);
        }
    }

    emit this->recievedData(client, data);
}

void Server::clientDisconnected(Worker* client) {
    clients.removeAll(client);
    client->deleteLater();
}

void Server::broadcast(const QJsonObject &data, Worker *exclude) {
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i] != exclude) {
            clients[i]->sendData(data);
        }
    }
}

QJsonArray Server::getPlayerNames() const {
    return playerNames;
}
