#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

#include "../ui/tablegraphics.h"

MainWindow::MainWindow(Client* client, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new TableGraphics),
    logic(new ClientLogic(client))
{
    ui->setupUi(this);

    QGraphicsView* view = ui->centralwidget->findChild<QGraphicsView*>();
    view->setScene(scene);

    connect(logic, &ClientLogic::dataChanged, this, &MainWindow::updateScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateScene() {
    QJsonObject hands = logic->getHands();
    QJsonObject lastPlays = logic->getLastPlays();
    QJsonArray names = logic->getNames();
    QString thisName = logic->getName();
    QString currPlayer = logic->getCurrPlayer();
    QJsonArray::iterator it2 = names.begin();
    while (it2->toString() != thisName) {it2++;}

    if (currPlayer == it2->toString()) scene->setCurrent(0);
    scene->changeHand(0, hands[it2->toString()].toArray());
    scene->setLastPlay(0, lastPlays[it2->toString()].toArray());
    if (hands.size() == 2) {
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(2, it2->toString());
        scene->changeHand(2, hands[it2->toString()].toArray());
        scene->setLastPlay(2, lastPlays[it2->toString()].toArray());
        if (currPlayer == it2->toString()) scene->setCurrent(2);
    } else if (hands.size() == 3) {
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(1, it2->toString());
        scene->changeHand(1, hands[it2->toString()].toArray());
        scene->setLastPlay(1, lastPlays[it2->toString()].toArray());
        if (currPlayer == it2->toString()) scene->setCurrent(1);
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(3, it2->toString());
        scene->changeHand(3, hands[it2->toString()].toArray());
        scene->setLastPlay(3, lastPlays[it2->toString()].toArray());
        if (currPlayer == it2->toString()) scene->setCurrent(3);
    } else {
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(1, it2->toString());
        scene->changeHand(1, hands[it2->toString()].toArray());
        scene->setLastPlay(1, lastPlays[it2->toString()].toArray());
        if (currPlayer == it2->toString()) scene->setCurrent(1);
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(2, it2->toString());
        scene->changeHand(2, hands[it2->toString()].toArray());
        scene->setLastPlay(2, lastPlays[it2->toString()].toArray());
        if (currPlayer == it2->toString()) scene->setCurrent(2);
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(3, it2->toString());
        scene->changeHand(3, hands[it2->toString()].toArray());
        scene->setLastPlay(3, lastPlays[it2->toString()].toArray());
        if (currPlayer == it2->toString()) scene->setCurrent(3);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        logic->processPlay(scene->getNextPlay());
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    scene->resizeEvent(event);
}
