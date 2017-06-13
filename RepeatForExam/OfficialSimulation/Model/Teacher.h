//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#ifndef WTM_TEACHER_H
#define WTM_TEACHER_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Teacher {
private:
    string name;
    vector<int> groups;

public:
    //ructors
    Teacher(string name);
    
    //Getters and setters
    string getName() ;
    void setName( string name);
    vector<int> getGroups() ;

    //Functionality
    void addGroup(int group);

};


#endif //WTM_TEACHER_H
