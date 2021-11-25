#include "client/mainwindow.h"
#include "startingwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartingWindow s;
    s.show();
    return a.exec();
}
