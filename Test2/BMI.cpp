//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "BMI.h"

double BMI::getValue(){
    /*
     * Getter for the value
     */
    return value;
}

void BMI::setValue(double value) {
    /*
     * Setter for the valie
     */
    BMI::value = value;
}

bool BMI::isResultOk() {
    /*
     * Returns true if the current analysis is OK. False otherwise
     */
    if(this->value >= 18.5 && this->value <= 25)
        return true;
    return false;
}

string BMI::toString() {
    /*
     * Formats to string the current analysis
     */
    string res;
    res = "BMI: " + to_string(this->value);
    res += "( " + to_string(this->getDate().year) + "." + to_string(this->getDate().month) + "." + to_string(this->getDate().day) + ")";
    return res;
}

BMI::BMI(Date date, double value): MedicalAnalysis(date) {
    /*
     * CONSTRUCTOR
     */
    this->setDate(date);
    this->value = value;

}
