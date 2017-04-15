//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#ifndef LAB5_6_IMOVIEREPOSITORY_H
#define LAB5_6_IMOVIEREPOSITORY_H

#include "../Model/Movie.h"

template<class TVector>
class IMovieRepository {
protected:
    //DynamicArray<Movie> movies;
    TVector movies;

public:
    //Constructors and destructors
    IMovieRepository();
    virtual ~IMovieRepository();

    //Functionality
    virtual void load() = 0;
    virtual void save() = 0;

    //Getters
    TVector & getMovies();
    TVector getByGenre(string genre);

    //Functionality
    void add(Movie movie);
    void del(Movie movie);
    void update(string title, Movie movie);

    //ForIterators
    Movie * begin();
    Movie * end();
};


#endif //LAB5_6_IMOVIEREPOSITORY_H
