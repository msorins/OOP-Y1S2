//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#ifndef TEST2_PERSON_H
#define TEST2_PERSON_H
#include <vector>
#include <iostream>
#include "MedicalAnalysis.h"
#include "Date.h"
using namespace std;


class Person {
protected:
    vector<MedicalAnalysis*> v;
public:
    //Constructor
    Person();

    //Functionality
    void addAnalysis(MedicalAnalysis* a);
    vector<MedicalAnalysis*> getAllAnalyses();
    vector<MedicalAnalysis*> getAnalysesByMonth(int month);
    bool isHealthy(int month);
    vector<MedicalAnalysis*> getAnalysesNewerThan(Date date);
    void writeToFile(string file, Date date);
};


#endif //TEST2_PERSON_H
