//
// Created by Sorin Sebastian Mircea on 28/04/2017.
//

#ifndef LAB5_6_MEMORYWATCHLISTREPOSITORY_H
#define LAB5_6_MEMORYWATCHLISTREPOSITORY_H


#include "IWatchListRepository.h"

class MemoryWatchListRepository: public IWatchListRepository {
public:
    void loadCustom() override;

    void saveCustom() override;

    void save() override;

};


#endif //LAB5_6_MEMORYWATCHLISTREPOSITORY_H
