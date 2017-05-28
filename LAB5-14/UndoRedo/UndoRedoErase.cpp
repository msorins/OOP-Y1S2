//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#include "UndoRedoErase.h"
#include "../Repository/FileMovieRepository.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../List/STLVector.h"

template<class TRepo>
UndoRedoErase<TRepo>::UndoRedoErase(TRepo &repo, const Movie &movie): movieRepository{repo}, erasedMovie{movie} {

}

template<class TRepo>
void UndoRedoErase<TRepo>::executeUndo() {
    this->movieRepository.add(erasedMovie);
}

template<class TRepo>
void UndoRedoErase<TRepo>::executeRedo() {
    this->movieRepository.del(erasedMovie);
}

template class UndoRedoErase<FileMovieRepository<DynamicArray<Movie> > >;
template class UndoRedoErase<FileMovieRepository<STLVector<Movie> > >;
template class UndoRedoErase<MemoryMovieRepository<DynamicArray<Movie> > >;
template class UndoRedoErase<MemoryMovieRepository<STLVector<Movie> > >;