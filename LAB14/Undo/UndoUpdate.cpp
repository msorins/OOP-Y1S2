//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#include "UndoUpdate.h"
#include "../Repository/FileMovieRepository.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../List/STLVector.h"

template<class TRepo>
UndoUpdate<TRepo>::UndoUpdate(TRepo &repo, const Movie &movie): movieRepository{ repo }, updatedMovie{movie}  {

}

template<class TRepo>
void UndoUpdate<TRepo>::executeUndo() {
    this->movieRepository.update(updatedMovie.getTitle(), updatedMovie);
}

template class UndoUpdate<FileMovieRepository<DynamicArray<Movie> > >;
template class UndoUpdate<FileMovieRepository<STLVector<Movie> > >;
template class UndoUpdate<MemoryMovieRepository<DynamicArray<Movie> > >;
template class UndoUpdate<MemoryMovieRepository<STLVector<Movie> > >;