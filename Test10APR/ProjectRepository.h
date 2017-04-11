//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#ifndef TEST10APR_PROJECTREPOSITORY_H
#define TEST10APR_PROJECTREPOSITORY_H
#include <iostream>
#include <vector>
#include "ProjectModel.h"
using namespace std;

class ProjectRepository {
private:
    vector<ProjectModel>  projects;
public:
    void addProject(ProjectModel proj);
    void markProjectFinished(ProjectModel proj);
    vector<ProjectModel> getAllProjects();
    vector<ProjectModel> sortedUnfinishedByDueDate();
    int totalCostOfFinished();
    int getProjectPosition(ProjectModel proj);
    ProjectModel getProject(int pos);
};


#endif //TEST10APR_PROJECTREPOSITORY_H
