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

/*
 *  Server::get<var>()
 *  @funct: return corresponding data member
 *  @param: N/A
 *  @return: int port / string ip
 */

quint16 Server::getPort() const {return port;}
QString Server::getIP() const {return ip;}

void Server::incomingConnection(qintptr handle) {
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

/*
 *  Server::clientDisconnected(Worker* client)
 *  @funct: disconnect the specific client from the server
 *  @param: client: client to be disconnected
 *  @return: N/A
 */

void Server::clientDisconnected(Worker* client) {
    clients.removeAll(client);
    client->deleteLater();
}

/*
 *  Server::broadcast(const QJsonObject &data, Worker *exclude)
 *  @funct: send data to all client except the excluded one
 *  @param: data: data to be sent
 *          exclude: client that will not receive the data
 *  @return: N/A
 */

void Server::broadcast(const QJsonObject &data, Worker *exclude) {
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i] != exclude) {
            clients[i]->sendData(data);
        }
    }
}

/*
 *  Server::getPlayerNames()
 *  @funct: return player's name
 *  @param: N/A
 *  @return: string playerNames
 */

QJsonArray Server::getPlayerNames() const {
    return playerNames;
}

/*
 *  Server::sendDataTo(QString name, const QJsonObject& data)
 *  @funct: send data to specific client
 *  @param: name: name of the client
 *          data: the data to be sent to the client
 *  @return: N/A
 */

void Server::sendDataTo(QString name, const QJsonObject& data) {
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i]->getName() == name) {
            clients[i]->sendData(data);
        }
    }
}
