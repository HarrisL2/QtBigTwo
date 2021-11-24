#include "lobbywindow.h"
#include "ui_lobbywindow.h"

#include <QtDebug>

LobbyWindow::LobbyWindow(Client* client,
                         QJsonArray playerNames,
                         QString playerName,
                         QWidget* parent,
                         Server* server) :
    QMainWindow(parent),
    ui(new Ui::LobbyWindow),
    playerNames(playerNames),
    playerName(playerName),
    maxPlayerCount(4),
    maxAICount(0),
    server(server),
    client(client)
{
    ui->setupUi(this);
    if (server != nullptr) {
        isHost = true;
        ui->IPLabel->setText(server->getIP()+":"+QString::number(server->getPort()));
    }
    connect(client, &Client::dataRecieved, this, &LobbyWindow::clientRecieved);

    QString playerList;
    for (int i = 0; i < playerNames.size(); i++) {
        playerList.append(playerNames[i].toString()+"\n");
    }
    ui->PlayerListText->setText(playerList);
    ui->PlayerCount->setText("4");
    ui->AICount->setText("0");
}

LobbyWindow::~LobbyWindow()
{
    delete ui;
}

void LobbyWindow::clientRecieved(const QJsonObject& data) {
    if (data["type"] == "nameList") {
        playerNames = data["list"].toArray();
        QString playerList;
        for (int i = 0; i < playerNames.size(); i++) {
            playerList.append(playerNames[i].toString()+"\n");
        }
        ui->PlayerListText->setText(playerList);
    }
}

void LobbyWindow::on_GameStartButton_clicked() {

}
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
