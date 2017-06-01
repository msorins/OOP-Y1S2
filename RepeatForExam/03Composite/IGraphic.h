//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#ifndef INC_03COMPOSITE_GRAPHIC_H
#define INC_03COMPOSITE_GRAPHIC_H


class IGraphic {
public:
    //Pure virtual
    virtual void draw() = 0;

    //Virtual but has empty implementations here
    virtual void add(IGraphic *comp) {};
    virtual void remove(IGraphic *comp) {};
    virtual ~IGraphic() {};
};


#endif //INC_03COMPOSITE_GRAPHIC_H
