//
// Created by Sorin Sebastian Mircea on 17/05/2017.
//

#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include "../Others/Iterator.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->movieController = new  MovieController< FSTL >( new CSVWatchListRepository() );
    this->movieController->getWatchListRepository()->saveCustom();

    ui->setupUi(this);
    this->populateMovieList();
    this->populateWatchList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateMovieList() {

    if( this->ui->moviesListWidget > 0)
        this->ui->moviesListWidget->clear();

    Iterator< Movie> st1( this->movieController->getMovieRepository().begin() );
    Iterator< Movie> dr1( this->movieController->getMovieRepository().end() );

    //Then add items to that list
    for (Iterator< Movie > it=st1; it!=dr1; it++) {
        Movie crt = *it;

        string string = crt.getTitle();
        string +=  "  |  " + crt.getGenre() + "  |  " + to_string(crt.getLikes()) + "  |  " + to_string(crt.getYear());
        QString itemText = QString::fromStdString(string);
        QListWidgetItem *item = new QListWidgetItem{itemText};

        this->ui->moviesListWidget->addItem(item);
    }
}

void MainWindow::populateWatchList() {

    if( this->ui->watchListWidget > 0)
        this->ui->watchListWidget->clear();

    Iterator< WatchListItem > st1( this->movieController->getWatchListRepository()->begin() );
    Iterator< WatchListItem > dr1( this->movieController->getWatchListRepository()->end() );

    //Then add items to that list
    for (Iterator< WatchListItem > it=++st1; it!=dr1; it++) {
        WatchListItem crt = *it;

        string string = crt.getTitle();
        QString itemText = QString::fromStdString(string);
        QListWidgetItem *item = new QListWidgetItem{itemText};

        this->ui->watchListWidget->addItem(item);
    }
}

void MainWindow::connectSignalsWithSlots() {
    //Connect the ADMIN arrea buttons

    QObject::connect(this->ui->addButton, SIGNAL(clicked()), this, SLOT(addMovie()));
}

void MainWindow::addMovie() {

}

void MainWindow::editMovie() {

}

void MainWindow::eraseMovie() {

}
