//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#include "UndoAdd.h"
#include "../Repository/FileMovieRepository.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../List/STLVector.h"

template<class TRepo>
UndoAdd<TRepo>::UndoAdd(TRepo &repo, const Movie &movie): movieRepository{repo}, addedMovie{movie} {

}

template<class TRepo>
void UndoAdd<TRepo>::executeUndo() {
    this->movieRepository.del(this->addedMovie);

}

template class UndoAdd<FileMovieRepository<DynamicArray<Movie> > >;
template class UndoAdd<FileMovieRepository<STLVector<Movie> > >;
template class UndoAdd<MemoryMovieRepository<DynamicArray<Movie> > >;
template class UndoAdd<MemoryMovieRepository<STLVector<Movie> > >;