#include <iostream>
#include <QApplication>
#include "UI/mainwindow.h"
#include "Repository/StudentsRepository.h"
#include "Controller/GradingController.h"

int main(int argc, char* argv[]) {
    StudentsRepository studentRepo;
    TeachersRepository teacherRepo;
    GradingController controller(&studentRepo, &teacherRepo);


    QApplication a(argc, argv);
    MainWindow w{&controller};
    w.show();
    a.exec();

}