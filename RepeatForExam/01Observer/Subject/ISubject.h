//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#ifndef INC_01OBSERVER_ISUBJECT_H
#define INC_01OBSERVER_ISUBJECT_H


#include "../Observer/IObserver.h"
#include <vector>
#include <iostream>
using namespace std;

class ISubject {
private:
    vector<IObserver *> list;

public:
    void attach(IObserver *product);
    void detach(IObserver *product);
    void notify(int price);
};


#endif //INC_01OBSERVER_ISUBJECT_H
