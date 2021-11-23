#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT

public:
    Client(QObject* parent);
    void sendData(const QJsonObject&);

public slots:
    void connectToServer(const QHostAddress& adress, quint16 port);

signals:
    void dataRecieved(const QJsonObject&);

private slots:
    void readData();

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
