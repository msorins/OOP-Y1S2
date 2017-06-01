//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#ifndef INC_01OBSERVER_ACTIONSUBJECT_H
#define INC_01OBSERVER_ACTIONSUBJECT_H


#include "ISubject.h"

class ActionSubject: public ISubject {
private:
    string actionProduct;

public:
    ActionSubject(string actionProduct);
};


#endif //INC_01OBSERVER_ACTIONSUBJECT_H
