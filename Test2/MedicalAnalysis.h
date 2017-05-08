//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#ifndef TEST2_MEDICALANALYSIS_H
#define TEST2_MEDICALANALYSIS_H

#include <string>
#include <iostream>
using namespace std;
#include "Date.h"

class MedicalAnalysis {
private:
    Date date;
public:
    MedicalAnalysis(const Date &date);

    //Getters and setters
    Date getDate();
    void setDate(const Date &date);

public:
    virtual bool isResultOk() = 0;
    virtual string toString() = 0;
};


#endif //TEST2_MEDICALANALYSIS_H
