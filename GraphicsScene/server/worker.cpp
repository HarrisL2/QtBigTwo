#include "worker.h"
#include <QJsonObject>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>

Worker::Worker(QObject* parent) :
    QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Worker::readData);
}

bool Worker::setSocketDescriptor(qintptr ptr) {
    return socket->setSocketDescriptor(ptr);
}

void Worker::readData() {
    QByteArray rawData;
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream >> rawData;
    const QJsonDocument data = QJsonDocument::fromJson(rawData);

    emit dataRecieved(data.object());
}

void Worker::sendData(const QJsonObject& data) {
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream << QJsonDocument(data).toJson(QJsonDocument::Compact);
}

void Worker::disconnect() {
    socket->disconnectFromHost();
    emit clientDisconnected();
}

void Worker::setName(const QString &name) {
    this->name = name;
}

QString Worker::getName() {
    return name;
}
