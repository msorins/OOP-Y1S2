//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#include "IMovieRepository.h"
#include "../List/DynamicArray.h"
#include "../List/STLVector.h"
#include "../Others/Exception.h"

template<class TVector>
IMovieRepository<TVector>::IMovieRepository() {
    /*
     * CONSTRUCTOR
     */
}


template<class TVector>
IMovieRepository<TVector>::~IMovieRepository() {
    /*
     * DESTRUCTOR
     * Freeing the space is done automatically
     */
}

template<class TVector>
TVector & IMovieRepository<TVector>::getMovies() {
    /*
     * GETTER for movies
     */
    return this->movies;
}

template<class TVector>
void IMovieRepository<TVector>::add(Movie movie) {
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
void IMovieRepository<TVector>::del(Movie movie) {
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
void IMovieRepository<TVector>::update(string title, Movie movie) {
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
TVector IMovieRepository<TVector>::getByGenre(string genre) {
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
Movie * IMovieRepository<TVector>::begin() {
    return this->movies.begin();
}

template<class TVector>
Movie * IMovieRepository<TVector>::end() {
    return this->movies.end();
}

template class IMovieRepository< DynamicArray<Movie> >;
template class IMovieRepository< STLVector<Movie> >;
