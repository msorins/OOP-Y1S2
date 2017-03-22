//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include "UI.h"
#include <iostream>
using namespace std;

UI::UI() {
    while(1) {
        this->printAdminUI();
        this->getInput();
    }
}

MovieController & UI::getMovieController() {
    return this->movieController;
}

void UI::printAdminUI() {
    cout << "\n##########################\n";
    cout << "0. List\n";
    cout << "1. Add\n";
    cout << "2. Delete\n";
    cout << "3. Update\n";
    cout << "##########################\n";
}

void UI::printUserUI() {

}

void UI::getInput() {
    int n;
    cin >> n;

    if(!this->checkCommand(n))
        throw("Invalid command");

    switch(n) {
        case 0:
            this->list();
            break;
        case 1:
            this->add();
            break;
        case 2:
            this->del();
            break;
        case 3:
            this->update();
            break;
        default:
            this->list();
            break;
    }


}

bool UI::checkCommand(int cmd) {
    return cmd >= 0 && cmd <=3;
}

void UI::add() {
    string title, genre, trailer;
    int year, likes;

    cout<<"Title: ";
    cin>>title;

    cout<<"Genre: ";
    cin>>genre;

    cout<<"Year: ";
    cin>>year;

    cout<<"Likes: ";
    cin>>likes;

    cout<<"Trailer: ";
    cin>>trailer;


    this->getMovieController().add(title, genre, likes, year, trailer);
}

void UI::del() {
    string title;

    cout<<"Title: ";
    cin>>title;

    this->getMovieController().del(title);
}

void UI::update() {
    string oldTitle, title, genre, trailer;
    int year, likes;

    cout<<"Old title: ";
    cin>>oldTitle;

    cout<<"New title: ";
    cin>>title;

    cout<<"New genre: ";
    cin>>genre;

    cout<<"New year: ";
    cin>>year;

    cout<<"New likes: ";
    cin>>likes;

    cout<<"New trailer: ";
    cin>>trailer;

    this->getMovieController().update(oldTitle, title, genre, likes, year, trailer);
}

void UI::list() {

    for(int i=1; i<=this->getMovieController().getMovieRepository().getMovies().getLength(); i++) {
            Movie crt = this->getMovieController().getMovieRepository().getMovies().get(i);
            cout<<crt.getTitle() <<"  " << crt.getGenre() << " " << crt.getYear() << " " << crt.getLikes() << " " << crt.getTrailer()<<"\n";
    }

}




