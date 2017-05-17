//
// Created by Sorin Sebastian Mircea on 23/03/2017.
//

#ifndef LAB5_6_WATCHLIST_H
#define LAB5_6_WATCHLIST_H
#include <iostream>
#include "Movie.h"

using namespace std;

class WatchListItem {
private:
    string title;
    Movie movie;

public:
    //Constructors
    WatchListItem();
    WatchListItem(string title);
    WatchListItem(string title, Movie movie);

    //Getters
    string getTitle();
    Movie getMovie();
    void setMovie(Movie movie);

    //Operator
    bool operator==( WatchListItem  A) {
        if(A.title == this->title)
            return true;
        return false;
    }

};


#endif //LAB5_6_WATCHLIST_H
