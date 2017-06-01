#include <iostream>
#include <QApplication>
#include "UI/mainwindow.h"
#include "Repository/Repository.h"

int main(int argc, char *argv[]) {

    Repository repo;

    QApplication a(argc, argv);
    MainWindow w{repo};
    w.show();

    a.exec();

    return 0;
}