//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#include "ProjectRepository.h"

void ProjectRepository::addProject(ProjectModel proj) {
    /*
     * Adds a new project
     * Check if the projects exists, and if does throw an error
     */

    int pos = this->getProjectPosition(proj);
    if(pos != -1)
        throw("Project already exists");


    this->projects.push_back(proj);
}

void ProjectRepository::markProjectFinished(ProjectModel proj) {
    /*
     * Simply marks a project as finished. It is not found throw an error
     */

    //Get the position
    int pos = this->getProjectPosition(proj);
    if(pos == -1)
        throw("Project not found");

    //Check if the project is not marked as doen alreayd
    if(this->projects[pos].getIsDone())
        throw("Project is already marked as done");

    //Mark it as done
    this->projects[pos].setIsDone(true);
}

vector<ProjectModel> ProjectRepository::getAllProjects() {
    /*
     * Getter for the repository
     */
    return this->projects;
}

vector<ProjectModel> ProjectRepository::sortedUnfinishedByDueDate() {
    /*
     * Sorts just unfinished movie bye due date
     * RETURNS A VECTOR OF PROJECTMODEL THAT IS ALREADY SORTED
     */
    vector<ProjectModel> srted;
    struct tm  timeinfo;

    for(int i = 0; i < this->projects.size(); i++) {

        if(this->projects[i].getIsDone())
            continue;

        int day = 0, mon = 0, year = 0, pc = 0;
        string date = this->projects[i].getDueDate();
        for(int j= 0; j< date.size(); j++) {
            if(date[j] == '.') {
                pc++;
                continue;
            }
            if(pc == 0)
                day = day * 10 + (date[j] - '0');
            if(pc == 1)
                mon = mon * 10 + (date[j] - '0');
            if(pc == 2)
                year = year * 10 + (date[j] - '0');
        }

        this->projects[i].day = day;
        this->projects[i].month = mon;
        this->projects[i].year = year;

        srted.push_back(this->projects[i]);

    }

    for(int i= 0; i< srted.size(); i++)
        for(int j=0; j< srted.size(); j++) {
            int nrI = srted[i].year*365 + srted[i].month * 30 + srted[i].day;
            int nrJ = srted[j].year*365 + srted[j].month * 30 + srted[j].day;
            if(nrI < nrJ)
                swap(srted[i], srted[j]);
        }

    return srted;

}


int ProjectRepository::totalCostOfFinished() {
    /*
     * Returns the total cost of the project that are finished
     * Return is int type
     */
    int cost = 0;
    for(int i = 0; i < this->projects.size(); i++)
        if(this->projects[i].getIsDone())
            cost += this->projects[i].getCost();

    return cost;

}

int ProjectRepository::getProjectPosition(ProjectModel proj) {
    /*
     * FIND AND RETURNS THE POSITION IN THE INDEX (BY NAME AND CUSTOMER)
     * If the position is not found returns -1
     */
    for(int i = 0; i< this->projects.size(); i++)
        if(this->projects[i].getName() == proj.getName() && this->projects[i].getCustomer() == proj.getCustomer())
            return i;

    return -1;
}

ProjectModel ProjectRepository::getProject(int pos) {
    /*
     * Returns a project at a given index
     * If the index is invalid throw an error
     */

    if(pos < 0 || pos >= this->projects.size())
        throw("Invalid position index");

    return this->projects[pos];
}
