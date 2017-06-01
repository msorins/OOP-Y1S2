//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#ifndef INC_02ADAPTER_OLDCLASS_H
#define INC_02ADAPTER_OLDCLASS_H


class OldRectangle {
private:
    int _x1, _y1;
    int _x2, _y2;

public:
    //Constructor
    OldRectangle();
    OldRectangle(int x1, int y1, int x2, int y2);

    //Functionality
    void oldDraw();
};


#endif //INC_02ADAPTER_OLDCLASS_H
