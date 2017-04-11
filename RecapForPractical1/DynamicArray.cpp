//
// Created by Sorin Sebastian Mircea on 09/04/2017.
//
#include <iostream>
#include "DynamicArray.h"
using namespace std;
#define DEFLENGTH 100

template<class TElement>
DynamicArray::DynamicArray() {
    this->n = 0;
    this->capacity = DEFLENGTH;
    this->elems = new TElement[DEFLENGTH];
}

template<class TElement>
DynamicArray::DynamicArray(TElement t) {
    this->DynamicArray();
    this->push_back(t);
}

DynamicArray::~DynamicArray() {
    delete []this->elems;
}

template<class TElement>
void DynamicArray::push_back(TElement t) {

    this->n++;
    if(this->n == this->capacity)
        this->resize();

    this->elems[n] = t;
}

template<class TElement>
void DynamicArray::resize() {
    this->capacity *= 2;

    TElement* newElems = new TElement[this->capacity];

    for(int i = 1; i<= this->n; i++)
        newElems[i] = this->elems[i];

    delete []this->elems;

    this->elems = newElems;
}


void DynamicArray::erase(int pos) {

    this->validatePosition(pos);

    for(int i = pos;  i<= this->n; i++)
        this->elems[i] = this->elems[i+1];

    this->n--;
}

template<class TElement>
int DynamicArray::find(TElement t) {

    for(int i =  1; i<= this->n; i++)
        if(this->elems[i] == t)
            return i;

    return -1;
}

template<class TElement>
void DynamicArray::insert(TElement t, int pos) {
    this->validatePosition(pos);

    this->n++;

    if(this->n == this->capacity) {
        this->resize();
    }

    for(int i = n; i > pos; i--)
        this->elems[i] = this->elems[i-1];

    this->elems[pos] = t;
}

void DynamicArray::validatePosition(int position) {
    if(position < 1 || position > this->getLength())
        throw("Invalid delete position (Dynamic Array)");
}

int DynamicArray::getLength() {
    return this->n;
}

template<class TElement>
TElement *DynamicArray::getArray() {
    return  this->elems;
}


//template class DynamicArray<int>;
