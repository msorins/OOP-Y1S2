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

string WatchListItem::getTitle() {
    /*
     * GETTER for the title
     */
    return this->title;
}
