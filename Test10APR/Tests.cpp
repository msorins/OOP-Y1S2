//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#include "Tests.h"
#include "ProjectController.h"
#include <iostream>
#include <cassert>

using namespace std;

Tests::Tests() {
    this->pc = ProjectController();
    this->testAddProject();
    this->testTotalCost();

}

void Tests::testAddProject() {
    this->pc.addProject("Stairs", "Flin", "15.04.2018", 10, false);
    assert(this->pc.getAllProjects().size() == 1);

    this->pc.addProject("A", "B", "15.04.2017", 10, false);
    assert(this->pc.getAllProjects().size() == 2);

    this->pc.addProject("Website", "SPD", "14.10.2016", 20, false);
    assert(this->pc.getAllProjects().size() == 3);

    this->pc.addProject("Data", "XOY", "01.01.2015", 5, false);
    assert(this->pc.getAllProjects().size() == 4);

    this->pc.addProject("MMM", "NNN", "10.02.2000", 50, false);
    assert(this->pc.getAllProjects().size() == 5);
}

void Tests::testTotalCost() {
    this->pc.markProjectFinished("Stairs", "Flin");
    assert(this->pc.totalCostOfFinished() == 10);

    this->pc.markProjectFinished("A", "B");
    assert(this->pc.totalCostOfFinished() == 20);

    this->pc.markProjectFinished("Website", "SPD");
    assert(this->pc.totalCostOfFinished() == 40);

    this->pc.markProjectFinished("Data", "XOY");
    assert(this->pc.totalCostOfFinished() == 45);

    this->pc.markProjectFinished("MMM", "NNN");
    assert(this->pc.totalCostOfFinished() == 95);
}
