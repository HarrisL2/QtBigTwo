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
    GameEngine(Server* ser);
    void updateClients();

public slots:
    void recieveData(Worker* sender, const QJsonObject& data);

private:
    Server* server;
    QVector<Combination*> stack;
    QString currentPlayer;
    QJsonObject playerHands;
    QJsonObject lastPlays;
};

#endif // GAMEENGINE_H
