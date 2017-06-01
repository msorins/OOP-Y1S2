#include <iostream>
#include <QApplication>
#include "UI/mainwindow.h"
#include "Repository/Repository.h"

using namespace std;

int main(int argc, char *argv[]) {

    Repository repo("file.txt");


    QApplication a(argc, argv);
    MainWindow w(repo);
    w.show();
    a.exec();

    return 0;
}