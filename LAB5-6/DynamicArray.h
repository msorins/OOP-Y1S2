//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//
#pragma once
#ifndef LAB5_6_DYNAMICARRAY_H
#define LAB5_6_DYNAMICARRAY_H
#include <iostream>
using namespace std;

template<class TElement>
class DynamicArray {
protected:
    TElement* elems;
private:
    int n;
    int capacity;

public:
    //Constructors and Destructors
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
    int getLength();
    TElement* getArray();

    //Operators
    DynamicArray& operator = (DynamicArray A ) {
        TElement* newElems = new TElement[A.capacity];
        for(int i = 1; i<= A.getLength(); i++)
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



};



#endif //LAB5_6_DYNAMICARRAY_H