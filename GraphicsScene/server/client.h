#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT

public:
    Client(QObject* parent = nullptr);
    void sendData(const QJsonObject&);
    void setName(QString name);
    QString getName();


public slots:
    void connectToServer(const QHostAddress& adress, quint16 port);
signals:
    void dataRecieved(const QJsonObject&);

private slots:
    void readData();

private:
    QTcpSocket* socket;
    QString name;
};

#endif // CLIENT_H
