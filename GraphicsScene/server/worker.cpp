#include "worker.h"
#include <QJsonObject>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>

/*
 *  Worker::Worker(QObject* parent)
 *  @funct: create a worker object that handles the reading and sending of data for server
 *  @param: parent
 *  @return: N/A
 */

Worker::Worker(QObject* parent) :
    QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Worker::readData);
}

/*
 *  Worker::setSocketDescriptor(qintptr ptr)
 *  @funct: give the worker a socket descriptor to run on
 *  @param: pointer to socket
 *  @return: validity of the socket
 */

bool Worker::setSocketDescriptor(qintptr ptr) {
    return socket->setSocketDescriptor(ptr);
}

/*
 *  Worker::readData()
 *  @funct: read the data from the socket and emit as Json File
 *  @param: N/A
 *  @return: N/A
 */

void Worker::readData() {
    QByteArray rawData;
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream >> rawData;
    const QJsonDocument data = QJsonDocument::fromJson(rawData);
    if (data["type"] == "newPlayer") {
        name = data["name"].toString();
    }

    emit dataRecieved(data.object());
}

/*
 *  Worker::sendData(const QJsonObject& data)
 *  @funct: send given Json File as data from the socket
 *  @param: json file
 *  @return: N/A
 */

void Worker::sendData(const QJsonObject& data) {
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_12);
    stream << QJsonDocument(data).toJson(QJsonDocument::Compact);
}

/*
 *  Worker::disconnect()
 *  @funct: disconnect from the client
 *  @param: N/A
 *  @return: N/A
 */

void Worker::disconnect() {
    socket->disconnectFromHost();
    emit clientDisconnected();
}

/*
 *  Worker::set/getName
 *  @funct: set/get the name of the client
 *  @param: name
 *  @return: name
 */

void Worker::setName(const QString &name) {
    this->name = name;
}

QString Worker::getName() {
    return name;
}
