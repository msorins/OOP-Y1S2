//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include <csignal>
#include "DynamicArray.h"
#include "Movie.h"
#include "WatchListItem.h"

using namespace std;
#define DEFLENGTH 100


template<class TElement>
DynamicArray<TElement>::DynamicArray() {
    /*
     * Constructor
     * Initialises the DynamicArray
     */

    this->n = 0;
    this->capacity = DEFLENGTH;
    this->elems = new TElement[DEFLENGTH];
}

template<class TElement>
DynamicArray<TElement>::DynamicArray(TElement t) {
    this->push_back(t);
}

template<class TElement>
DynamicArray<TElement>::~DynamicArray() {
    /*
     * Destructor
     * Free the space allocated for elements
     */
    delete []this->elems;
}

template<class TElement>
void DynamicArray<TElement>::push_back(TElement elem) {
    /*
     * Adds a new element to the back of the Array
     */

    this->n++;

    //The array is full, must allocate more memory
    if(this->n == this->capacity) {
        this -> resize();
    }

    //Actually add the new elementh
    this->elems[n] = elem;
}

template<class TElement>
void DynamicArray<TElement>::resize() {
    //Increase the Capacity
    this->capacity *= 2;

    //Put the elements into a new array
    TElement* newElems = new TElement[this->capacity];
    for(int i = 1; i <= this->n ; i++)
        newElems[i] = this->elems[i];

    //Delete current array
    delete []this->elems;

    //Move the new (bigger) array in place
    this->elems = newElems;
}

template<class TElement>
void DynamicArray<TElement>::erase(int pos) {
    /*
     * Given a position(int) .. erase that position
     */

    //Validate the position
    this->validatePosition(pos);

    //Remove the element at that position
    for(int i = pos; i<= this->getLength(); i++)
        this->elems[i] = this->elems[i+1];

    //Decrease the length
    this -> n--;

}

template<class TElement>
TElement DynamicArray<TElement>::get(int pos) {
    /*
     * GETTER FOR A SPECIFIC ELEMENT IN AN ARRAY
     */

    //Validate the position
    this->validatePosition(pos);

    return this->elems[pos];
}

template<class TElement>
int DynamicArray<TElement>::getLength() {
    /*
     * GETTER FOR THE LENGTH OF ARRAY
     */
    return this->n;
}

template<class TElement>
TElement *DynamicArray<TElement>::getArray() {
    /*
     * GETTER FOR THE ARRAY
     */
    return this->elems;
}

template<class TElement>
void DynamicArray<TElement>::validatePosition(int position) {
    /*
     * Validates the position...If it is not valid it raises an error
     */
    if(position < 1 || position > this->getLength())
        throw("Invalid delete position (Dynamic Array)");

}

template<class TElement>
int DynamicArray<TElement>::find(TElement elem) {
    /*
     * Find a particular element in an array.
     * If it is found return its index, otherwise return -1
     */
    for(int i = 1; i<= this->getLength(); i++)
        if(this->elems[i] == elem)
            return i;

    return -1;
}

template<class TElement>
void DynamicArray<TElement>::insert(TElement element, int pos) {
    /*
     * Inserts an element at a given position
     */

    //Validate the position
    this->validatePosition(pos);


    //Increase the number of elements in the array
    this->n++;

    //The array is full, must allocate more memory
    if(this->n == this->capacity) {
        this -> resize();
    }

    //Move all the elements to the right
    for(int i = n; i > pos; i--)
        this->elems[i] = this->elems[i-1];

    //Insert that element
    this->elems[pos] = element;
}





template class DynamicArray<int>;
template class DynamicArray<Movie>;
template class DynamicArray<WatchListItem>;