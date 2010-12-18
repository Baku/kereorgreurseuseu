#include <QtGui/QApplication>
#include <iostream>
#include "rssParse.h"
#include "mywindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow    w;

    w.run();

    return a.exec();
}
