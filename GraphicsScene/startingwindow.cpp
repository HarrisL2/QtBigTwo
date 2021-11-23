#include "startingwindow.h"
#include "ui_startingwindow.h"
#include "server/client.h"
#include "server/server.h"

#include <QHostAddress>
#include <QtDebug>

StartingWindow::StartingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartingWindow)
{
    ui->setupUi(this);
}

StartingWindow::~StartingWindow()
{
    delete ui;
}

void StartingWindow::on_CreateRoom_clicked() {
    if (!ui->PlayerNameBox->toPlainText().isEmpty()) {
        Server* server = new Server();

        Client* client = new Client();
        client->setName(ui->PlayerNameBox->toPlainText());
        client->connectToServer(QHostAddress(server->getIP()),server->getPort());
    } else {
        qDebug() << "hi";
    }
}

void StartingWindow::on_JoinRoom_clicked() {
    if (!(ui->PlayerNameBox->toPlainText().isEmpty() ||
          ui->IPBox->toPlainText().isEmpty() ||
          ui->PortBox->toPlainText().isEmpty())) {
        Client* client = new Client();
        client->setName(ui->PlayerNameBox->toPlainText());
        client->connectToServer(QHostAddress(ui->IPBox->toPlainText()),ui->PortBox->toPlainText().toInt());
    } else {
        qDebug() << "hey";
    }
}
