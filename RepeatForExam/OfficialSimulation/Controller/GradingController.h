//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#ifndef WTM_GRADINGCONTROLLER_H
#define WTM_GRADINGCONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include "../Repository/StudentsRepository.h"
#include "../Repository/TeachersRepository.h"


using namespace std;

class GradingController {

private:
    StudentsRepository *studentRepo;
    TeachersRepository *teacherRepo;

public:
    GradingController(StudentsRepository *gradingRepo, TeachersRepository *teachersRepo);

    //Get Stuff
    StudentsRepository *getStudentsRepo();
    TeachersRepository *getTeachersRepo();

    //Main teacher
    void addStudent(string name, int group);
    void removStudentFromPosition(int pos);

    //Mini teachers
    void gradeStudentFromPosition(string nameOfTeacher, int pos, double grade);
};


#endif //WTM_GRADINGCONTROLLER_H
