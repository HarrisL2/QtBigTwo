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
    QJsonArray names = logic->getNames();
    QString thisName = logic->getName();
    QJsonObject::iterator it = hands.find(thisName);
    QJsonArray::iterator it2 = names.begin();
    while (it2->toString() != thisName) {it2++;}

    scene->changeHand(0,it->toArray());
    if (hands.size() == 2) {
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(2, it->toArray());

        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(2, it2->toString());
    } else if (hands.size() == 3) {
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(1, it->toArray());
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(3, it->toArray());

        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(1, it2->toString());
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(3, it2->toString());
    } else {
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(1, it->toArray());
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(2, it->toArray());
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(3, it->toArray());

        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(1, it2->toString());
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(2, it2->toString());
        if (++it2 == names.end()) it2 = names.begin();
        scene->setName(3, it2->toString());
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
