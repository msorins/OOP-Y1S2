//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include "MovieController.h"
#include "WatchListRepository.h"

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

WatchListRepository & MovieController::getWatchListRepository() {
    /*
     * GETTER for WatchListItem
     */
    return this->watchListRepository;
}


void MovieController::add(string title, string genre, int year, int likes, string trailer) {
    /*
     * Add a new movie
     */
    this->movieRepository.add(Movie(title, genre, year, likes, trailer));
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

Movie MovieController::getByGenreByStep(string genre, int pos) {
    /*
     * Returns a single movie by genre
     */
    DynamicArray<Movie> moviesByGenre = this->getMovieRepository().getByGenre(genre);

    if(moviesByGenre.size() == 0)
        throw ("No movies with given genre ");

    return moviesByGenre.get( (pos % moviesByGenre.size()) + 1);

}

void MovieController::incrementLikes(string title) {
    /*
     *  Receives a string title and increase the amount of likes
     */

    //Get the position in the dynamic array
    int posMovie = this->getMovieRepository().getMovies().find( Movie(title) );

    //Get the element itself
    Movie crtMovie = this->getMovieRepository().getMovies().get(posMovie);

    //Increase the number of likes
    crtMovie.setLikes( crtMovie.getLikes() + 1 );

    //Delete the old object
    this->getMovieRepository().del( Movie(title) );

    //Now add the new one
    this->getMovieRepository().add( crtMovie );
}

