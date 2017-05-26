//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include "MovieController.h"
#include "../Repository/IWatchListRepository.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../Repository/FileMovieRepository.h"
#include "../UndoRedo/UndoRedoAdd.h"
#include "../UndoRedo/UndoRedoErase.h"
#include "../UndoRedo/UndoRedoUpdate.h"
#include <memory>
template<class TRepo>
MovieController<TRepo>::MovieController() {
    /*
     * CONSTRUCTOR
     */

    this->getMovieRepository().load();
}

template<class TRepo>
MovieController<TRepo>::MovieController(IWatchListRepository *watchListRepo) {
    this->getMovieRepository().load();
    this->setWatchListRepository(watchListRepo);
}


template<class TRepo>
MovieController<TRepo>::~MovieController() {

}

template<class TRepo>
TRepo & MovieController<TRepo>::getMovieRepository() {
    /*
     * GETTER for movieRepository
     */
    return this->movieRepository;
}

template<class TRepo>
IWatchListRepository *MovieController<TRepo>::getWatchListRepository() {
    /*
     * GETTER for WatchListItem
     */
    return this->watchListRepository;
}

template<class TRepo>
void MovieController<TRepo>::add(string title, string genre, int year, int likes, string trailer) {
    /*
     * Add a new movie
     */
    Movie addedMovie = Movie(title, genre, year, likes, trailer);
    this->movieRepository.add(addedMovie);

    this->getMovieRepository().save();

    //Add to undoList
    shared_ptr< UndoRedoAdd<TRepo> > undoPointer =  make_shared< UndoRedoAdd<TRepo> >(this->getMovieRepository(), addedMovie);
    this->undoList.push_back( make_unique< UndoRedoAdd<TRepo> >(this->getMovieRepository(), addedMovie) );

}

template<class TRepo>
void MovieController<TRepo>::del(string title) {
    /*
     * Delete a movie
     */

    //Add to undoList
    int erasedMoviePos = this->getMovieRepository().getMovies().find(Movie(title));
    Movie erasedMovie = this->getMovieRepository().getMovies().get(erasedMoviePos);
    this->undoList.push_back( make_shared< UndoRedoErase<TRepo> >(this->getMovieRepository(), erasedMovie));

    this->getMovieRepository().del(Movie(title));

    this->getMovieRepository().save();

}

template<class TRepo>
void MovieController<TRepo>::update(string titleOld, string titleNew, string genreNew, int yearNew, int likesNew,
                             string trailerNew) {
    /*
     * Update a movie
     */

    //Add to undoList
    int updatedMoviePos = this->getMovieRepository().getMovies().find(Movie(titleOld));
    Movie updatedOldMovie = this->getMovieRepository().getMovies().get(updatedMoviePos);
    this->undoList.push_back( make_shared< UndoRedoUpdate<TRepo> >(this->getMovieRepository(), updatedOldMovie, Movie(titleNew, genreNew, yearNew, likesNew, trailerNew)));


    this->getMovieRepository().update(titleOld, Movie(titleNew, genreNew, yearNew, likesNew, trailerNew));

    this->getMovieRepository().save();
}

template<class TRepo>
Movie MovieController<TRepo>::getByGenreByStep(string genre, int pos) {
    /*
     * Returns a single movie by genre
     */
    auto moviesByGenre = this->getMovieRepository().getByGenre(genre);

    if(moviesByGenre.size() == 0)
        throw ("No movies with given genre ");

    return moviesByGenre.get( (pos % moviesByGenre.size()) );

}

template<class TRepo>
void MovieController<TRepo>::incrementLikes(string title) {
    /*
     *  Receives a string title and increase the amount of likes
     */

    //Get the position in the dynamic array
    int posMovie = this->getMovieRepository().getMovies().find( Movie(title) );

    //Get the element itself
    Movie crtMovie = this->getMovieRepository().getMovies().get(posMovie);

    //Increase the number of likes
    crtMovie.setLikes( crtMovie.getLikes() + 1 );

    //Delete the old object
    this->getMovieRepository().del( Movie(title) );

    //Now add the new one
    this->getMovieRepository().add( crtMovie );
}

template<class TRepo>
void MovieController<TRepo>::setWatchListRepository(IWatchListRepository *watchListRepository) {
    this->watchListRepository = watchListRepository;
}


template class MovieController< MemoryMovieRepository<STLVector<Movie>> >;
template class MovieController< FileMovieRepository<STLVector<Movie>> >;

template class MovieController< MemoryMovieRepository<DynamicArray<Movie>> >;
template class MovieController< FileMovieRepository<DynamicArray<Movie>> >;

