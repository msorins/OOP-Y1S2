//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#ifndef WTM_GRADINGREPOSITORY_H
#define WTM_GRADINGREPOSITORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include "../Model/Student.h"

using namespace std;

class StudentsRepository {
private:
    vector<Student> teachersList;

public:
    //Constructor
    StudentsRepository();

    //Destructor
    virtual ~StudentsRepository();

    //Get studd
    int getSize();
    vector<Student> getTeacherList();

    //Load and save
    void load();
    void save();

    void add(Student s);
    int find(Student s);
    void removeByPosition(int pos);

    int getNewId();

    Student getStudentByPosition(int pos);
    void setStudentFromPosition(int pos, Student student);
};


#endif //WTM_GRADINGREPOSITORY_H
