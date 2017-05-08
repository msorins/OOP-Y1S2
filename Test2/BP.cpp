//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "BP.h"
#include <iostream>
#include <string>
using namespace std;

int BP::getSystolicValue(){
    /*
     * Getter for the systolicValue
     */
    return systolicValue;
}

void BP::setSystolicValue(int systolicValue) {
    /*
     * Setter for the systolic Value
     */
    BP::systolicValue = systolicValue;
}

int BP::getDiastolicValue() {
    /*
     * Getter for the diastolicValue
     */
    return diastolicValue;
}

void BP::setDiastolicValue(int diastolicValue) {
    /*
     * Setter for the diastolic value
     */
    BP::diastolicValue = diastolicValue;
}

bool BP::isResultOk() {
    /*
     * Returns a boolean indicating if the current analysis si ok or not
     */
    if(this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue>=60 && this->diastolicValue <= 79)
        return true;
    return false;
}

string BP::toString() {
    /*
     * Formats the current analysis to string
     */
    string res;
    res += "BP: Systolic value: " + to_string(this->systolicValue) + ". DiastolicValue: " + to_string(this->diastolicValue);
    res += "( " + to_string(this->getDate().year) + "." + to_string(this->getDate().month) + "." + to_string(this->getDate().day) + ")";
    return res;
}

BP::BP(Date date, int sys, int dias): MedicalAnalysis(date) {
    /*
     * CONSTRUCTOR
     */
    this->setDate(date);
    this->systolicValue = sys;
    this->diastolicValue = dias;
}
