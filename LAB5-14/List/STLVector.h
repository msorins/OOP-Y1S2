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

    STLVector operator+(const TElement& b) {
        STLVector newVector;

        for(int i = 0; i < this->elems.size(); i++)
            newVector.elems.push_back(this->elems[i]);

        newVector.push_back(b);

        return newVector;
    }

};

template<class TElement>
STLVector<TElement> operator+(TElement a, STLVector<TElement> b) {

    STLVector<TElement> newVector;

    for(int i = 0; i < b.elems.size(); i++)
        newVector.elems.push_back(b.elems[i]);

    newVector.push_back(a);

    return newVector;
}






#endif //LAB5_6_STLVECTOR_H
