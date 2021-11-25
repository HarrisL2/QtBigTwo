#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QJsonObject>

#include "server.h"
#include "../client/basecard.h"
#include "../client/combination.h"

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
    QJsonArray::iterator currentPlayer;
    QJsonArray::iterator nextPlayer;
    int turnDirection;

    void updateAll();
};

#endif // GAMEENGINE_H
