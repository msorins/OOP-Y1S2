//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#include "Rectangle.h"

void Rectangle::draw() {
    cout<<"draw a rectangle " << this->name<<"\n";
}

Rectangle::Rectangle(const string &name) : name(name) {}
