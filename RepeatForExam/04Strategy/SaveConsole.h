//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#ifndef INC_04STRATEGY_SAVECONSOLE_H
#define INC_04STRATEGY_SAVECONSOLE_H


#include "ISave.h"
#include <iostream>
using namespace std;

class SaveConsole: public ISave {
public:
    string msg;

public:
    SaveConsole(string msg);
    void save() override;
};


#endif //INC_04STRATEGY_SAVECONSOLE_H
