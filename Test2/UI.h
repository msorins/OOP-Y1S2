//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#ifndef TEST2_UI_H
#define TEST2_UI_H
#include "Person.h"

class UI {
private:
    Person p;
public:
    //Constructor
    UI(Person p);

    //Functionality
    void writeMenu();
    void parseCommand();
    void addAnalysis();
    void amIHealthy();
    void saveToFile();
    void showAll();

};


#endif //TEST2_UI_H
