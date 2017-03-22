//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_UI_H
#define LAB5_6_UI_H
#include "MovieController.h"

class UI {
private:
    MovieController movieController;

public:

    //Constructors
    UI();

    //Getters
    MovieController & getMovieController();

    //Functionality
    void printAdminUI();
    void printUserUI();
    void getInput();
    bool checkCommand(int cmd);

    //Admin area
    void add();
    void del();
    void update();
    void list();

};


#endif //LAB5_6_UI_H
