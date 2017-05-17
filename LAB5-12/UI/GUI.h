//
// Created by Sorin Sebastian Mircea on 17/05/2017.
//



#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QWidget>
#include "../Controller/MovieController.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../Repository/FileMovieRepository.h"
#define STL  MemoryMovieRepository<STLVector<Movie>>
#define DYN  MemoryMovieRepository<DynamicArray<Movie>>
#define FSTL FileMovieRepository<STLVector<Movie>>
#define FDYN FileMovieRepository<DynamicArray<Movie>>


class GUI: public QWidget {
Q_OBJECT
public:
    MovieController<FSTL>* movieController;

private:
    QListWidget *moviesList;
    QPushButton* addMovies;

    QLineEdit* movieTitle;
    QLineEdit* movieGenre;
    QLineEdit* movieYear;
    QLineEdit* movieLikes;
    QLineEdit* movieTrailer;

public:
    //Constructor & destructor
    GUI(QWidget *parent = 0);
    ~GUI();


    //Functionality
    void initGUI();
    void connectSignalsWithSlots();

signals:
    void moviesUpdated();

public slots:
    void addMovie();
    void populateMovieList();
};
