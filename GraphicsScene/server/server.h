#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

#include "worker.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);

    quint16 getPort() const;
    QString getIP() const;
    void setNumPlayers(int);
    void setNumAI(int);
    int getNumPlayers() const;
    int getNumAI() const;
signals:
    void recievedData(Worker* client, const QJsonObject& data);


private slots:
    void clientDisconnected(Worker* client);
    void readData(Worker* client, const QJsonObject& data);

protected:
    void incomingConnection(qintptr handle) override;

private:
    quint16 port;
    QString ip;
    int numPlayers;
    int numAI;
    QVector<Worker*> clients;
    QVector<QString> playerNames;

    void broadcast(const QJsonObject& data, Worker* exclude = nullptr);
};

#endif // SERVER_H
