//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#include "TeachersRepository.h"

TeachersRepository::TeachersRepository() {
    this->load();
}

TeachersRepository::~TeachersRepository() {

}

int TeachersRepository::getSize() {
    return (int) this->teachersList.size();
}

vector<Teacher> TeachersRepository::getTeacherList() {
    return this->teachersList;
}

void TeachersRepository::load() {
    ifstream in("teachers.in");

    string line, name, id;
    int crt;

    while(!in.eof()) {
        string line;
        getline(in, line);

        name.erase(name.begin(), name.end());
        id.erase(id.begin(), id.end());

        int i = 0;
        while(line[i] != ';')
            name+=line[i], i++;

        Teacher teacher(name);
        for(; i < line.size(); i++) {
            if(line[i] == ';') {
                teacher.addGroup(atoi(id.c_str()));
                id.erase(id.begin(), id.end());
                continue;
            }

            id += line[i];
        }
        this->add(teacher);
    }
}

void TeachersRepository::save() {

}

void TeachersRepository::add(Teacher s) {
    this->teachersList.push_back(s);
}
