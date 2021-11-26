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
        playerNames = data["players"].toArray();
        currentPlayer = data["currPlayer"].toString();
        lastPlayer = data["lastPlater"].toString();
        playerHands = data["hands"].toObject();
        turnDir = data["turnDir"].toInt();
        lastPlays = data["lastPlays"].toObject();
    }
    emit dataChanged();
}

QString ClientLogic::getName() const {
    return name;
}

QJsonArray ClientLogic::getNames() const {
    return playerNames;
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
        } else {
            QJsonArray tempComb = lastPlays[lastPlayer].toArray();
            QVector<int> combInts;
            for (int i = 0; i < tempComb.size(); i++) {
                combInts.append(tempComb[i].toInt());
            }
            Combination* lastComb = Combination::createCombination(combInts);
            if (comb->getType() == Combination::Type::PASS) {
                QJsonObject data;
                data["type"] = "newPlay";
                QJsonArray play;
                QVector<BaseCard*> cards = comb->getCards();
                for (int i = 0; i < cards.size(); i++) {
                    play.append(cards[i]->getID());
                }
                data["play"] = play;
                client->sendData(data);
            } else if (lastComb->size() != comb->size()) {
                QMessageBox msg;
                msg.setText("Play type does not match previous.");
                msg.exec();
            } if (lastComb->getLastCard()->getType() == BaseCard::Type::UNO &&
                (lastComb->getLastCard()->getColor() != comb->getFirstCard()->getColor())) {
                QMessageBox msg;
                msg.setText("Play color does not match previous.");
                msg.exec();
            } else {

            }
        }
    }
}

bool ClientLogic::waitingForPlay() const {
    return currentPlayer == name;
}
