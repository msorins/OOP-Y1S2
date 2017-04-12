//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_MOVIECONTROLLER_H
#define LAB5_6_MOVIECONTROLLER_H
#include "MovieRepository.h"
#include "WatchListItem.h"
#include "WatchListRepository.h"

class MovieController {
private:
    MovieRepository<STLVector<Movie>> movieRepository = MovieRepository<STLVector<Movie>>();
    WatchListRepository watchListRepository;

public:
    // Constructors and Destructors
    MovieController();
    ~MovieController();

    //Getters
    MovieRepository<STLVector<Movie>> & getMovieRepository();
    WatchListRepository & getWatchListRepository();
    Movie getByGenreByStep(string genre, int pos);

    //Functionality
    void add(string title, string genre, int year, int likes, string trailer);
    void del(string title);
    void update(string titleOld, string titleNew, string genreNew, int yearNew, int likesNew, string trailerNew);
    void incrementLikes(string title);
};


#endif //LAB5_6_MOVIECONTROLLER_H
