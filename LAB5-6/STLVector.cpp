//
// Created by z003swax on 11.04.2017.
//

#include "STLVector.h"

template<class TElement>
STLVector<TElement>::~STLVector() {

}

template<class TElement>
void STLVector<TElement>::push_back(TElement elem) {

}

template<class TElement>
void STLVector<TElement>::erase(int pos) {

}

template<class TElement>
void STLVector<TElement>::resize() {

}

template<class TElement>
TElement STLVector<TElement>::get(int pos) {
    return nullptr;
}

template<class TElement>
int STLVector<TElement>::find(TElement elem) {
    return 0;
}

template<class TElement>
void STLVector<TElement>::insert(TElement element, int pos) {

}

template<class TElement>
void STLVector<TElement>::validatePosition(int position) {

}

template<class TElement>
int STLVector<TElement>::getLength() {
    return 0;
}

template<class TElement>
TElement *STLVector<TElement>::getArray() {
    return nullptr;
}

template class STLVector<int>;
template class STLVector<Movie>;
template class STLVector<WatchListItem>;