//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#include <fstream>
#include "Repository.h"

Repository::Repository() {
    this->populateFromFile();
}

void Repository::populateFromFile() {
    ifstream fin("data.txt");
    string crtLine;
    string hourStartS, hourEndS, temperatureS, precipitationProbabilityS, descriptionS;

    while(!fin.eof()) {
        //Empty those stuff
        crtLine.erase(crtLine.begin(), crtLine.end());
        hourStartS.erase(hourStartS.begin(), hourStartS.end());
        hourEndS.erase(hourEndS.begin(), hourEndS.end());
        temperatureS.erase(temperatureS.begin(), temperatureS.end());
        precipitationProbabilityS.erase(precipitationProbabilityS.begin(), precipitationProbabilityS.end());
        descriptionS.erase(descriptionS.begin(), descriptionS.end());


        //Read
        getline(fin, crtLine);

        int nrSep = 0;
        for(int i = 0; i < crtLine.size(); i++) {
            if(crtLine[i] == ';') {
                nrSep++;
                continue;
            }

            switch(nrSep) {
                case 0:
                    hourStartS += crtLine[i];
                    break;
                case 1:
                    hourEndS += crtLine[i];
                    break;
                case 2:
                    temperatureS += crtLine[i];
                    break;
                case 3:
                    precipitationProbabilityS += crtLine[i];
                    break;
                case 4:
                    descriptionS += crtLine[i];
                    break;
            }
        }

        //Push back the result
        this->list.push_back(Weather(stoi(hourStartS), stoi(hourEndS), stoi(temperatureS), stoi(precipitationProbabilityS), descriptionS));
    }

    cout<<this->list.size();
}

int Repository::getSize() {
    return (int) this->list.size();
}

Weather Repository::getElemetFromPosition(int pos) {
    return this->list[pos];
}

int Repository::computeHoursByDescription(string description) {
    int hours = 0;
    for(int i = 0; i < this->list.size(); i++) {
        if(this->list[i].getDescription() == description)
            hours += (this->list[i].getHourEnd() - this->list[i].getHourStart());
    }

    return hours;
}

void Repository::setElementToPosition(Weather weather, int pos) {
    this->list[pos] = weather;
}


