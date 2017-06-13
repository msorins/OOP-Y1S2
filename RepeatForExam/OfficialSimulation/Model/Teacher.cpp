//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#include "Teacher.h"

Teacher::Teacher(string name) : name(name) {}

 string Teacher::getName()  {
    return name;
}

void Teacher::setName( string name) {
    this->name = name;
}

 vector<int> Teacher::getGroups()  {
    return this->groups;
}

void Teacher::addGroup(int group) {
    this->groups.push_back(group);
}
