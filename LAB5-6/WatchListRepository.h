//
// Created by Sorin Sebastian Mircea on 23/03/2017.
//

#ifndef LAB5_6_WATCHLISTREPOSITORY_H
#define LAB5_6_WATCHLISTREPOSITORY_H
#include "DynamicArray.h"
#include "WatchListItem.h"
class WatchListRepository {
private:
    DynamicArray<WatchListItem> watchList;

public:
    //Constructors
    WatchListRepository();

    //Getters
    DynamicArray<WatchListItem>& getWatchList();

    //Functionality
    void add(WatchListItem item);
    void del(WatchListItem item);

};


#endif //LAB5_6_WATCHLISTREPOSITORY_H
