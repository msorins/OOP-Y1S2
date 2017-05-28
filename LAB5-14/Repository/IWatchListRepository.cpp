//
// Created by Sorin Sebastian Mircea on 23/03/2017.
//

#include "IWatchListRepository.h"
#include "../Others/Exception.h"
#include "../Others/Iterator.h"
#include <fstream>
using namespace std;

IWatchListRepository::IWatchListRepository() {
    /*
     * CONSTRUCTOR
     */
}

DynamicArray<WatchListItem> &IWatchListRepository::getWatchList() {
    /*
     * GETTER for the watchList
     */
    return this->watchList;
}

void IWatchListRepository::add(WatchListItem item) {
    /*
     * Add a new item to the Watch List
     */
    if(this->getWatchList().find(item) != -1)
        throw Exception("Movie already in the watch list");

    this->getWatchList().push_back(item);

    this->save();
}

void IWatchListRepository::del(WatchListItem item) {
    /*
     * Deletes an item from the watch list
     *
     */
    if(this->getWatchList().find(item) == -1)
        throw Exception("Can't delete movie from the watch list. It does not exists");

    this->getWatchList().erase( this->getWatchList().find(item) );

    this->save();
}

WatchListItem * IWatchListRepository::begin() {
    return this->getWatchList().begin();
}

WatchListItem * IWatchListRepository::end() {
    return this->getWatchList().end();
}


void IWatchListRepository::save() {
    //Save movies to file
    ofstream fout("../Files/watch-list.txt");

    fout<<"x"<<"\n";

    Iterator< WatchListItem > st1( this->getWatchList().begin() );
    Iterator< WatchListItem > dr1( this->getWatchList().end() );


    for (Iterator< WatchListItem > it=st1; it!=dr1; it++) {
        WatchListItem crtWatchList = *it;

        if(!crtWatchList.getTitle().size())
            continue;

        Movie mov = crtWatchList.getMovie();
        fout << mov;
    }

    fout.close();

}
