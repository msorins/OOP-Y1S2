//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#include "UndoErase.h"
#include "../Repository/FileMovieRepository.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../List/STLVector.h"

template<class TRepo>
UndoErase<TRepo>::UndoErase(TRepo &repo, const Movie &movie): movieRepository{repo}, erasedMovie{movie} {

}

template<class TRepo>
void UndoErase<TRepo>::executeUndo() {
    this->movieRepository.add(erasedMovie);
}

template class UndoErase<FileMovieRepository<DynamicArray<Movie> > >;
template class UndoErase<FileMovieRepository<STLVector<Movie> > >;
template class UndoErase<MemoryMovieRepository<DynamicArray<Movie> > >;
template class UndoErase<MemoryMovieRepository<STLVector<Movie> > >;