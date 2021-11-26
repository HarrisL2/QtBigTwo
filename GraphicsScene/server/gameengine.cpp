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
}

QVector<int> GameEngine::getSingle(Hand hand, BaseCard* lastCard, BaseCard::Type lastType, int lastNum, QVector<BaseCard*> cardInHand) const {
//    int j = lastNum, boundary;
//    if (lastNum > 2) {
//        boundary = 13;
//    } else {
//        boundary = 2;
//    }
//    for (; j <= boundary; ++j) { //check from small num
//        if (hand.numNum(j) > 0) { //have that num
//            for (int i = 0; i < cardInHand.size(); ++i) {
//                if (cardInHand[i]->getNumber() == j) { //find that num in hand
//                    BaseCard* card = cardInHand[i];
//                    if (lastType != card->getType()) {
//                        QVector<int> temp;
//                        temp.append(card->getID());
//                        return temp;
//                    } else if (card->getType() == BaseCard::Type::UNO && card->getColor() == lastCard->getColor()) {
//                        QVector<int> temp;
//                        temp.append(card->getID());
//                        return temp;
//                    } else if (card->getType() == BaseCard::Type::PLAYING) {
//                        QVector<int> temp;
//                        temp.append(card->getID());
//                        return temp;
//                    }
//                }
//            }
//        }
//    }
//    if (boundary == 13) {
//        return getSingle(hand, lastCard, lastType, 1, cardInHand);
//    }
//    return QVector<int>(0);
    bool notUNO = false;
    BaseCard* cardToPlay = nullptr;
    QVector<BaseCard*> cards = hand.getCards();
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getType() == BaseCard::Type::PLAYING &&
                cards[i]->getID() > (lastCard->getType() == BaseCard::Type::UNO ? lastCard->getID()-100 : lastCard->getID())) {
            if (cardToPlay == nullptr || cards[i]->getID() < cardToPlay->getID()) {
                cardToPlay = cards[i];
                notUNO = true;
            }
        } else {

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
        return Combination::createCombination(getSingle(hand, lastCard, lastType, lastNum, cardInHand));
    }
    else if (currentCom == Combination::Type::PAIR) {

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
            }
        }
        if (play.size() > 0) {
            lastPlayer = currentPlayer;
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
