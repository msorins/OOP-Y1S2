//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//
#pragma once
#ifndef LAB5_6_DYNAMICARRAY_H
#define LAB5_6_DYNAMICARRAY_H
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
    TElement find(TElement elem);
    void insert(TElement element, int pos);
    void validatePosition(int position);

    //Getters
    int getLength();
    TElement* getArray();

};



#endif //LAB5_6_DYNAMICARRAY_H
