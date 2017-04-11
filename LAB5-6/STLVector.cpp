//
// Created by z003swax on 11.04.2017.
//

#include "STLVector.h"

template<class TElement>
STLVector<TElement>::~STLVector() {
    /*
     * Constructor, nothing to do
     */
}

template<class TElement>
void STLVector<TElement>::push_back(TElement elem) {
    /*
    * Adds a new element to the back of the Array
    */
    this->elems.push_back(elem);
}

template<class TElement>
void STLVector<TElement>::erase(int pos) {
    /*
    * Given a position(int) .. erase that position
    */

    //Validate the position
    this->validatePosition(pos);

    //Do the actual erasing
    this->elems.erase(this->elems.begin() + pos);
}

template<class TElement>
void STLVector<TElement>::resize() {
    //Nothing to do here
    //To erase
}

template<class TElement>
TElement STLVector<TElement>::get(int pos) {
    /*
    * GETTER FOR A SPECIFIC ELEMENT IN AN ARRAY
    */

    //Validate the position
    this->validatePosition(pos);

    //Get the actual element
    return this->elems[pos];
}

template<class TElement>
int STLVector<TElement>::find(TElement elem) {
    /*
     * Find a particular element in an array.
     * If it is found return its index, otherwise return -1
     */
    for(int i = 0; i< this->elems.size(); i++)
        if(this->elems[i] == elem)
            return i;

    return -1;
}

template<class TElement>
void STLVector<TElement>::insert(TElement element, int pos) {
    /*
     * Inserts an element at a given position
     */

    //Validate the position
    this->validatePosition(pos);

    //Insert that element
    this->elems.insert(this->elems.begin() + pos, element);
}

template<class TElement>
void STLVector<TElement>::validatePosition(int position) {
    /*
    * Validates the position...If it is not valid it raises an error
    */
    if(position < 0 || position >= this->size())
        throw("Invalid delete position (Dynamic Array)");
}

template<class TElement>
int STLVector<TElement>::size() {
    /*
    * GETTER FOR THE LENGTH OF ARRAY
    */
    return this->elems.size();
}

template<class TElement>
TElement *STLVector<TElement>::getArray() {
    TElement* a;
    return a;
}

template<class TElement>
TElement *STLVector<TElement>::begin() {
    return &this->elems[0];
}

template<class TElement>
TElement *STLVector<TElement>::end() {
    return &this->elems[this->elems.size() -1];
}

template class STLVector<int>;
template class STLVector<Movie>;
template class STLVector<WatchListItem>;