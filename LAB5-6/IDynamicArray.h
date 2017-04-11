//
// Created by z003swax on 11.04.2017.
//

#include "WatchListItem.h"
#include "Movie.h"

#ifndef LAB5_6_IDYNAMICARRAY_H
#define LAB5_6_IDYNAMICARRAY_H

template<class TElement>
class IDynamicArray {
public:
    //Constructors and Destructors
    virtual ~IDynamicArray() = 0;

    //Functionality
    virtual void push_back(TElement elem) = 0;
    virtual void erase(int pos) = 0;
    virtual void resize() = 0;
    virtual TElement get(int pos) = 0;
    virtual int find(TElement elem) = 0;
    virtual void insert(TElement element, int pos) = 0;
    virtual void validatePosition(int position) = 0;

    //Getters
    virtual int getLength() = 0;
    virtual TElement* getArray() = 0;
};


#endif //LAB5_6_IDYNAMICARRAY_H
