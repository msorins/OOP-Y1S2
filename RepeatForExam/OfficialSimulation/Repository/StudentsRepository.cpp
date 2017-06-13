//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#include "StudentsRepository.h"

StudentsRepository::StudentsRepository() {
    this->load();
}

void StudentsRepository::load() {
    ifstream in("students.txt");

    string idS;
    string nameS;
    string groupS;
    string gradeS;
    string nameOfTeacherS;

    while(!in.eof()) {
        string line;
        getline(in, line);

        int separator = 0;
        idS.erase(idS.begin(), idS.end());
        nameS.erase(nameS.begin(), nameS.end());
        groupS.erase(groupS.begin(), groupS.end());
        gradeS.erase(gradeS.begin(), gradeS.end());
        nameOfTeacherS.erase(nameOfTeacherS.begin(), nameOfTeacherS.end());

        for(int i = 0; i < line.size(); i++) {
            if(line[i] == ';') {
                separator++;
                continue;
            }

            if(line[i] == ' ') {
                continue;
            }

            switch(separator) {
                case 0:
                    idS += line[i];
                    break;
                case 1:
                    nameS += line[i];
                    break;
                case 2:
                    groupS += line[i];
                    break;
                case 3:
                    gradeS += line[i];
                    break;
                case 4:
                    nameOfTeacherS += line[i];
                    break;
            }
        }


        this->add(Student(stoi(idS), nameS, stoi(groupS), stod(gradeS), nameOfTeacherS));
    }
}

void StudentsRepository::save() {
    ofstream out("students.txt");

    for(int i = 0; i < this->teachersList.size(); i++) {
        out<<this->teachersList[i].getId()<<";"<<this->teachersList[i].getName()<<";"<<this->teachersList[i].getGroup()<<";"<<this->teachersList[i].getGrade()<<";"<<this->teachersList[i].getNameOfTeacher();
        if(i < this->teachersList.size() -1 )
            cout<<"\n";
    }
}

void StudentsRepository::add(Student s) {
    this->teachersList.push_back(s);
}

void StudentsRepository::removeByPosition(int pos) {
    this->teachersList.erase(this->teachersList.begin() + pos);
}

int StudentsRepository::find(Student s) {
    for(int i = 0; i < this->teachersList.size(); i++)
        if(this->teachersList[i].getName() == s.getName())
            return i;

    return -1;
}

StudentsRepository::~StudentsRepository() {
    this->save();
}

int StudentsRepository::getSize() {
    return this->teachersList.size();
}

vector<Student> StudentsRepository::getTeacherList() {
   return this->teachersList;
}

int StudentsRepository::getNewId() {
    int startingId = (int) this->teachersList.size();

    bool ok;
    while(true) {
        ok = true;

        for(int i = 0; i < this->teachersList.size(); i++)
            if(this->teachersList[i].getId() == startingId)
                ok = false;

        if(ok)
            break;

    }

    return startingId;
}

Student StudentsRepository::getStudentByPosition(int pos) {
    return this->teachersList[pos];
}

void StudentsRepository::setStudentFromPosition(int pos, Student student) {
    this->teachersList[pos] = student;
}


