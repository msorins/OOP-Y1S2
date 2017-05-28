//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#include "MemoryMovieRepository.h"
#include "../List/DynamicArray.h"
#include "../List/STLVector.h"
#include "../Others/Exception.h"

template<class TVector>
void MemoryMovieRepository<TVector>::load() {

}

template<class TVector>
void MemoryMovieRepository<TVector>::save() {

}

template class MemoryMovieRepository< DynamicArray<Movie> >;
template class MemoryMovieRepository< STLVector<Movie> >;
