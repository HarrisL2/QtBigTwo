#ifndef STARTINGWINDOW_H
#define STARTINGWINDOW_H

#include <QWidget>
#include <QGraphicsScene>

#include "server/client.h"
#include "server/server.h"

namespace Ui {
class StartingWindow;
}

class StartingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartingWindow(QWidget *parent = nullptr);
    ~StartingWindow();

private slots:
    void on_CreateRoom_clicked();
    void on_JoinRoom_clicked();
    void on_CreditsButton_clicked();
    void on_RulesButton_clicked();
    void on_BackButton_clicked();

    void clientRecieved(const QJsonObject&);
    void clientConnectionFailed();

private:
    Ui::StartingWindow *ui;
    Client* client;
    Server* server;
};

#endif // STARTINGWINDOW_H
