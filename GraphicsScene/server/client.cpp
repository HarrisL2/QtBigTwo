#include "client.h"

#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtDebug>

Client::Client(QObject* parent) :
    QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::readData);
}

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

void Client::readData() {
    QByteArray rawData;
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream >> rawData;
    const QJsonDocument data = QJsonDocument::fromJson(rawData);

    emit dataRecieved(data.object());
}

void Client::sendData(const QJsonObject &data) {
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream << QJsonDocument(data).toJson(QJsonDocument::Compact);
}

void Client::setName(QString name) {
    this->name = name;
}

QString Client::getName() {
    return name;
}
