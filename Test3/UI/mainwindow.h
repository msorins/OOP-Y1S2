#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listmodel.h"
#include "../Repository/Repository.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Repository& repo;

public:
    explicit MainWindow(Repository& repos, QWidget *parent = 0);
    ~MainWindow();
    void linkListView();

public:
    ListModel *listModel;
private:
    Ui::MainWindow *ui;

public:
    void linkSignalAndSlots();

public slots:
    void sortBySum();
    void calculateUnpaidBillsForCompany();


};

#endif // MAINWINDOW_H
