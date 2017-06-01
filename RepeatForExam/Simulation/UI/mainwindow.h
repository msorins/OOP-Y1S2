#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Repository/Repository.h"
#include "ui_list.h"
#include "CustomProxyModel.h"
#include <QSortFilterProxyModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Repository &repo, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    Repository &repo;
    UI_List *uiListModel;
    CustomProxyModel* proxyModel;

    //Functionality
    void populateWeatherListView();
    void linkStuff();

public slots:
    void computeHours();
    void sortAsc();
    void removeSorting();
    void precipitationFilter();
    void removePrecipitationFilter();
};

#endif // MAINWINDOW_H
