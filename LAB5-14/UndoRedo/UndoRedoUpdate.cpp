//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#include "UndoRedoUpdate.h"
#include "../Repository/FileMovieRepository.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../List/STLVector.h"

template<class TRepo>
UndoRedoUpdate<TRepo>::UndoRedoUpdate(TRepo &repo, const Movie &movieOld, const Movie &movieNew): movieRepository{ repo }, oldMovie{movieOld}, newMovie{movieNew}  {

}

template<class TRepo>
void UndoRedoUpdate<TRepo>::executeUndo() {
    this->movieRepository.update(newMovie.getTitle(), oldMovie);
}

template<class TRepo>
void UndoRedoUpdate<TRepo>::executeRedo() {
    this->movieRepository.update(oldMovie.getTitle(), newMovie);
}

template class UndoRedoUpdate<FileMovieRepository<DynamicArray<Movie> > >;
template class UndoRedoUpdate<FileMovieRepository<STLVector<Movie> > >;
template class UndoRedoUpdate<MemoryMovieRepository<DynamicArray<Movie> > >;
template class UndoRedoUpdate<MemoryMovieRepository<STLVector<Movie> > >;