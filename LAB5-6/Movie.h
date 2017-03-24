//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_MOVIE_H
#define LAB5_6_MOVIE_H
#include <iostream>
using namespace std;

class Movie {
private:
    string title;
    string genre;
    int year;
    int likes;
    string trailer;

public:

    //Constructors and destructors
    Movie(string title, string genre, int year, int likes, string trailer);
    Movie(string title);
    Movie();
    ~Movie();

    //Getters
    string getTitle();
    string getGenre();
    int getYear();
    int getLikes();
    string getTrailer();

    //Setters
    void setTitle(string title);
    void setGenre(string genre);
    void setYear(int year);
    void setLikes(int likes);
    void setTrailer(string trailer);

    //Operators
    bool operator==( Movie  A) {
        if(A.title == this->title)
            return true;
        return false;
    }

};


#endif //LAB5_6_MOVIE_H
