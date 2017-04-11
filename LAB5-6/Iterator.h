//
// Created by Sorin Sebastian Mircea on 11/04/2017.
//

#ifndef LAB5_6_ITERATOR_H
#define LAB5_6_ITERATOR_H
#include <iostream>
using namespace std;

template<class TElement>
class Iterator : public std::iterator<input_iterator_tag, TElement>
{
    TElement* p;
public:
    Iterator(TElement* x) :p(x) {

    }

    Iterator(const Iterator& mit) : p(mit.p) {

    }

    Iterator& operator++() {
        ++p;
        return *this;
    }


    Iterator operator++(int) {
        Iterator tmp(*this);
        operator++();
        return tmp;
    }

    bool operator==(const Iterator& rhs) {
        return p==rhs.p;
    }

    bool operator!=(const Iterator& rhs) {
        return p!=rhs.p;
    }

    TElement& operator*() {
        return *p;
    }
};


#endif //LAB5_6_ITERATOR_H
