//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "Person.h"
#include <fstream>

Person::Person() {

}

void Person::addAnalysis(MedicalAnalysis *a) {
    /*
     * Adds a new analysis
     */
    this->v.push_back(a);
}

vector<MedicalAnalysis *> Person::getAllAnalyses() {
    /*
     * Returns a vector with all the analyses
     */
    return this->v;
}

vector<MedicalAnalysis *> Person::getAnalysesByMonth(int month) {
    /*
     * Returns all analyses from a given month
     */
    vector<MedicalAnalysis *> res;

    for(int i = 0; i < this->v.size(); i++) {
        if(this->v[i]->getDate().month == month)
            res.push_back(this->v[i]);
    }

    return res;
}

bool Person::isHealthy(int month) {
    /*
     * Returns a boolean value indicating if a person is healthy or not
     */
    bool healthy = true;

    for(int i = max(1, month - 1); i<= month; i++) {
        vector<MedicalAnalysis *> crtMonth = this->getAnalysesByMonth(i);
        for(int j = 0; j< crtMonth.size(); j++) {

            //Must be from current year
            if(crtMonth[j]->getDate().year != 2017)
                continue;

            if(!crtMonth[j]->isResultOk())
                healthy = false;
        }
    }

    return healthy;
}

vector<MedicalAnalysis *> Person::getAnalysesNewerThan(Date date) {
    /*
     * Returns all analysus newer than a given date
     */
    vector<MedicalAnalysis *> res;

    for(int i = 0; i < this->v.size(); i++) {
        if(this->v[i]->getDate().year > date.year ||
                (this->v[i]->getDate().year ==  date.year && this->v[i]->getDate().month >  date.month) ||
                (this->v[i]->getDate().year ==  date.year && this->v[i]->getDate().month ==  date.month && this->v[i]->getDate().day > date.day))
            res.push_back(this->v[i]);

    }

    return res;
}

void Person::writeToFile(string file, Date date) {
    /*
     * Write to file all analyss newer than a given date
     */
    ofstream out(file);

    vector<MedicalAnalysis *> elements = this->getAnalysesNewerThan(date);
    for(int i = 0; i < elements.size(); i++) {
        out<<elements[i]->toString()<<"\n";
    }

}
