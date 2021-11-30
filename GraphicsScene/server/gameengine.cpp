#include <QRandomGenerator>
#include <QtDebug>
#include <QThread>

#include "gameengine.h"
#include "../client/playingcard.h"
#include "../client/unocard.h"


/*
 *  GameEngine::GameEngine(Server* ser, int AICount, int playerCount, bool UNOMode, QObject* parent)
 *  @funct: create game engine and initialize the game state
 *  @param: ser: server object
 *  @return: N/A
 */

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
    /*for (int i = 0; i < int(playerNames.size()*QRandomGenerator::global()->generateDouble()); i++) {
        currentPlayer++;
    }*/
    lastPlayer = currentPlayer;
    nextPlayer = currentPlayer+1 == playerNames.end() ? playerNames.begin() : currentPlayer+1;
    turnDirection = 1;
    connect(server, &Server::recievedData, this, &GameEngine::recieveData);
    if (currentPlayer->toString().left(2) == "AI") {
        Hand AIHand(playerHands[currentPlayer->toString()].toArray());
        Combination* lastPlay = nullptr;
        if (currentPlayer != lastPlayer) {
            lastPlay = Combination::createCombination(lastPlays[lastPlayer->toString()].toArray());
        }
        processMove(getAIMove(AIHand,lastPlay));
    }
    updateAll();
}

/*
 *  GameEngine::getAIMove(Hand hand, Combination* lastPlay)
 *  @funct: get a valid play given a hand and the last play
 *  @param: hand, last play
 *  @return: N/A
 */

