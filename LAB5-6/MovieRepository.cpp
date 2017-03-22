//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include <csignal>
#include "MovieRepository.h"
using namespace std;

MovieRepository::MovieRepository() {
    /*
     * CONSTRUCTOR
     */
}

MovieRepository::~MovieRepository() {
    /*
     * DESTRUCTOR
     * Freeing the space is done automatically
     */
}

DynamicArray<Movie> & MovieRepository::getMovies() {
    /*
     * GETTER for movies
     */
    return this->movies;
}

void MovieRepository::add(Movie movie) {
    /*
     * Add a new movie
     * If the movie already exists throw an error
     */
    if(this->movies.find(movie) != -1)
        throw("Movie already exists");
    else
        this->getMovies().push_back(movie);

    cout<<"MovieRepository" << this->getMovies().getLength()<<"\n";
    int x = 1;


}

void MovieRepository::del(Movie movie) {
    /*
     * Delete a movie
     * If the movie already exists throw an error
     */
    if(this->movies.find(movie) == -1)
        throw("Movie does not exists");
    else
        this->movies.erase( this->movies.find(movie) );

}

void MovieRepository::update(string title, Movie movie) {
    /*
     * Update a movie
     * If the movie does not exists, throw an error
     */

    if(this->movies.find(Movie(title)) == -1)
        throw("Movie does not exists");
    else {
        //First delete it
        this->movies.erase( this -> movies.find(Movie(title) ) );

        //Then erase it
        this->movies.push_back( movie );
    }
}
