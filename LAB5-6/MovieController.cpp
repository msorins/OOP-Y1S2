//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include "MovieController.h"

MovieController::MovieController() {

}

MovieController::~MovieController() {

}

MovieRepository & MovieController::getMovieRepository() {
    /*
     * GETTER for movieRepository
     */
    return this->movieRepository;
}

void MovieController::add(string title, string genre, int year, int likes, string trailer) {
    /*
     * Add a new movie
     */
    this->movieRepository.add(Movie(title, genre, year, likes, trailer));
    cout<<"MovieController " << this->getMovieRepository().getMovies().getLength();
}

void MovieController::del(string title) {
    /*
     * Delete a movie
     */
    this->getMovieRepository().del(Movie(title));

}

void MovieController::update(string titleOld, string titleNew, string genreNew, int yearNew, int likesNew,
                             string trailerNew) {
    /*
     * Update a movie
     */
    this->getMovieRepository().update(titleOld, Movie(titleNew, genreNew, yearNew, likesNew, trailerNew));
}
