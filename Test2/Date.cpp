//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "Date.h"
#include "Exception.h"
#include <string>
#include <iostream>
using namespace std;

Date::Date(string date) {
    string a;

    if(date.size() != 10) {
        throw Exception("Invalid date");
    }

    if(date[4] != '.' || date[7] != '.') {
        throw Exception("Invalid date");
    }
    this->day= stoi(date.substr(8,2));
    this->month= stoi(date.substr(5,2));
    this->year= stoi(date.substr(0,4));

    if(this->month > 12){
        throw Exception("Invalid month");
    }

    if(this->day > 33) {
        throw Exception("Invalid day");
    }
}
