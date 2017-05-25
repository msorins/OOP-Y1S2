//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#ifndef LAB5_6_MEMORYMOVIEREPOSITORY_H
#define LAB5_6_MEMORYMOVIEREPOSITORY_H

#include "IMovieRepository.h"

template<class TVector>
class MemoryMovieRepository: public IMovieRepository<TVector> {

public:
    void load() override;
    void save() override;

};


#endif //LAB5_6_MEMORYMOVIEREPOSITORY_H
