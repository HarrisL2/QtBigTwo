#ifndef CLIENTLOGIC_H
#define CLIENTLOGIC_H

#include "../server/client.h"
#include "combination.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>


class ClientLogic : public QObject
{

    Q_OBJECT

public:
    ClientLogic(Client* client);

    QString getName() const;
    QJsonObject getHands() const;
    bool waitingForPlay() const;
    void processPlay(QVector<int>);
    QJsonArray getNames() const;
    QJsonObject getLastPlays() const;
    QString getCurrPlayer() const;

signals:
    void dataChanged();

private slots:
    void recieveData(const QJsonObject&);

private:
    Client* client;
    QString name;
    int turnDir;
    QVector<Combination*> stack;
    QJsonArray playerNames;
    QJsonObject playerHands;
    QJsonObject lastPlays;
    QString lastPlayer;
    QString currentPlayer;

    void sendPlay(Combination*);
};

#endif // CLIENTLOGIC_H
