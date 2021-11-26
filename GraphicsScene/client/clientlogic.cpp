#include "clientlogic.h"
#include "combination.h"

#include <QMessageBox>
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
        lastPlayer = data["lastPlater"].toString();
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

void ClientLogic::processPlay(QVector<int> input) {
    Combination* comb = Combination::createCombination(input);
    if (!waitingForPlay()) {
        QMessageBox msg;
        msg.setText("It is not your turn yet.");
        msg.exec();
    } else if (!comb) {
        QMessageBox msg;
        msg.setText("Invalid play!");
        msg.exec();
    } else {
        if (lastPlayer == currentPlayer) {
            if (comb->getType() == Combination::Type::PASS) {
                QMessageBox msg;
                msg.setText("Cannot pass.");
                msg.exec();
            } else {
                QJsonObject data;
                data["type"] = "newPlay";
                QJsonArray play;
                QVector<BaseCard*> cards = comb->getCards();
                for (int i = 0; i < cards.size(); i++) {
                    play.append(cards[i]->getID());
                }
                data["play"] = play;
                client->sendData(data);
            }
        }
    }
}

bool ClientLogic::waitingForPlay() const {
    return currentPlayer == name;
}
