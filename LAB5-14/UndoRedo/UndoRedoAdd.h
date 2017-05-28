//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#ifndef LAB5_6_UNDOADD_H
#define LAB5_6_UNDOADD_H


#include "UndoRedo.h"
#include "../Model/Movie.h"
#include "../Repository/IWatchListRepository.h"
#include "../Repository/IMovieRepository.h"

template<class TRepo>
class UndoRedoAdd: public UndoRedo<TRepo> {
private:
    Movie addedMovie;
    TRepo &movieRepository;

public:
    UndoRedoAdd(TRepo &repo, const Movie &movie);

    void executeUndo() override;
    void executeRedo() override;
};

#endif //LAB5_6_UNDOADD_H
