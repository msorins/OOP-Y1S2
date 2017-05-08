//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#ifndef TEST2_BP_H
#define TEST2_BP_H


#include "MedicalAnalysis.h"
#include "Date.h"

class BP: public MedicalAnalysis {
private:
    int systolicValue;
    int diastolicValue;
public:
    //Constructor
    BP(Date date, int sys, int dias);

    //Getters and Setters
    int getSystolicValue();
    void setSystolicValue(int systolicValue);
    int getDiastolicValue();
    void setDiastolicValue(int diastolicValue);

    //Functionality
    bool isResultOk() override;
    string toString() override;
};


#endif //TEST2_BP_H
