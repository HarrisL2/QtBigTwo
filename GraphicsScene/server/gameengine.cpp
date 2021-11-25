#include <QRandomGenerator>
#include <QtDebug>

#include "gameengine.h"
#include "../client/playingcard.h"
#include "../client/unocard.h"

GameEngine::GameEngine(Server* ser, int AICount, int playerCount, bool UNOMode, QObject* parent) :
    QObject(parent),
    server(ser),
    AICount(AICount),
    playerCount(playerCount),
    UNOMode(UNOMode)
{
    playerNames = server->getPlayerNames();
    for (int i = 0; i < AICount; i++) {
        playerNames.append("AI"+QString::number(i+1));
    }
    for (int i = 1; i <= 52; i++) {
        deck.append(new PlayingCard(i));
    }
    if (UNOMode) {
        for (int i = 101; i <= 152; i++) {
            deck.append(new UNOCard(i));
        }
    }
    for (int i = deck.size()-1; i > 0; i--) {
        int j = i*QRandomGenerator::global()->generateDouble();
        BaseCard* temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    for (int i = 0; i < playerNames.size(); i++) {
        QJsonArray newHand;
        for (int j = 0; j < 13; j++) {
            BaseCard* temp = deck.takeLast();
            newHand.append(temp->getID());
        }
        playerHands[playerNames[i].toString()] = newHand;
    }
    currentPlayer = playerNames.begin();
    for (int i = 0; i < int(playerNames.size()*QRandomGenerator::global()->generateDouble()); i++) {
        currentPlayer++;
    }
    nextPlayer = currentPlayer+1 == playerNames.end() ? playerNames.begin() : currentPlayer+1;
    turnDirection = 1;
    updateAll();
}

void GameEngine::recieveData(Worker* sender, const QJsonObject& data) {

}

void GameEngine::updateAll() {
    for (int i = 0; i < playerNames.size(); i++) {
        QJsonObject data;
        data["type"] = "gameInfo";
        data["deckSize"] = deck.size();
        QJsonArray jsonStack;
        for (int j = 0; j < stack.size(); j++) {
            QJsonArray jsonComb;
            for (int k = 0; k < stack[j]->size(); k++) {
                jsonComb.append(stack[j]->getCards()[k]->getID());
            }
            jsonStack.append(jsonComb);
        }
        data["stack"] = jsonStack;
        QJsonObject tempHands = playerHands;
        for (int j = 0; j < playerNames.size(); j++) {
            if (playerNames[i] != playerNames[j]) {
                QJsonArray tempHand = tempHands[playerNames[j].toString()].toArray();
                for (int k = 0; k < tempHand.size(); k++) {
                    if (tempHand[k].toInt() < 99) {
                        tempHand[k] = 0;
                    } else {
                        tempHand[k] = 100;
                    }
                }
                tempHands[playerNames[j].toString()] = tempHand;
            }
        }
        data["hands"] = tempHands;
        data["currPlayer"] = *currentPlayer;
        data["turnDir"] = turnDirection;
        server->sendDataTo(playerNames[i].toString(),data);
    }
}
