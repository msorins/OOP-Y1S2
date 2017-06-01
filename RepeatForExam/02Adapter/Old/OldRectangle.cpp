//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#include "OldRectangle.h"
#include <iostream>
using namespace std;

//Constructor
OldRectangle::OldRectangle(): _x1{0}, _y1{0}, _x2{0}, _y2{0} {}

OldRectangle::OldRectangle(int x1, int y1, int x2, int y2) : _x1{x1}, _y1{y1}, _x2{x2}, _y2{y2} {
    cout<<"Old rectangle created. (" << x1 << ", " << y1 << ", "<< x2 <<", "<<y2<<")\n";
}

//Functionality
void OldRectangle::oldDraw() {
    cout<<"Old draw: " << this->_x1 << " " << this->_y1 << this->_x2<<" "<< this->_y2<<"\n";
}



