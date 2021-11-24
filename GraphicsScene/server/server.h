#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QJsonArray>

#include "worker.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);

    quint16 getPort() const;
    QString getIP() const;
    QJsonArray getPlayerNames() const;

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
    QVector<Worker*> clients;
    QJsonArray playerNames;

    void broadcast(const QJsonObject& data, Worker* exclude = nullptr);
};

#endif // SERVER_H
