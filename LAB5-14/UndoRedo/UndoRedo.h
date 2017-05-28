//
// Created by Sorin Sebastian Mircea on 24/05/2017.
//

#ifndef LAB5_6_UNDO_H
#define LAB5_6_UNDO_H


template<class TRepo>
class UndoRedo {
public:
    //Virtual destructor
    virtual ~UndoRedo() {};

    //Functionality
    virtual void executeUndo() = 0;
    virtual void executeRedo() = 0;
};


#endif //LAB5_6_UNDO_H
