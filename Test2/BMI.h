//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#ifndef TEST2_BMI_H
#define TEST2_BMI_H


#include "MedicalAnalysis.h"

class BMI: public MedicalAnalysis {
private:
    double value;
public:
    //Constructor
    BMI(Date date, double value);

    //Getters and Setters
    double getValue();
    void setValue(double value);

    //Functionality
    bool isResultOk() override;
    string toString() override;
};


#endif //TEST2_BMI_H
