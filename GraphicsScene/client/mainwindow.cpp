#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "combination.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>

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
    QString thisName = logic->getName();
    QJsonObject::iterator it = hands.find(thisName);

    scene->changeHand(0,it->toArray());
    if (hands.size() == 2) {
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(2, it->toArray());
    } else if (hands.size() == 3) {
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(1, it->toArray());
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(3, it->toArray());
    } else {
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(1, it->toArray());
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(2, it->toArray());
        if (++it == hands.end()) it = hands.begin();
        scene->changeHand(3, it->toArray());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        QVector<int> selected = scene->getNextPlay();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    scene->resizeEvent(event);
}
