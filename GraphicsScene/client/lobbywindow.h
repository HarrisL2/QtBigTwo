#ifndef LOBBYWINDOW_H
#define LOBBYWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonArray>
#include "../server/client.h"
#include "../server/server.h"

/*
 * The LobbyWindow is the interface for the players when
 * a room is created but a game has not been started.
 * They will set the amount of AI players and the mode
 * of the game in this screen.
 */

namespace Ui {
class LobbyWindow;
}

class LobbyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LobbyWindow(Client* client,
                         QJsonArray playerNames,
                         QString playerName,
                         QWidget* parent = nullptr,
                         Server* server = nullptr);
    ~LobbyWindow();

private slots:
    void clientRecieved(const QJsonObject&);
    void on_GameStartButton_clicked();
    void on_IncreasePlayers_clicked();
    void on_DecreasePlayers_clicked();
    void on_IncreaseAI_clicked();
    void on_DecreaseAI_clicked();

private:
    bool isHost;
    Ui::LobbyWindow *ui;
    QJsonArray playerNames;
    QString playerName;
    int maxPlayerCount;
    int maxAICount;
    Server* server;
    Client* client;
};

#endif // LOBBYWINDOW_H
