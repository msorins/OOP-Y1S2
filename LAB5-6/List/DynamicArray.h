//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//
#pragma once
#ifndef LAB5_6_DYNAMICARRAY_H
#define LAB5_6_DYNAMICARRAY_H
#include <iostream>
#include "IDynamicArray.h"
using namespace std;

template<class TElement>
class DynamicArray:  IDynamicArray<TElement> {
protected:
    TElement* elems;
private:
    int n;
    int capacity;

public:
    //Constructors and Destructors
    DynamicArray(TElement t);
    DynamicArray();
    ~DynamicArray();

    //Functionality
    void push_back(TElement elem);
    void erase(int pos);
    void resize();
    TElement get(int pos);
    int find(TElement elem);
    void insert(TElement element, int pos);
    void validatePosition(int position);

    //Getters
    int size();
    TElement* getArray();

    //ForIterators
    TElement * begin();
    TElement * end();

    //Operators
    DynamicArray& operator = (DynamicArray A ) {
        TElement* newElems = new TElement[A.capacity];
        for(int i = 1; i<= A.size(); i++)
            newElems[i] = A.getArray()[i];

        this->elems = newElems;
        this->n = A.n;
        this->capacity = A.capacity;
        return *this;
    }

    DynamicArray(const DynamicArray &A) { //Copy

        TElement* newElems = new TElement[A.capacity];
        for(int i = 1; i<= A.n; i++)
            newElems[i] = A.elems[i];

        this->elems = newElems;
        this->n = A.n;
        this->capacity = A.capacity;
    }


    DynamicArray operator+(const TElement& b) {
        DynamicArray newDyn;

        newDyn.capacity = this->capacity;
        for(int i = 1; i<= this->n; i++)
            newDyn.push_back(this->get(i));

        newDyn.push_back(b);

        return newDyn;
    }

};

template<class TElement>
DynamicArray<TElement> operator+(TElement a, DynamicArray<TElement> b) {

    DynamicArray<TElement> newDyn;

    for(int i = 1; i<= b.size(); i++)
        newDyn.push_back(b.get(i));

    newDyn.push_back(a);
    return newDyn;
}




#endif //LAB5_6_DYNAMICARRAY_H
