#include "mainwindow.h"
#include "tester.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Tester t(w.facade);
    t.loadModel();

    return a.exec();
}
