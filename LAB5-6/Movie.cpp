//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include "Movie.h"

Movie::Movie(string title, string genre, int year, int likes, string trailer) {
    this->setTitle(title);
    this->setGenre(genre);
    this->setYear(year);
    this->setLikes(likes);
    this->setTrailer(trailer);
}

Movie::Movie(string title) {
    this->setTitle(title);

}


Movie::Movie() {

}


Movie::~Movie() {

}


string Movie::getGenre() {
    /*
     * GETTER for genre
     */
    return this->genre;
}

int Movie::getYear() {
    /*
    * GETTER for year
    */
    return this->year;
}

int Movie::getLikes() {
    /*
    * GETTER for likes
    */
    return this->likes;
}

string Movie::getTrailer() {
    /*
    * GETTER for trailer
    */
    return this->trailer;
}

string Movie::getTitle() {
    /*
    * GETTER for title
    */
    return this->title;
}

void Movie::setTitle(string title) {
    /*
    * SETTER for title
    */
    this->title = title;
}

void Movie::setGenre(string genre) {
    /*
    * SETTER for genre
    */
    this->genre = genre;
}

void Movie::setYear(int year) {
    /*
    * SETTER for year
    */
    this->year = year;
}

void Movie::setLikes(int likes) {
    /*
    * SETTER for likes
    */
    this->likes = likes;
}

void Movie::setTrailer(string trailer) {
    /*
    * SETTER for trailer
    */
    this->trailer = trailer;

}

