//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#ifndef INC_03COMPOSITE_LINE_H
#define INC_03COMPOSITE_LINE_H

#include "IGraphic.h"
#include <iostream>
#include <string>
using namespace std;

class Line: public IGraphic {
public:
    string name;
public:
    Line(const string &name);

    void draw() override;
};


#endif //INC_03COMPOSITE_LINE_H
