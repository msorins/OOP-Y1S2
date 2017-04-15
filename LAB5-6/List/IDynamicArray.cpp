//
// Created by z003swax on 11.04.2017.
//

#include "IDynamicArray.h"

template<class TElement>
IDynamicArray<TElement>::~IDynamicArray() {
    /*
     * Destructor
     * Free the space allocated for elements
     */

}

template class IDynamicArray<int>;
template class IDynamicArray<Movie>;
template class IDynamicArray<WatchListItem>;