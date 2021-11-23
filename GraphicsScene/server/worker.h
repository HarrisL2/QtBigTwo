#ifndef WORKER_H
#define WORKER_H

#include <QTcpSocket>

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
