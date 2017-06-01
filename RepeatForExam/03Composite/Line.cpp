//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#include "Line.h"

void Line::draw() {
    cout<<"draw a line: " << this->name<<"\n";
}

Line::Line(const string &name) : name(name) {}
