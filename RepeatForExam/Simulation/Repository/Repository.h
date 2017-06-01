//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#ifndef SIMULATION_REPOSITORY_H
#define SIMULATION_REPOSITORY_H
#include <iostream>
#include <vector>
#include <string>
#include "../Model/Weather.h"

using namespace std;

class Repository {
private:
    vector<Weather> list;

public:
    //Constructor
    Repository();

    //Functionality
    void populateFromFile();
    int getSize();
    Weather getElemetFromPosition(int pos);
    void setElementToPosition(Weather weather, int pos);
    int computeHoursByDescription(string description);

};


#endif //SIMULATION_REPOSITORY_H
