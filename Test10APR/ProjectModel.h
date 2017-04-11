//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#ifndef TEST10APR_PROJECTMODEL_H
#define TEST10APR_PROJECTMODEL_H
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


class ProjectModel {
private:
    string name;
    string customer;
    string dueDate;
    int cost;
    bool isDone;
public:
    int day, year, month;
public:
    ProjectModel();
    ProjectModel(string name, string customer, string dueDate, int cost, bool isDone);
    ProjectModel(string name, string customer);


    string getName();
    void setName(string name);

    string getCustomer();
    void setCustomer(string customer);

    string getDueDate();
    void setDueDate(string date);

    int getCost();
    void setCost(int cost);

    bool getIsDone();
    void setIsDone(bool ok);



};


#endif //TEST10APR_PROJECTMODEL_H
