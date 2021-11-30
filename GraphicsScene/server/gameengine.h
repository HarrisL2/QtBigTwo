#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QJsonObject>

#include "server.h"
#include "../client/hand.h"
#include "../client/basecard.h"
#include "../client/combination.h"

/*
 * GameEngine is the class that handles the server-side
 * logic of a game of Big Two/TwUNO. It owns a server
 * object and uses it to communicate with clients. It
 * contains the data of player's hands and also has the
 * logic for an AI player.
 */

class GameEngine : public QObject
{
    Q_OBJECT

public:
    GameEngine(Server* ser, int AICount, int playerCount, bool UNOMode, QObject* parent);
    void updateClients();

public slots:
    void recieveData(Worker* sender, const QJsonObject& data);

private:
    Server* server;
    int AICount, playerCount;
    bool UNOMode;
    QJsonArray playerNames;
    QVector<BaseCard*> deck;
    QVector<Combination*> stack;
    QJsonObject playerHands;
    QJsonObject lastPlays;
    QJsonArray::iterator lastPlayer;
    QJsonArray::iterator currentPlayer;
    QJsonArray::iterator nextPlayer;
    int turnDirection;

    void advanceNextPlayer();
    void playerDraw(QString);
    void updateAll();
    void processMove(Combination*);
    void winGame(QString);
    Combination* getAIMove(Hand, Combination*) const;
};

#endif // GAMEENGINE_H
