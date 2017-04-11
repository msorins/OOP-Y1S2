//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#ifndef TEST10APR_UI_H
#define TEST10APR_UI_H
#include "ProjectController.h"

class UI {
public:
    ProjectController pc;
public:
    UI();
    UI(ProjectController pc);

    void insertData();

    void printMenu();
    int getCommand();
    void checkCommand(int cmd);
    void executeCommand(int cmd);


    void addProject();
    void printAllProjects();
    void markProjectFinished();
    void printTotalCostOfFinished();
    void printSortedByDueDate();

};


#endif //TEST10APR_UI_H
