//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#ifndef INC_02ADAPTER_RECTANGLEADAPTER_H
#define INC_02ADAPTER_RECTANGLEADAPTER_H


#include "../New/INewRectangle.h"
#include "../Old/OldRectangle.h"

class RectangleAdapter: public INewRectangle, private OldRectangle {
public:
    //Constructor
    RectangleAdapter(int x0, int y0, int w, int h);

    //Override the INewRectangle interfacce
    void newDraw() override;
};


#endif //INC_02ADAPTER_RECTANGLEADAPTER_H
