//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include <csignal>
#include "MovieRepository.h"
#include "../List/STLVector.h"
#include "../Others/Exception.h"

using namespace std;

template<class TVector>
MovieRepository<TVector>::MovieRepository() {
    /*
     * CONSTRUCTOR
     */
}

template<class TVector>
MovieRepository<TVector>::~MovieRepository() {
    /*
     * DESTRUCTOR
     * Freeing the space is done automatically
     */
}

template<class TVector>
TVector & MovieRepository<TVector>::getMovies() {
    /*
     * GETTER for movies
     */
    return this->movies;
}

template<class TVector>
void MovieRepository<TVector>::add(Movie movie) {
    /*
     * Add a new movie
     * If the movie already exists throw an error
     */
    if(this->movies.find(movie) != -1)
        throw Exception("Movie already exists");
    else
        this->movies = this->movies + movie;
        //this->movies.push_back(movie);
        //this->getMovies().push_back(movie);
}

template<class TVector>
void MovieRepository<TVector>::del(Movie movie) {
    /*
     * Delete a movie
     * If the movie already exists throw an error
     */
    if(this->movies.find(movie) == -1)
        throw Exception("Movie does not exists");
    else
        this->movies.erase( this->movies.find(movie) );

}

template<class TVector>
void MovieRepository<TVector>::update(string title, Movie movie) {
    /*
     * Update a movie
     * If the movie does not exists, throw an error
     */

    if(this->movies.find(Movie(title)) == -1)
        throw Exception("Movie does not exists");
    else {
        //First delete it
        this->movies.erase( this -> movies.find(Movie(title) ) );

        //Then erase it
        this->movies = this->movies + movie;
        //this->movies.push_back( movie );
    }
}

template<class TVector>
TVector MovieRepository<TVector>::getByGenre(string genre) {
    /*
    if(!genre.length())
        return this->getMovies();

    TVector res;

    for(int i = 1; i <= this->getMovies().size(); i++) {
        Movie crtMovie = this->getMovies().get(i);
        if(crtMovie.getGenre() == genre)
            res = res + crtMovie;
    }

    return res;*/

    if(!genre.length())
        return this->getMovies();

    TVector res;
    res.push_back(Movie());

    const auto& tmp = genre;
    copy_if(this->getMovies().begin(),
            this->getMovies().end(),
            res.begin(),
            [&tmp](Movie el){
                if( el.getGenre() == tmp )
                    return true;
                return false;
            });


    return res;

}

template<class TVector>
Movie * MovieRepository<TVector>::begin() {
    return this->movies.begin();
}

template<class TVector>
Movie * MovieRepository<TVector>::end() {
    return this->movies.end();
}

template class MovieRepository< DynamicArray<Movie> >;
template class MovieRepository< STLVector<Movie> >;
