//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#ifndef LAB5_6_UNDOERASE_H
#define LAB5_6_UNDOERASE_H


#include "UndoRedo.h"
#include "../Repository/IWatchListRepository.h"
#include "../Repository/MovieRepository.h"
#include "../Repository/IMovieRepository.h"

template<class TRepo>
class UndoRedoErase: public UndoRedo<TRepo> {
private:
    Movie erasedMovie;
    TRepo &movieRepository;

public:
    UndoRedoErase(TRepo &repo, const Movie &movie);

    void executeUndo() override;
    void executeRedo() override;

};


#endif //LAB5_6_UNDOERASE_H
