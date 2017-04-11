//
// Created by Sorin Sebastian Mircea on 11/04/2017.
//

#include "Iterator.h"
#include "Movie.h"
#include "WatchListItem.h"
#include "DynamicArray.h"

template class Iterator<int>;
template class Iterator<Movie>;
template class Iterator< DynamicArray<int> >;
template class Iterator<WatchListItem>;