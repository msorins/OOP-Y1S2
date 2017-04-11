//
// Created by Sorin Sebastian Mircea on 09/04/2017.
//
#pragma once
#include <iostream>
using namespace std;

template<class TElement>
class DynamicArray {
protected:
    TElement* elems;
    int n;
    int capacity;

public:
    //Constructors and destructors
    DynamicArray();
    DynamicArray(TElement t);
    ~DynamicArray();

    //Functionality
    void push_back(TElement t);
    void erase(int pos);
    void resize();
    int find(TElement t);
    void insert(TElement t, int pos);
    void validatePosition(int position);

    //getters
    int getLength();
    TElement* getArray();


    //Overriding Operators

    //=
    DynamicArray& operator = (DynamicArray &A) {
        TElement* newElems = new TElement[A.capacity];
        for(int i = 1; i<= A.getLength(); i++)
            newElems[i] = A.getArray()[i];

        this->elems = newElems;
        this->n = A.n;
        this->capacity = A.capacity;

        return *this;
    }

    //Copy operator
    DynamicArray(const DynamicArray &A) {
        TElement* newElems = new TElement[A.capacity];
        for(int i = 1; i <= A.n; i++)
            newElems[i] = A.elems[i];

        this->elems = newElems;
        this->n = A.n;
        this->capacity = A.capacity;
    }
};

