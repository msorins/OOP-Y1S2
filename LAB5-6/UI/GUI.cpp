//
// Created by Sorin Sebastian Mircea on 17/05/2017.
//

#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QLabel>
#include "GUI.h"
#include <QListWidget>
#include "../Others/Iterator.h"
#include <string>
#include <iostream>
using namespace std;

GUI::GUI(QWidget *parent): QWidget{parent} {
    this->movieController = new  MovieController< FSTL >( new CSVWatchListRepository() );
    this->movieController->getWatchListRepository()->saveCustom();

    this->initGUI();
    this->populateMovieList();
    this->connectSignalsWithSlots();
}

void GUI::initGUI() {
    QVBoxLayout *layout = new QVBoxLayout{this};

    //Create the list of movies
    this->moviesList = new QListWidget{};


    //Create LineEDits
    QHBoxLayout *line1 = new QHBoxLayout{this};
    this->movieTitle = new QLineEdit{};
    this->movieTitle->setText("Title: ");

    this->movieGenre = new QLineEdit{};
    this->movieGenre->setText("Genre: ");
    line1->addWidget(this->movieTitle);
    line1->addWidget(this->movieGenre);

    //Create LineEDits
    QHBoxLayout *line2 = new QHBoxLayout{this};
    this->movieYear = new QLineEdit{};
    this->movieYear->setText("Year: ");

    this->movieLikes = new QLineEdit{};
    this->movieLikes->setText("Likes: ");
    line2->addWidget(this->movieYear);
    line2->addWidget(this->movieLikes);

    //Create LineEDits
    QHBoxLayout *line3 = new QHBoxLayout{this};
    this->movieTrailer = new QLineEdit{};
    this->movieTrailer->setText("Trailer: ");

    line3->addWidget(this->movieTrailer);


    //Create the push button
    this->addMovies = new QPushButton{};
    this->addMovies->setText("Add movies");


    layout->addWidget(this->moviesList);

    layout->addLayout(line1) ;
    layout->addLayout(line2) ;
    layout->addLayout(line3) ;
    layout->addWidget(this->addMovies);
}

GUI::~GUI() {

}

void GUI::populateMovieList() {

    //Clear the list if it is not empty
    if(this->moviesList->count() > 0)
        this->moviesList->clear();

    Iterator< Movie> st1( this->movieController->getMovieRepository().begin() );
    Iterator< Movie> dr1( this->movieController->getMovieRepository().end() );

    //Then add items to that list
    for (Iterator< Movie > it=st1; it!=dr1; it++) {
        Movie crt = *it;

        string string = crt.getTitle();
        string +=  "  |  " + crt.getGenre() + "  |  " + to_string(crt.getLikes()) + "  |  " + to_string(crt.getYear());
        QString itemText = QString::fromStdString(string);
        QListWidgetItem *item = new QListWidgetItem{itemText};

        this->moviesList->addItem(item);
    }
}

void GUI::connectSignalsWithSlots() {
    QObject::connect(this->addMovies, SIGNAL(clicked()), this, SLOT(addMovie(this->movieTitle->text().toStdString(),
    this->movieGenre->text().toStdString(), atoi(this->movieYear->text().toStdString()), atoi(this->movieLikes->text().toStdString()),
    this->movieTitle->text().toStdString() )));
}

void GUI::addMovie(string title, string genre, int year, int likes, string trailer) {
    /*
     * Add movie SLOT
     */

    //Compute the add operation
    this->movieController->add(title, genre, year, likes, trailer);

    //Emit an signal that announces a change in movies list
    emit moviesUpdated();

}

void GUI::moviesUpdated() {
    /*
     * Signal fired when a movie is updated
     */

    this->populateMovieList();

}


