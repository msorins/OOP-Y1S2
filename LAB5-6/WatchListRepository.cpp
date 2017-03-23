//
// Created by Sorin Sebastian Mircea on 23/03/2017.
//

#include "WatchListRepository.h"

WatchListRepository::WatchListRepository() {
    /*
     * CONSTRUCTOR
     */
}

DynamicArray<WatchListItem> &WatchListRepository::getWatchList() {
    /*
     * GETTER for the watchList
     */
    return this->watchList;
}

void WatchListRepository::add(WatchListItem item) {
    /*
     * Add a new item to the Watch List
     */
    if(this->getWatchList().find(item) != -1)
        throw("Movie already in the watch list");

    this->getWatchList().push_back(item);
}

void WatchListRepository::del(WatchListItem item) {
    /*
     * Deletes an item from the watch list
     *
     */
    if(this->getWatchList().find(item) == -1)
        throw("Can't delete movie from the watch list. It does not exists");

    this->getWatchList().erase( this->getWatchList().find(item) );
}
