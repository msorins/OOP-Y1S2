//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#ifndef INC_03COMPOSITE_PICTURE_H
#define INC_03COMPOSITE_PICTURE_H


#include "IGraphic.h"
#include <iostream>
#include <vector>
using namespace std;

class Picture: public IGraphic {
public:
    string name;
    vector<IGraphic*> gList;

public:
    Picture(const string &name);

    void draw() override;
    void add(IGraphic *comp) override;
    void remove(IGraphic *comp) override;
};


#endif //INC_03COMPOSITE_PICTURE_H
