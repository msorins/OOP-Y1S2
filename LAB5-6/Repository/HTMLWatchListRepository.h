//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#ifndef LAB5_6_HTMLWATCHLISTREPOSITORY_H
#define LAB5_6_HTMLWATCHLISTREPOSITORY_H

#include "IWatchListRepository.h"

class HTMLWatchListRepository: public IWatchListRepository  {
public:
    void saveCustom() override;

};


#endif //LAB5_6_HTMLWATCHLISTREPOSITORY_H
