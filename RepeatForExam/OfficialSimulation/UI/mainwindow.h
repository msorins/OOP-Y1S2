#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include "../Controller/GradingController.h"
#include "customProxyTableModel.h"
#include <iostream>
#include <string>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    GradingController *controller;

public:
    explicit MainWindow(GradingController *controllerInput, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


//Variables + functionality
public:
    TableModel* tableModel;

    vector<CustomProxyTableModel *> secondaryTables;
    void createViewsForSecondaryTeachers();

public:
    void setTableView();
    void linkSlotsWithSignals();

public slots:
    void deleteStudent();
    void addStudent();


};

#endif // MAINWINDOW_H
