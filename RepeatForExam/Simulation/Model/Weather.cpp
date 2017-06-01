//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#include "Weather.h"

Weather::Weather(int hourStart, int hourEnd, int temperature, int precipitationProbability, const string &description)
        : hourStart(hourStart), hourEnd(hourEnd), temperature(temperature),
          precipitationProbability(precipitationProbability), description(description) {}

int Weather::getHourStart() const {
    return hourStart;
}

void Weather::setHourStart(int hourStart) {
    Weather::hourStart = hourStart;
}

int Weather::getHourEnd() const {
    return hourEnd;
}

void Weather::setHourEnd(int hourEnd) {
    Weather::hourEnd = hourEnd;
}

int Weather::getTemperature() const {
    return temperature;
}

void Weather::setTemperature(int temperature) {
    Weather::temperature = temperature;
}

int Weather::getPrecipitationProbability() const {
    return precipitationProbability;
}

void Weather::setPrecipitationProbability(int precipitationProbability) {
    Weather::precipitationProbability = precipitationProbability;
}

const string &Weather::getDescription() const {
    return description;
}

void Weather::setDescription(const string &description) {
    Weather::description = description;
}
