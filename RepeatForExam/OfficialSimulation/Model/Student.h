//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#ifndef WTM_STUDENT_H
#define WTM_STUDENT_H

#include <iostream>
#include <string>
using namespace std;


class Student {
private:
    int id;
    string name;
    int group;
    double grade;
    string nameOfTeacher;

public:
    //Constructor
    Student();
    Student(int id, string &name, int group, double grade, string &nameOfTeacher);

    //Setters and getters
    int getId();
    void setId(int id);
    string &getName() ;
    void setName(string &name);
    int getGroup() ;
    void setGroup(int group);
    double getGrade() ;
    void setGrade(double grade);
     string &getNameOfTeacher() ;
    void setNameOfTeacher( string &nameOfTeacher);
};


#endif //WTM_STUDENT_H
