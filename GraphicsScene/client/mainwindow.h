#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../ui/tablegraphics.h"
#include "clientlogic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*
 * MainWindow is the main interface for a game of Big
 * TwUNO. It owns the ClientLogic and GraphicScene and
 * acts as a coordinator between them.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Client* client, QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);

private slots:
    void updateScene();
    void endGame(QString);

private:
    Ui::MainWindow *ui;
    TableGraphics* scene;
    ClientLogic* logic;

    void resizeEvent(QResizeEvent*);
};
#endif // MAINWINDOW_H
