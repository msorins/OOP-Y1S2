//
// Created by z003swax on 11.04.2017.
//

#ifndef LAB5_6_STLVECTOR_H
#define LAB5_6_STLVECTOR_H

#include <vector>
#include "IDynamicArray.h"

template<class TElement>
class STLVector: IDynamicArray<TElement> {
protected:
    vector<TElement> elems;

public:
    //Constructors and Destructors
    ~STLVector();

    //Functionality
    void push_back(TElement elem);
    void erase(int pos);
    void resize();
    TElement get(int pos);
    int find(TElement elem);
    void insert(TElement element, int pos);
    void validatePosition(int position);

    //Getters
    virtual int size();
    virtual TElement* getArray();

    //ForIterators
    TElement * begin();
    TElement * end();
};




#endif //LAB5_6_STLVECTOR_H
