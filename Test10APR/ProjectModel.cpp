//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#include "ProjectModel.h"

ProjectModel::ProjectModel() {

}

ProjectModel::ProjectModel(string name, string customer, string dueDate, int cost, bool isDone) {
    this->name = name;
    this->customer = customer;
    this->dueDate = dueDate;
    this->cost = cost;
    this->isDone = isDone;
}

ProjectModel::ProjectModel(string name, string customer) {
    this->name = name;
    this->customer = customer;
}

string ProjectModel::getName() {
    return this->name;
}

void ProjectModel::setName(string name) {
    this->name = name;
}

string ProjectModel::getCustomer() {
    return this->customer;
}

void ProjectModel::setCustomer(string customer) {
    this->customer = customer;
}

string ProjectModel::getDueDate() {
    return this->dueDate;
}

void ProjectModel::setDueDate(string date) {
    this->dueDate = date;
}

int ProjectModel::getCost() {
    return this->cost;
}

void ProjectModel::setCost(int cost) {
    this->cost = cost;
}

bool ProjectModel::getIsDone() {
    return this->isDone;
}

void ProjectModel::setIsDone(bool ok) {
    this->isDone = ok;

}
