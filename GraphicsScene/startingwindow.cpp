#include "startingwindow.h"
#include "ui_startingwindow.h"

#include "client/lobbywindow.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QHostAddress>
#include <QMessageBox>
#include <QtDebug>

StartingWindow::StartingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartingWindow),
    client(nullptr),
    server(nullptr)
{
    ui->setupUi(this);
    QPixmap temp = ui->Title->pixmap();
    ui->Title->setPixmap(temp.scaled(temp.width() * 0.25,temp.height() * 0.25));
}

StartingWindow::~StartingWindow()
{
    delete ui;
}

void StartingWindow::on_CreateRoom_clicked() {
    if (!ui->PlayerNameBox->toPlainText().isEmpty()) {
        server = new Server();

        client = new Client();
        client->setName(ui->PlayerNameBox->toPlainText());
        connect(client, &Client::dataRecieved, this, &StartingWindow::clientRecieved);
        client->connectToServer(QHostAddress(server->getIP()),server->getPort());
    } else {
        QMessageBox msg;
        msg.setText("Please enter a name before creating a Lobby");
        msg.exec();
    }
}

void StartingWindow::on_JoinRoom_clicked() {
    if (ui->PlayerNameBox->toPlainText().isEmpty()) {
        QMessageBox msg;
        msg.setText("Please enter a name before joining a Lobby");
        msg.exec();
    } else if (ui->IPBox->toPlainText().isEmpty()) {
        QMessageBox msg;
        msg.setText("Please enter an IP adress before joining a Lobby");
        msg.exec();
    } else if (ui->PortBox->toPlainText().isEmpty()) {
        QMessageBox msg;
        msg.setText("Please enter a Port before joining a Lobby");
        msg.exec();
    } else {
        client = new Client();
        connect(client, &Client::dataRecieved, this, &StartingWindow::clientRecieved);
        connect(client, &Client::connectionFailed, this, &StartingWindow::clientConnectionFailed);
        client->setName(ui->PlayerNameBox->toPlainText());
        client->connectToServer(QHostAddress(ui->IPBox->toPlainText()),ui->PortBox->toPlainText().toInt());

    }
}

void StartingWindow::on_CreditsButton_clicked() {

}

void StartingWindow::clientRecieved(const QJsonObject& data) {
    if (data["type"] == "nameList") {
        LobbyWindow* lobby = new LobbyWindow(client, data["list"].toArray(), ui->PlayerNameBox->toPlainText(), nullptr, server);
        lobby->show();
        disconnect(client, &Client::dataRecieved, this, &StartingWindow::clientRecieved);
        disconnect(client, &Client::connectionFailed, this, &StartingWindow::clientConnectionFailed);
        this->close();
    } else if (data["type"] == "repeatedName") {
        QMessageBox msg;
        msg.setText("The name you are trying to use has already been taken, please use another name.");
        msg.exec();
        client->disconnect();
        client->deleteLater();
    }
}

void StartingWindow::clientConnectionFailed() {
    QMessageBox msg;
    msg.setText("You have entered an invalid adress/port, please check and try again.");
    msg.exec();
    client->deleteLater();
}