Combination* GameEngine::getAIMove(Hand hand, Combination* lastPlay) const {
    QVector<BaseCard*> cards = hand.getCards();
    if (lastPlay == nullptr) {
        QVector<BaseCard*> toPlay;
        toPlay.append(cards[0]);
        return Combination::createCombination(toPlay);
    }
    QVector<BaseCard*> toPlay;
    switch (lastPlay->getType()) {
    case Combination::Type::SINGLE: {
        for (int i = 0 ; i < cards.size(); i++) {
            if (*cards[i] > *lastPlay->getFirstCard()) {
                if (lastPlay->getFirstCard()->getType() == BaseCard::Type::UNO && cards[i]->getType() == BaseCard::Type::UNO && lastPlay->getFirstCard()->getColor() != cards[i]->getColor()) {
                    continue;
                } else {
                    toPlay.append(cards[i]);
                    return Combination::createCombination(toPlay);
                }
            }
        }
        break;
    }
    case Combination::Type::PAIR: {
        for (int i = lastPlay->getFirstCard()->getNumber(); ; i++) {
            if (i == 14) i = 1;
            if (hand.numNum(i) >= 2) {
                QVector<BaseCard*> nums = hand.getAllNum(i);
                for (int j = 0; j < nums.size(); j++) {
                    for (int k = j+1; k < nums.size(); k++) {
                        toPlay.append(nums[j]);
                        toPlay.append(nums[k]);
                        Combination* testComb = Combination::createCombination(toPlay);
                        if (*testComb > *lastPlay) {
                            return testComb;
                        } else {
                            toPlay.clear();
                            delete testComb;
                        }
                    }
                }
            }
            if (i == 2) break;
        }
        break;
    }
    case Combination::Type::TRIPLE: {
        for (int i = lastPlay->getFirstCard()->getNumber(); ; i++) {
            if (i == 14) i = 1;
            if (hand.numNum(i) >= 2) {
                QVector<BaseCard*> nums = hand.getAllNum(i);
                for (int j = 0; j < nums.size(); j++) {
                    for (int k = j+1; k < nums.size(); k++) {
                        for (int l = k+1; l < nums.size(); l++) {
                            toPlay.append(nums[j]);
                            toPlay.append(nums[k]);
                            toPlay.append(nums[l]);
                            Combination* testComb = Combination::createCombination(toPlay);
                            if (*testComb > *lastPlay) {
                                return testComb;
                            } else {
                                toPlay.clear();
                                delete testComb;
                            }
                        }
                    }
                }
            }
            if (i == 2) break;
        }
        break;
    }
    case Combination::Type::STRAIGHT: {
        for (int i = lastPlay->getSorted().at(0)->getNumber(); ;i++) {
            if (i == 14) i = 1;
            bool hasAll = true;
            for (int j = i; ; j--) {
                if (j == 0) j = 13;
                if (hand.numNum(j) == 0) hasAll = false;
                if (j == lastPlay->getSorted().at(4)->getNumber()) break;
            }
            if (hasAll) {
                for (int j = i; ; j--) {
                    if (j == 0) j = 13;
                    toPlay.append(hand.getAllNum(j).at(0));
                    if (j == lastPlay->getSorted().at(4)->getNumber()) break;
                }
                return Combination::createCombination(toPlay);
            }
            if (i == 2) break;
        }
        break;
    }
    case Combination::Type::FLUSH: {
        for (int i = 1; i <= 4; i++) {
            int suitCount = hand.numSuit(static_cast<BaseCard::Suit>(i));
            if (suitCount >= 5) {
                QVector<BaseCard*> temp = hand.getAllSuit(static_cast<BaseCard::Suit>(i));
                if (*temp[suitCount-1] > *lastPlay->getSorted().at(0)) {
                    for (int j = suitCount-1; j >= suitCount-5; j--) {
                        toPlay.append(temp[j]);
                        return Combination::createCombination(toPlay);
                    }
                }
            }
        }
        for (int i = 1; i <= 4; i++) {
            int colorCount = hand.numColor(static_cast<BaseCard::Color>(i));
            if (colorCount >= 5) {
                QVector<BaseCard*> temp = hand.getAllColor(static_cast<BaseCard::Color>(i));
                if (*temp[colorCount-1] > *lastPlay->getSorted().at(0)) {
                    for (int j = colorCount-1; j >= colorCount-5; j--) {
                        toPlay.append(temp[j]);
                        return Combination::createCombination(toPlay);
                    }
                }
            }
        }
        break;
    }
    case Combination::Type::FULL_HOUSE: {
        BaseCard* lastMajor = (lastPlay->getSorted().at(1)->getNumber() == lastPlay->getSorted().at(2)->getNumber() ? lastPlay->getSorted().at(0) : lastPlay->getSorted().at(2));
        for (int i = lastMajor->getNumber(); ;i++) {
            if (i == 14) i = 1;
            if (hand.numNum(i) >= 3) {
                for (int j = 3; ; j++) {
                    if (j == 14) j = 1;
                    if (i != j && hand.numNum(j) >= 2) {
                        QVector<BaseCard*> majors = hand.getAllNum(i);
                        QVector<BaseCard*> minors = hand.getAllNum(j);
                        for (int x = 0; x < 3; x++) toPlay.append(majors[x]);
                        for (int x = 0; x < 2; x++) toPlay.append(minors[x]);
                        return Combination::createCombination(toPlay);
                    }
                    if (j == 2) break;
                }
            }
            if (i == 2) break;
        }
        break;
    }
    case Combination::Type::FOUR_OF_A_KIND: {
        BaseCard* lastMajor = (lastPlay->getSorted().at(0)->getNumber() == lastPlay->getSorted().at(1)->getNumber() ? lastPlay->getSorted().at(0) : lastPlay->getSorted().at(4));
        for (int i = lastMajor->getNumber(); ;i++) {
            if (i == 14) i = 1;
            if (hand.numNum(i) >= 4) {
                for (int j = 0; j < hand.numCards(); j++) {
                    QVector<BaseCard*> majors = hand.getAllNum(i);
                    if (cards[j]->getNumber() != i) {
                        for (int x = 0; x < 4; x++) toPlay.append(majors[x]);
                        toPlay.append(cards[j]);
                        return Combination::createCombination(toPlay);
                    }
                }
            }
            if (i == 2) break;
        }
        break;
    }
    default:
        break;
    }
    return Combination::createCombination(QVector<int>(0));
}

