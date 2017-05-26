//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#ifndef LAB5_6_UNDOUPDATE_H
#define LAB5_6_UNDOUPDATE_H


#include "UndoRedo.h"
#include "../Repository/IWatchListRepository.h"
#include "../Repository/MovieRepository.h"
#include "../Repository/IMovieRepository.h"

template<class TRepo>
class UndoRedoUpdate: public UndoRedo<TRepo> {
private:
    Movie oldMovie, newMovie;
    TRepo& movieRepository;

public:
    UndoRedoUpdate(TRepo &repo, const Movie &movieOld, const Movie &movieNew);

    void executeUndo() override;
    void executeRedo() override;
};


#endif //LAB5_6_UNDOUPDATE_H
