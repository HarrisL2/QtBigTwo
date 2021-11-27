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
        lastPlayer = data["lastPlayer"].toString();
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

QJsonObject ClientLogic::getLastPlays() const {
    return lastPlays;
}

QString ClientLogic::getCurrPlayer() const {
    return currentPlayer;
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
                sendPlay(comb);
            }
        } else {
            if (comb->getType() == Combination::Type::PASS) {
                sendPlay(comb);
                return;
            }
            QJsonArray tempComb = lastPlays[lastPlayer].toArray();
            QVector<int> combInts;
            for (int i = 0; i < tempComb.size(); i++) {
                combInts.append(tempComb[i].toInt());
            }
            Combination* lastComb = Combination::createCombination(combInts);
            if (*comb > *lastComb) {
                if (lastComb->getLastCard()->getType() == BaseCard::Type::UNO && comb->getFirstCard()->getType() == BaseCard::Type::UNO) {
                    if (lastComb->getLastCard()->getColor() != comb->getFirstCard()->getColor()) {
                        QMessageBox msg;
                        msg.setText("Card color does not match previous play!");
                        msg.exec();
                    } else {
                        sendPlay(comb);
                    }
                } else {
                    sendPlay(comb);
                }
            } else {
                QMessageBox msg;
                msg.setText("Invalid play!");
                msg.exec();
            }
        }
    }
}

void ClientLogic::sendPlay(Combination* comb) {
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

bool ClientLogic::waitingForPlay() const {
    return currentPlayer == name;
}