/*
 *  GameEngine::recieveData(Worker* sender, const QJsonObject& data)
 *  @funct: recieve and process data from client
 *  @param: client, data
 *  @return: N/A
 */

void GameEngine::recieveData(Worker* sender, const QJsonObject& data) {
    assert(sender->getName() == currentPlayer->toString());
    qDebug() << data;
    if (data["type"].toString() == "newPlay") {
        QJsonArray play = data["play"].toArray();
        QVector<BaseCard*> cards;
        for (int i = 0; i < play.size(); i++) {
            if (play[i].toInt() < 99) {
                cards.append(new PlayingCard(play[i].toInt()));
            } else {
                cards.append(new UNOCard(play[i].toInt()));
            }
        }
        processMove(Combination::createCombination(cards));
    }
    updateAll();
}

/*
 *  GameEngine::processMove(Combination* move)
 *  @funct: process the given move and execute special function cards
 *  @param: move
 *  @return: N/A
 */

void GameEngine::processMove(Combination* move) {
    if (move->getType() == Combination::Type::PASS) {
        QJsonArray empty;
        lastPlays[currentPlayer->toString()] = empty;
    }
    lastPlays[currentPlayer->toString()] = move->toJsonArray();
    QVector<BaseCard*> cards = move->getSorted();
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getEffect() == BaseCard::Effect::REVERSE) {
            turnDirection *= -1;
            advanceNextPlayer();
            advanceNextPlayer();
        } else if (cards[i]->getEffect() == BaseCard::Effect::SKIP) {
            QJsonArray empty;
            lastPlays[nextPlayer->toString()] = empty;
            advanceNextPlayer();
        } else if (cards[i]->getEffect() == BaseCard::Effect::DRAWTWO) {
            playerDraw(nextPlayer->toString());
            playerDraw(nextPlayer->toString());
            QJsonArray empty;
            lastPlays[nextPlayer->toString()] = empty;
            advanceNextPlayer();
        }
    }
    Hand playerhand(playerHands[currentPlayer->toString()].toArray());
    for (int i = 0; i < cards.size(); i++) {
        playerhand.removeCard(cards[i]->getID());
    }
    playerHands[currentPlayer->toString()] = playerhand.toJsonArray();
    if (cards.size() > 0) {
        lastPlayer = currentPlayer;
    }
    if (playerhand.numCards() == 0) {
        winGame(currentPlayer->toString());
        return;
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
    if (currentPlayer->toString().left(2) == "AI") {
        Hand AIHand(playerHands[currentPlayer->toString()].toArray());
        Combination* lastPlay = nullptr;
        if (currentPlayer != lastPlayer) {
            lastPlay = Combination::createCombination(lastPlays[lastPlayer->toString()].toArray());
        }
        processMove(getAIMove(AIHand,lastPlay));
    } else {
        updateAll();
    }
}

/*
 *  GameEngine::advanceNextPlayer()
 *  @funct: advance the next player based on the turn direction
 *  @param: N/A
 *  @return: N/A
 */

void GameEngine::advanceNextPlayer() {
    if (turnDirection == 1) {
        nextPlayer = nextPlayer+1 == playerNames.end() ? playerNames.begin() : nextPlayer+1;
    } else if (turnDirection == -1) {
        nextPlayer = nextPlayer == playerNames.begin() ? playerNames.end()-1 : nextPlayer-1;
    }
}

/*
 *  GameEngine::playerDraw(QString player)
 *  @funct: add a card to player's hand from deck
 *  @param: player
 *  @return: N/A
 */

void GameEngine::playerDraw(QString player) {
    QJsonArray tempHand = playerHands[player].toArray();
    tempHand.append(deck.takeLast()->getID());
    playerHands[player] = tempHand;
}

void GameEngine::winGame(QString player) {
    QJsonObject data;
    data["type"] = "win";
    data["winner"] = player;
    server->broadcast(data);
}

/*
 *  GameEngine::updateAll()
 *  @funct: update all players with corresponding information
 *  @param: N/A
 *  @return: N/A
 */

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
