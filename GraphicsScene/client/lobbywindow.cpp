#include "lobbywindow.h"
#include "ui_lobbywindow.h"
#include "clientlogic.h"
#include "mainwindow.h"
#include "../server/gameengine.h"

#include <QtDebug>
#include <QMessageBox>

/*
 *  LobbyWindow::LobbyWindow(Client* client,
                         QJsonArray playerNames,
                         QString playerName,
                         QWidget* parent,
                         Server* server)
 *  @funct:  creates a lobby window with the corresponding data
 *  @param:  client: client object
 *           playerNames: names of the players
 *           playerName: name of this player
 *           parent: N/A
 *           server: server object
 *  @return: N/A
 */

LobbyWindow::LobbyWindow(Client* client,
                         QJsonArray playerNames,
                         QString playerName,
                         QWidget* parent,
                         Server* server) :
    QMainWindow(parent),
    ui(new Ui::LobbyWindow),
    playerNames(playerNames),
    playerName(playerName),
    maxPlayerCount(1),
    maxAICount(3),
    server(server),
    client(client)
{
    ui->setupUi(this);
    if (server != nullptr) {
        isHost = true;
        ui->IPLabel->setText(server->getIP()+":"+QString::number(server->getPort()));
    } else {
        isHost = false;
        ui->verticalWidget_2->hide();
    }
    connect(client, &Client::dataRecieved, this, &LobbyWindow::clientRecieved);

    QString playerList;
    for (int i = 0; i < playerNames.size(); i++) {
        playerList.append(playerNames[i].toString()+"\n");
    }
    ui->PlayerListText->setText(playerList);
    ui->PlayerCount->setText(QString::number(maxPlayerCount));
    ui->AICount->setText(QString::number(maxAICount));

    QPixmap up {":/cards/png/up.png"};
    QPixmap down {":/cards/png/down.png"};
    ui->IncreaseAI->setIcon(up);
    ui->DecreaseAI->setIcon(down);
    ui->IncreasePlayers->setIcon(up);
    ui->DecreasePlayers->setIcon(down);
}

LobbyWindow::~LobbyWindow()
{
    delete ui;
}

/*
 *  LobbyWindow::clientRecieved(const QJsonObject& data)
 *  @funct: updates namelist or starts game depending on data recieved
 *  @param: data from client
 *  @return: N/A
 */

void LobbyWindow::clientRecieved(const QJsonObject& data) {
    if (data["type"] == "nameList") {
        playerNames = data["list"].toArray();
        QString playerList;
        for (int i = 0; i < playerNames.size(); i++) {
            playerList.append(playerNames[i].toString()+"\n");
        }
        ui->PlayerListText->setText(playerList);
    } else if (data["type"] == "startGame") {
        MainWindow* mainWindow = new MainWindow(client);
        disconnect(client, &Client::dataRecieved, this, &LobbyWindow::clientRecieved);
        mainWindow->show();
        if (isHost) {
            GameEngine* engine = new GameEngine(server, maxAICount, maxPlayerCount,
                                                ui->UNOMode->checkState(), mainWindow);
        }
        this->close();
    }
}

/*
 *  LobbyWindow::on_GameStartButton_clicked()
 *  @funct: starts game if conditions are valid
 *  @param: N/A
 *  @return: N/A
 */

void LobbyWindow::on_GameStartButton_clicked() {
    if (!isHost) {
        QMessageBox msg;
        msg.setText("Only the host can start the game.");
        msg.exec();
    } else if (maxAICount + maxPlayerCount > 4) {
        QMessageBox msg;
        msg.setText("Cannot start game with more than 4 AIs and Players combined.");
        msg.exec();
    } else if (maxAICount + maxPlayerCount < 2) {
        QMessageBox msg;
        msg.setText("Cannot start game with less than 2 AIs and Players combined.");
        msg.exec();
    } else if (playerNames.size() > maxPlayerCount) {
        QMessageBox msg;
        msg.setText("Number of players present in Lobby is more than set.");
        msg.exec();
    } else if (playerNames.size() < maxPlayerCount) {
        QMessageBox msg;
        msg.setText("Number of players present in Lobby is less than set.");
        msg.exec();
    } else {
        QJsonObject data;
        data["type"] = "startGame";
        server->broadcast(data);
    }
}

/*
 *  LobbyWindow::on_<button>_clicked()
 *  @funct: performs the corresponding functions
 *  @param: N/A
 *  @return: N/A
 */

void LobbyWindow::on_IncreasePlayers_clicked() {
    if (maxPlayerCount < 4) {
        maxPlayerCount++;
        ui->PlayerCount->setText(QString::number(maxPlayerCount));
    }
}
void LobbyWindow::on_DecreasePlayers_clicked() {
    if (maxPlayerCount > 0) {
        maxPlayerCount--;
        ui->PlayerCount->setText(QString::number(maxPlayerCount));
    }
}
void LobbyWindow::on_IncreaseAI_clicked() {
    if (maxAICount < 4) {
        maxAICount++;
        ui->AICount->setText(QString::number(maxAICount));
    }
}
void LobbyWindow::on_DecreaseAI_clicked() {
    if (maxAICount > 0) {
        maxAICount--;
        ui->AICount->setText(QString::number(maxAICount));
    }
}
