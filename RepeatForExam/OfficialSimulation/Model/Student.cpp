//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#include "Student.h"

Student::Student(int id,  string &name, int group, double grade,  string &nameOfTeacher) : id(id), name(name),
                                                                                                     group(group),
                                                                                                     grade(grade),
                                                                                                     nameOfTeacher(nameOfTeacher) {}

int Student::getId()  {
    return id;
}

void Student::setId(int id) {
    Student::id = id;
}

 string &Student::getName()  {
    return name;
}

void Student::setName( string &name) {
    Student::name = name;
}

int Student::getGroup()  {
    return group;
}

void Student::setGroup(int group) {
    Student::group = group;
}

double Student::getGrade()  {
    return grade;
}

void Student::setGrade(double grade) {
    Student::grade = grade;
}

 string &Student::getNameOfTeacher()  {
    return nameOfTeacher;
}

void Student::setNameOfTeacher( string &nameOfTeacher) {
    Student::nameOfTeacher = nameOfTeacher;
}

Student::Student() {
    this->id = NULL;
    this->grade = NULL;
}


