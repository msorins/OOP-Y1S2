//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "MedicalAnalysis.h"

Date MedicalAnalysis::getDate()  {
    return date;
}

void MedicalAnalysis::setDate(const Date &date) {
    MedicalAnalysis::date = date;
}

MedicalAnalysis::MedicalAnalysis(const Date &date) : date(date) {}
