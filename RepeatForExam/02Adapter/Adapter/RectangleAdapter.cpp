//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#include "RectangleAdapter.h"
#include <iostream>
using namespace std;

//Constructor also calls the old object constructor
RectangleAdapter::RectangleAdapter(int x0, int y0, int w, int h) : OldRectangle(x0, y0, x0 + w, y0 + h) {
    cout<<"New rectangle created. (" << x0 << ", " << y0 << ",w: "<< w <<",h: "<<h<<")\n";
}

void RectangleAdapter::newDraw() {
    cout<<"New draW ";
    this->oldDraw();
}
