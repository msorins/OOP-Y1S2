//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#ifndef INC_03COMPOSITE_RECTANGLE_H
#define INC_03COMPOSITE_RECTANGLE_H


#include "IGraphic.h"
#include <iostream>
#include <string>
using namespace std;

class Rectangle: public IGraphic {
public:
    string name;
public:
    Rectangle(const string &name);

    void draw() override;
};


#endif //INC_03COMPOSITE_RECTANGLE_H
