//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#include "CSVWatchListRepository.h"
#include "../Others/Iterator.h"
#include <fstream>
using namespace std;

CSVWatchListRepository::CSVWatchListRepository() {
    this->loadCustom();
}

void CSVWatchListRepository::saveCustom() {
    /*
     * Saves the content of Watch List Repositoru in a CSV Format
     */
    //Open the File
    ofstream fout("../Files/csv-watch-list.txt");

    Iterator< WatchListItem > st1( this->getWatchList().begin() );
    Iterator< WatchListItem > dr1( this->getWatchList().end() );


    for (Iterator< WatchListItem > it=st1; it!=dr1; it++) {
        WatchListItem crt = *it;

        if(!crt.getTitle().size())
            continue;

        fout<<crt.getMovie().getTitle()<<", "<<crt.getMovie().getGenre()<<","<<crt.getMovie().getYear()<<","<<crt.getMovie().getLikes()<<","<<crt.getMovie().getTrailer()<<"\n";
    }

    fout.close();
    IWatchListRepository::save();
}

void CSVWatchListRepository::loadCustom() {
    Movie crtMovie;
    ifstream fin("../Files/watch-list.txt");

    //Load movies from file
    while(!fin.eof()) {
        fin >> crtMovie;

        if(crtMovie.getTitle().size() == 0)
            break;

        this->add(WatchListItem(crtMovie.getTitle(), crtMovie));
    }

    fin.close();

}


