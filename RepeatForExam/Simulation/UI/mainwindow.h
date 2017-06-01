#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Repository/Repository.h"
#include "UI_ListModel.h"
#include "CustomProxyModel.h"
#include "UI_TableModel.h"
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
    UI_ListModel *uiListModel;
    UI_TableModel *uiTableModel;
    CustomProxyModel* customProxyListModel;
    CustomProxyModel* customProxyMapModel, *customProxyMapModel2;

    //Functionality
    void populateWeatherListView();
    void createAndPopulateWeatherTableView();
    void linkStuff();

public slots:
    void computeHours();
    void sortAsc();
    void removeSorting();
    void precipitationFilter();
    void removePrecipitationFilter();
};

#endif // MAINWINDOW_H
