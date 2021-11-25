#include "clientlogic.h"

#include <QtDebug>

ClientLogic::ClientLogic(Client* client) :
    client(client),
    name(client->getName())
{
    qDebug() << "constructing";
    connect(client, &Client::dataRecieved, this, &ClientLogic::recieveData);
    qDebug() << "constructed";
}

void ClientLogic::recieveData(const QJsonObject& data) {
    qDebug() << data;
    if (data["type"] == "gameInfo") {
        currentPlayer = data["currPlayer"].toString();
        playerHands = data["hands"].toObject();
        turnDir = data["turnDir"].toInt();
    }
    emit dataChanged();
}

QString ClientLogic::getName() const {
    return name;
}

QJsonObject ClientLogic::getHands() const {
    return playerHands;
}
