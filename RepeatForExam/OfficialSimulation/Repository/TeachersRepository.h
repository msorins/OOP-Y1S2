//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//


#include <iostream>
#include <fstream>
#include <vector>
#include "../Model/Teacher.h"


using namespace std;

class TeachersRepository {
private:
    vector<Teacher> teachersList;

public:
    //Constructor
    TeachersRepository();

    //Destructor
    virtual ~TeachersRepository();

    //Get studd
    int getSize();
    vector<Teacher> getTeacherList();

    //Load and save
    void load();
    void save();

    void add(Teacher s);
};

