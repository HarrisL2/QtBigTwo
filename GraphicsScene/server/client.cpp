#include "client.h"

#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtDebug>

/*
 *  Client::Client(QObject* parent)
 *  @funct: craete a client object for data transfer
 *  @param: parent
 *  @return: N/A
 */

Client::Client(QObject* parent) :
    QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::readData);
}

/*
 *  Client::connectToServer(const QHostAddress& adress, quint16 port)
 *  @funct: attempt to connect to the given address
 *  @param: adress, port
 *  @return: N/A
 */

void Client::connectToServer(const QHostAddress& adress, quint16 port) {
    socket->connectToHost(adress,port);
    if (socket->state() == QTcpSocket::ConnectedState ||
        socket->state() == QTcpSocket::ConnectingState ) {
        QJsonObject data;
        data["type"] = "newPlayer";
        data["name"] = this->name;
        this->sendData(data);
    } else {
        emit connectionFailed();
    }
}

/*
 *  Client::readData()
 *  @funct: read the data from the TcpSocket and emit it as Json file
 *  @param: N/A
 *  @return: N/A
 */

void Client::readData() {
    QByteArray rawData;
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream >> rawData;
    const QJsonDocument data = QJsonDocument::fromJson(rawData);
    emit dataRecieved(data.object());
    socket->readAll();
}

/*
 *  Client::sendData(const QJsonObject &data)
 *  @funct: send the given Json file as data through TcpSocket
 *  @param: data to be sent
 *  @return: N/A
 */


void Client::sendData(const QJsonObject &data) {
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream << QJsonDocument(data).toJson(QJsonDocument::Compact);
}

/*
 *  Client::setName(QString name)
 *  @funct: set the name of this client
 *  @param: name
 *  @return: N/A
 */

void Client::setName(QString name) {
    this->name = name;
}

/*
 *  Client::getName
 *  @funct: get the name of this client
 *  @param: N/A
 *  @return: name
 */

QString Client::getName() {
    return name;
}
