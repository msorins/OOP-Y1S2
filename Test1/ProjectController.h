//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#ifndef TEST10APR_PROJECTCONTROLLER_H
#define TEST10APR_PROJECTCONTROLLER_H
#include "ProjectRepository.h"

class ProjectController {
private:
    ProjectRepository projRepo;
public:
    ProjectController();
    ProjectController(ProjectRepository projRepo);

    void addProject(string name, string customer, string dueDate, int cost, bool isDone);
    vector<ProjectModel> getAllProjects();
    void markProjectFinished(string name, string customer);
    int totalCostOfFinished();
    vector<ProjectModel> sortedUnfinishedByDueDate();
};


#endif //TEST10APR_PROJECTCONTROLLER_H
