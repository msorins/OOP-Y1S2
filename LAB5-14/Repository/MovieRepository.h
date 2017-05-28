//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_MOVIEREPOSITORY_H
#define LAB5_6_MOVIEREPOSITORY_H

#include "../List/DynamicArray.h"
#include "../Model/Movie.h"
#include "../List/STLVector.h"

template<class TVector>
class MovieRepository {
private:
    //DynamicArray<Movie> movies;
    TVector movies;

public:

    // Constructors and Destructors
    MovieRepository();
    ~MovieRepository();

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


#endif //LAB5_6_MOVIEREPOSITORY_H
