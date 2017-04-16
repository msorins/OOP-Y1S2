//
// Created by Sorin Sebastian Mircea on 23/03/2017.
//

#ifndef LAB5_6_WATCHLISTREPOSITORY_H
#define LAB5_6_WATCHLISTREPOSITORY_H
#include "../List/DynamicArray.h"
#include "../Model/WatchListItem.h"
class IWatchListRepository {
private:
    DynamicArray<WatchListItem> watchList;

public:
    //Constructors
    IWatchListRepository();

    //Getters
    DynamicArray<WatchListItem>& getWatchList();

    //Functionality
    void add(WatchListItem item);
    void del(WatchListItem item);

    //ForIterators
    WatchListItem * begin();
    WatchListItem * end();

    //Functionality
    void load();
    void save();
    virtual void saveCustom() = 0;

};


#endif //LAB5_6_WATCHLISTREPOSITORY_H
