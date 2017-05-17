//
// Created by Sorin Sebastian Mircea on 17/05/2017.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI.h"

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


public:
    MovieController<FSTL>* movieController;
public:
    //Functionality
    void populateMovieList();
    void populateWatchList();
    void connectSignalsWithSlots();

    void addMovie();
    void editMovie();
    void eraseMovie();


};

#endif // MAINWINDOW_H
