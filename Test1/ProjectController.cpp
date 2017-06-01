//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#include "ProjectController.h"
#include "ProjectModel.h"

void ProjectController::addProject(string name, string customer, string dueDate, int cost, bool isDone) {
    /*
     * Adds a project to the repository
     * IF something is wrong an error is thrown (trust me)
     */
    ProjectModel crtProj = ProjectModel(name, customer, dueDate, cost, isDone);
    this->projRepo.addProject(crtProj);
}

ProjectController::ProjectController() {

}

ProjectController::ProjectController(ProjectRepository projRepo) {
    this->projRepo = projRepo;
}

vector<ProjectModel> ProjectController::getAllProjects() {
    /*
     * Returns a vector with all projects ready to be printed
     */
    return this->projRepo.getAllProjects();
}

void ProjectController::markProjectFinished(string name, string customer) {
    /*
     * Mark given projects as finished.
     * If it does not exist it will throw an error
     */
    ProjectModel crtProj = ProjectModel(name, customer);
    this->projRepo.markProjectFinished(crtProj);
}

int ProjectController::totalCostOfFinished() {
    /*
     * Returns the total cost of finished
     */
    return this->projRepo.totalCostOfFinished();
}

vector<ProjectModel> ProjectController::sortedUnfinishedByDueDate() {
    return this->projRepo.sortedUnfinishedByDueDate();
}
