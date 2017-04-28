//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#ifndef LAB5_6_CSVWATCHLISTREPOSITORY_H
#define LAB5_6_CSVWATCHLISTREPOSITORY_H

#include "IWatchListRepository.h"

class CSVWatchListRepository: public IWatchListRepository  {
public:
    CSVWatchListRepository();

    void saveCustom() override;

    void loadCustom() override;

};


#endif //LAB5_6_CSVWATCHLISTREPOSITORY_H
