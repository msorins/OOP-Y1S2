//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#include "UndoRedoAdd.h"
#include "../Repository/FileMovieRepository.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../List/STLVector.h"

template<class TRepo>
UndoRedoAdd<TRepo>::UndoRedoAdd(TRepo &repo, const Movie &movie): movieRepository{repo}, addedMovie{movie} {

}

template<class TRepo>
void UndoRedoAdd<TRepo>::executeUndo() {
    this->movieRepository.del(this->addedMovie);

}

template<class TRepo>
void UndoRedoAdd<TRepo>::executeRedo() {
    this->movieRepository.add(this->addedMovie);
}

template class UndoRedoAdd<FileMovieRepository<DynamicArray<Movie> > >;
template class UndoRedoAdd<FileMovieRepository<STLVector<Movie> > >;
template class UndoRedoAdd<MemoryMovieRepository<DynamicArray<Movie> > >;
template class UndoRedoAdd<MemoryMovieRepository<STLVector<Movie> > >;