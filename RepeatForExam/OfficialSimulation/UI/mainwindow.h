#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include "../Controller/GradingController.h"
#include "customProxyTableModel.h"
#include <iostream>
#include <string>
#include <QTableView>

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
    CustomProxyTableModel* proxyTableModel;

    vector<CustomProxyTableModel *> secondaryProxyTablesModels;
    vector<QTableView *> secondaryTablesModels;
    vector<Teacher> teachers;
    void createViewsForSecondaryTeachers();
    void updateViewsForSecondaryTeachers();

public:
    void setTableView();
    void linkSlotWithSignalsOnce();
    void linkSlotsWithSignals();

public slots:
    void deleteStudent();
    void addStudent();
    void updateDataEverywhere(const QModelIndex& A, const QModelIndex& B);
    void updateDataEverywhereNoParam();

};

#endif // MAINWINDOW_H
