#ifndef WORKER_H
#define WORKER_H

#include <QTcpSocket>

/*
 * Worker is a helper class that Server creates to
 * handle each connection with a client. It emits
 * a signal that the server can respond to when
 * new data is read.
 */

class Worker : public QObject
{
    Q_OBJECT

public:
    Worker(QObject* parent);
    bool setSocketDescriptor(qintptr ptr);
    void sendData(const QJsonObject&);
    void setName(const QString& name);
    QString getName();

signals:
    void dataRecieved(const QJsonObject&);
    void clientDisconnected();

private slots:
    void readData();
    void disconnect();

private:
    QTcpSocket* socket;
    QString name;
};

#endif // WORKER_H
