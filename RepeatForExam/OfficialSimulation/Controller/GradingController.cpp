//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#include "GradingController.h"

GradingController::GradingController(StudentsRepository *gradingRepo, TeachersRepository *teachersRepository) : studentRepo(gradingRepo), teacherRepo{teachersRepository} { }

void GradingController::addStudent(string name, int group) {
    int newId = this->studentRepo->getNewId();
    string teachersName;

    this->studentRepo->add(Student(newId, name, group, 1.0, teachersName));
}

void GradingController::removStudentFromPosition(int pos) {
    this->studentRepo->removeByPosition(pos);
}

void GradingController::gradeStudentFromPosition(string nameOfTeacher, int pos, double grade) {
    Student student = this->studentRepo->getStudentByPosition(pos);

    if(!student.getNameOfTeacher().empty() && student.getNameOfTeacher() != nameOfTeacher)
        throw("Student already graded by other teacher");

    student.setGrade(grade);
    student.setNameOfTeacher(nameOfTeacher);

    this->studentRepo->setStudentFromPosition(pos, student);
}

StudentsRepository *GradingController::getStudentsRepo() {
    return this->studentRepo;
}

TeachersRepository *GradingController::getTeachersRepo() {
    return this->teacherRepo;
}
