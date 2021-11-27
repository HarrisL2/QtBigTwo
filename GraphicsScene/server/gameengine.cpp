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
        playerNames.append("AI "+QString::number(i+1));
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
        Hand sort(newHand);
        newHand = sort.toJsonArray();
        playerHands[playerNames[i].toString()] = newHand;

        QJsonArray newPlay;
        lastPlays[playerNames[i].toString()] = newPlay;
    }
    currentPlayer = playerNames.begin();
    for (int i = 0; i < int(playerNames.size()*QRandomGenerator::global()->generateDouble()); i++) {
        currentPlayer++;
    }
    lastPlayer = currentPlayer;
    nextPlayer = currentPlayer+1 == playerNames.end() ? playerNames.begin() : currentPlayer+1;
    turnDirection = 1;
    updateAll();
    connect(server, &Server::recievedData, this, &GameEngine::recieveData);
}

bool GameEngine::canPlay(BaseCard* lastCard, BaseCard* handCard) const {
    int lastNum = lastCard->getNumber();
    int handNum = handCard->getNumber();
    if (lastNum == handNum) { //(lastNum < 3 ? lastNum + 13 : lastNum) == (handNum < 3 ? handNum + 13 : handNum)
        if (lastCard->getType() != handCard->getType()) {
            return true;
        } else if (lastCard->getType() == BaseCard::Type::UNO) {
            return false;
        } else if (lastCard->getType() == BaseCard::Type::PLAYING) {
            if (handCard->getID() > lastCard->getID()) {
                return true;
            }
        }
    } else if ((lastNum < 3 ? lastNum + 13 : lastNum) < (handNum < 3 ? handNum + 13 : handNum)) {
        if (lastCard->getType() == BaseCard::Type::UNO && handCard->getType() == BaseCard::Type::UNO) {
            if (lastCard->getColor() != handCard->getColor()) {
                return false;
            }
        }
        return true;
    }
    return false;
}

QVector<int> GameEngine::getSingle(Hand hand, BaseCard* lastCard) const {
    for (int i = 0; i < hand.getCards().size(); i++) {
        BaseCard* card = hand.getCards().at(i);
        if (canPlay(lastCard, card)) {
            QVector<int> temp;
            temp.append(card->getID());
            return temp;
        }
    }
    return QVector<int>(0);
}

QVector<int> GameEngine::getPair(Hand hand, Combination lastPlay) const {
    for (int i = lastPlay.getLastCard()->getNumber(); ; i++) {
        if (i == 14) {
            i = 1;
        }
        if (hand.numNum(i) >= 2) {
            QVector<BaseCard*> targets;
            for (int j = 0; j < hand.getCards().size() ; j++) {
                BaseCard* card = hand.getCards()[j];
                if (card->getNumber() == i) {
                    targets.append(card);
                }
            }
        }


        if (i == 2) {
            break;
        }
    }
}

Combination* GameEngine::getAIMove(Hand hand, Combination lastPlay) const {
    Combination::Type currentCom = lastPlay.getType();
    BaseCard* lastCard = lastPlay.getLastCard();
    BaseCard::Type lastType = lastCard->getType(); //UNO or playingcard
    int lastNum = lastCard->getNumber();
    QVector<BaseCard*> cardInHand = hand.getCards();
    if (currentCom == Combination::Type::SINGLE) {
        return Combination::createCombination(getSingle(hand, lastCard));
    }
    else if (currentCom == Combination::Type::PAIR) {
        return Combination::createCombination(getPair(hand, lastPlay));
    }
    else if (currentCom == Combination::Type::TRIPLE) {

    }
    else {

    }
    return Combination::createCombination(QVector<int>(0));
}

void GameEngine::recieveData(Worker* sender, const QJsonObject& data) {
    assert(sender->getName() == currentPlayer->toString());
    if (data["type"].toString() == "newPlay") {
        lastPlays[currentPlayer->toString()] = data["play"];
        QJsonArray play = data["play"].toArray();
        QVector<BaseCard*> cards;
        for (int i = 0; i < play.size(); i++) {
            if (play[i].toInt() < 99) {
                cards.append(new PlayingCard(play[i].toInt()));
            } else {
                cards.append(new UNOCard(play[i].toInt()));
            }
            if (cards[i]->getEffect() == BaseCard::Effect::REVERSE) {
                turnDirection *= -1;
            } else if (cards[i]->getEffect() == BaseCard::Effect::SKIP) {
                advanceNextPlayer();
            } else if (cards[i]->getEffect() == BaseCard::Effect::DRAWTWO) {
                playerDraw(nextPlayer->toString());
                playerDraw(nextPlayer->toString());
                advanceNextPlayer();
            }
        }
        Hand playerhand(playerHands[currentPlayer->toString()].toArray());
        for (int i = 0; i < cards.size(); i++) {
            playerhand.removeCard(cards[i]->getID());
        }
        playerHands[currentPlayer->toString()] = playerhand.toJsonArray();
        if (play.size() > 0) {
            lastPlayer = currentPlayer;
        }
        if (nextPlayer == lastPlayer) {
            for (int i = 0; i < playerNames.size(); i++) {
                if (!(currentPlayer == nextPlayer && playerNames[i].toString() == currentPlayer->toString())) {
                    QJsonArray empty;
                    lastPlays[playerNames[i].toString()] = empty;
                }
            }
        }
        currentPlayer = nextPlayer;
        advanceNextPlayer();
        updateAll();
    }
}

void GameEngine::advanceNextPlayer() {
    if (turnDirection == 1) {
        nextPlayer = nextPlayer+1 == playerNames.end() ? playerNames.begin() : nextPlayer+1;
    } else if (turnDirection == -1) {
        nextPlayer = nextPlayer == playerNames.begin() ? playerNames.end()-1 : nextPlayer-1;
    }
}

void GameEngine::playerDraw(QString player) {
    QJsonArray tempHand = playerHands[player].toArray();
    tempHand.append(deck.takeLast()->getID());
    playerHands[player] = tempHand;
}

void GameEngine::updateAll() {
    for (int i = 0; i < playerNames.size(); i++) {
        QJsonObject data;
        data["type"] = "gameInfo";
        data["players"] = playerNames;
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
        data["lastPlays"] = lastPlays;
        data["currPlayer"] = *currentPlayer;
        data["lastPlayer"] = *lastPlayer;
        data["turnDir"] = turnDirection;
        server->sendDataTo(playerNames[i].toString(),data);
    }
}
