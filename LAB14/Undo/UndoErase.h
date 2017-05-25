//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#ifndef LAB5_6_UNDOERASE_H
#define LAB5_6_UNDOERASE_H


#include "Undo.h"
#include "../Repository/IWatchListRepository.h"
#include "../Repository/MovieRepository.h"
#include "../Repository/IMovieRepository.h"

template<class TRepo>
class UndoErase: Undo<TRepo> {
private:
    Movie erasedMovie;
    TRepo &movieRepository;

public:
    UndoErase(TRepo &repo, const Movie &movie);

    void executeUndo() override;
};


#endif //LAB5_6_UNDOERASE_H
