#include "mainwindow.h"
#include "entrance.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Entrance e;
    e.show();
    return a.exec();
}
