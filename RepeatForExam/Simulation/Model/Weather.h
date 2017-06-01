//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#ifndef SIMULATION_WEATHER_H
#define SIMULATION_WEATHER_H
#include <iostream>
#include <string>
using namespace std;

class Weather {
private:
    int hourStart, hourEnd, temperature, precipitationProbability;
    string description;

public:
    //Constructor
    Weather(int hourStart, int hourEnd, int temperature, int precipitationProbability, const string &description);

    //Getters and setters
    int getHourStart() const;

    void setHourStart(int hourStart);

    int getHourEnd() const;

    void setHourEnd(int hourEnd);

    int getTemperature() const;

    void setTemperature(int temperature);

    int getPrecipitationProbability() const;

    void setPrecipitationProbability(int precipitationProbability);

    const string &getDescription() const;

    void setDescription(const string &description);
};


#endif //SIMULATION_WEATHER_H
