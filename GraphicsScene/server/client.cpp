#include "client.h"

#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>


Client::Client(QObject* parent) :
    QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::readData);
}

void Client::connectToServer(const QHostAddress& adress, quint16 port) {
    socket->connectToHost(adress,port);
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
