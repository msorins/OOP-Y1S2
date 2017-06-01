//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#ifndef INC_04STRATEGY_SAVEFILE_H
#define INC_04STRATEGY_SAVEFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include "ISave.h"

using namespace std;

class SaveFile: public ISave {
public:
    string msg;

public:
    SaveFile(const string &msg);

private:
    void save() override;
};


#endif //INC_04STRATEGY_SAVEFILE_H
