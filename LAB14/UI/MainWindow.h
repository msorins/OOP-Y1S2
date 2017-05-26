//
// Created by Sorin Sebastian Mircea on 17/05/2017.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QTableView>
#include "UI.h"
#include "Ui_WatchListCustomModel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int loopThroughMoviesPos = 1;
    QtCharts::QChartView *chartView;
    QAbstractItemModel *watchListCustomModel;
    QTableView *watchListView;

public:
    MovieController<FSTL>* movieController;
public:
    //Functionality
    void connectSignalsWithSlots();
    void createWatchListWindow();

public slots:
    void populateMovieList();
    void populateMovieToUser();
    void populateWatchList();
    void addMovie();
    void editMovie();
    void eraseMovie();
    void nextMovie();

    void setAddWatchListTrue();
    void setAddWatchListFalse();
    void addWatchList();
    void eraseWatchList();
    void likeMovie();
    void seeTrailerMovie();

    void createPieChart();

    void executeUndo();
    void executeRedo();

signals:
    void moviesUpdated();
    void watchListUpdated();
    void currentMovieChanged();
};

#endif // MAINWINDOW_H
