#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QJsonArray>

#include "worker.h"

/*
 * Server is a QTcpServer with extra utility functions
 * to assist with the transfer of Json-based data files.
 * It keep tracks of individual clients using String-based
 * names.
 */

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);

    quint16 getPort() const;
    QString getIP() const;
    QJsonArray getPlayerNames() const;
    void sendDataTo(QString name, const QJsonObject& data);
    void broadcast(const QJsonObject& data, Worker* exclude = nullptr);

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

};

#endif // SERVER_H
