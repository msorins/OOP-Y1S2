//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include "UI.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

UI::UI() {
    this->getMovieController().add("Supernatural", "Horror", 2000, 500, "https://www.youtube.com/watch?v=4kmA86_hnbo");
    this->getMovieController().add("Family guy", "Comedy", 1997, 150, "https://www.youtube.com/watch?v=_ZKpw0SlAfc");
    this->getMovieController().add("The Blacklist", "Action", 2010, 40, "https://www.youtube.com/watch?v=JGBIimq1I3A");
    this->getMovieController().add("Person of Interest", "Action", 2012, 350, "https://www.youtube.com/watch?v=WYDWSNMTauQ");
    this->getMovieController().add("Suits", "Reality", 2012, 5, "https://www.youtube.com/watch?v=6Zu0yYV2uYs");

    this->mode = "MAIN";

    while(1) {
        if(this->mode == "MAIN") {
            this->printMainUI();
            this->getMainInput();
        } else if(this-> mode == "ADMIN") {
            this->printAdminUI();
            this->getAdminInput();
        } else if(this-> mode == "USER") {
            this->printUserUI();
            this->getUserInput();
        }

    }
}

MovieController & UI::getMovieController() {
    return this->movieController;
}

void UI::printMainUI() {
    cout << "\n##########################\n";
    cout << "0. Admin\n";
    cout << "1. User\n";
    cout << "##########################\n";
}

void UI::printAdminUI() {
    cout << "\n##########################\n";
    cout << "0. List\n";
    cout << "1. Add\n";
    cout << "2. Delete\n";
    cout << "3. Update\n";
    cout << "9. -Back- \n";
    cout << "##########################\n";
}

void UI::printUserUI() {
    cout << "\n##########################\n";
    cout << "0. Watch list\n";
    cout << "1. See movies\n";
    cout << "2. Delete from watch list\n";
    cout << "9. -Back- \n";
    cout << "##########################\n";
}

void UI::getMainInput() {
    int n;
    cin >> n;

    if(!(n >= 0 && n <= 1))
        throw("Invalid command");

    switch(n) {
        case 0:
            this->mode = "ADMIN";
            break;
        case 1:
            this->mode = "USER";
            break;
        default:
            break;
    }
}

void UI::getAdminInput() {
    int n;
    cin >> n;

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
            this->mode = "MAIN";
            break;
    }
}


void UI::getUserInput() {
    int n;
    cin >> n;

    switch(n) {
        case 0:
            this->userSeeWatchList();
            break;
        case 1:
            this->userSeeMoviesByGenre();
            break;
        case 2:
            this->userDeleteWatchList();
            break;
        default:
            this->mode = "MAIN";
            break;
    }
}


bool UI::checkCommand(int cmd) {
    return cmd >= 0 && cmd <=3;
}

void UI::add() {
    char aux[100];
    string title, genre, trailer;
    int year, likes;

    //Flush get line
    this->flushGetLine();

    cout<<"Title: ";
    cin.getline(aux, 100);
    title = string(aux);


    cout<<"Genre: ";
    cin.getline(aux, 100);
    genre = string(aux);

    cout<<"Year: ";
    cin>>year;

    cout<<"Likes: ";
    cin>>likes;

    cout<<"Trailer: ";
    cin>>trailer;


    this->getMovieController().add(title, genre, likes, year, trailer);
}

void UI::del() {
    char aux[100];
    string title;

    //Flush get line
    this->flushGetLine();

    cout<<"Title: ";
    cin.getline(aux, 100);
    title = string(aux);

    this->getMovieController().del(title);
}

void UI::update() {
    char aux[100];
    string oldTitle, title, genre, trailer;
    int year, likes;

    //Flush get line
    this->flushGetLine();

    cout<<"Old title: ";
    cin.getline(aux, 100);
    oldTitle = string(aux);

    cout<<"New title: ";
    cin.getline(aux, 100);
    title = string(aux);

    cout<<"New genre: ";
    cin.getline(aux, 100);
    genre = string(aux);

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

void UI::userSeeMoviesByGenre() {
    int pos = 1, cmd, cmd2;
    string genre;
    char genreStr[100];
    Movie crtMovie;

    //Flush get line
    this->flushGetLine();

    cout << "Genre: ";
    cin.getline(genreStr, 100);
    genre = string(genreStr);



    while(true) {
        cout<<"\n\n####  Title              |              Genre          |              Likes              ####\n";
        cout<<"=============================================================================================\n";
        crtMovie = this->getMovieController().getByGenreByStep(genre, pos);

        cout << "      " << crtMovie.getTitle() << "        " << crtMovie.getGenre() << "          " << crtMovie.getLikes()<<"\n\n";
        cout << "---------------------------------------------------------------------------------------------------------\n" ;

        cout << "1. Like trailer\n";
        cout << "2. Next\n";
        cout << "3. Back\n";

        //Open a link in chrome
        string command ("open '/Applications/Google Chrome.app/Contents/Versions/55.0.2883.95/Google Chrome Helper.app'");
        command += " " + crtMovie.getTrailer();
        system(command.c_str());


        cin.sync();
        cin >> cmd;
        switch(cmd){
            case 1:
                //LIKE -> increment the number of likes
                //this->getMovieController().incrementLikes( crtMovie.getTitle() );

                cout << "\n---------------------------------------------------------------------------------------------------------  \n" ;
                cout << "1. Add to watchlist\n";
                cout << "2. Back\n";

                cin>>cmd2;
                switch(cmd2) {
                    case 1:
                        // ADD to watchlist
                        this->movieController.getWatchListRepository().add(WatchListItem( crtMovie.getTitle() ));
                        pos += 1;
                        break;
                    default:
                        break;
                }

                continue;
            case 2:
                //NEXT
                pos += 1;
                continue;
            default:
                pos = -1;
                break;
        }

        //Lame stuff to trick the IDE not to show a warning anymore
        if( pos == -1)
            break;

    }
}

void UI::userSeeWatchList() {
    WatchListItem crtItem;

    cout<<"\n\n####          Title          ####\n";
    cout<<"=================================\n";
    for(int i = 1; i <= this->getMovieController().getWatchListRepository().getWatchList().getLength(); i++) {
        crtItem = this->getMovieController().getWatchListRepository().getWatchList().get(i);
        cout<<"    " << crtItem.getTitle() << "\n";
    }
}

void UI::userDeleteWatchList() {
    char aux[100];
    int cmd;
    string title;

    //Flush get line
    this->flushGetLine();

    cout << "Title: ";
    cin.getline(aux, 100);
    title = string(aux);

    int pos = this->getMovieController().getWatchListRepository().getWatchList().find(WatchListItem(title));
    if(pos == -1)
        throw "Invalid movie name";
    this->getMovieController().getWatchListRepository().getWatchList().erase(pos);




    cout << "\n---------------------------------------------------------------------------------------------------------  \n" ;
    cout << "1. Like the movie\n";
    cout << "2. Back\n";

    cin>>cmd;
    switch(cmd) {
        case 1:
            // Like the movie
            this->getMovieController().incrementLikes( title );
            break;
        default:
            break;
    }
}

void UI::flushGetLine() {
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }

}
