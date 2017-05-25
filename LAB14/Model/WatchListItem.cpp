//
// Created by Sorin Sebastian Mircea on 23/03/2017.
//

#include "WatchListItem.h"

WatchListItem::WatchListItem() {
    /*
     * Default constructor
     */
    this->title = "";
}

WatchListItem::WatchListItem(string title) {
    /*
     * Constructor which gets the title
     */
    this->title = title;
}

WatchListItem::WatchListItem(string title, Movie movie) {
    /*
     * Constructor which gets the title and whole information about the movie
     */
    this->title = title;
    this->movie = movie;
}

string WatchListItem::getTitle() {
    /*
     * GETTER for the title
     */
    return this->title;
}

Movie WatchListItem::getMovie(){
    return movie;
}

void WatchListItem::setMovie(Movie movie) {
    this->movie = movie;
}

