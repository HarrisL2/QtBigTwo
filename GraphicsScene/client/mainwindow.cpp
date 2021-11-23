#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include "../ui/tablegraphics.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new TableGraphics)
{
    ui->setupUi(this);

    QGraphicsView* view = ui->centralwidget->findChild<QGraphicsView*>();
    view->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    scene->resizeEvent(event);
}
