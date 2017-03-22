//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_MOVIECONTROLLER_H
#define LAB5_6_MOVIECONTROLLER_H
#include "MovieRepository.h"

class MovieController {
private:
    MovieRepository movieRepository;

public:
    // Constructors and Destructors
    MovieController();
    ~MovieController();

    //Getters
    MovieRepository & getMovieRepository();

    //Functionality
    void add(string title, string genre, int year, int likes, string trailer);
    void del(string title);
    void update(string titleOld, string titleNew, string genreNew, int yearNew, int likesNew, string trailerNew);
};


#endif //LAB5_6_MOVIECONTROLLER_H
