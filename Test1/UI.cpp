//
// Created by Sorin Sebastian Mircea on 10/04/2017.
//

#include "UI.h"
#include <iostream>
using namespace std;

UI::UI() {

}

void UI::printMenu() {
    cout<<"\n\n#############################\n";
    cout<<"1. Add project\n";
    cout<<"2. Mark project as finished\n";
    cout<<"3. Show all projects\n";
    cout<<"4. Show unfinished projects (sorted by due date)\n";
    cout<<"5. Get total cost of finished projects\n";
    cout<<"\n\n#############################\n";
}

void UI::checkCommand(int cmd) {
    if(cmd < 1 || cmd > 5)
        throw("Invalid command");
}

void UI::executeCommand(int cmd) {
    switch(cmd){
        case 1:
            this->addProject();
            break;
        case 2:
            this->markProjectFinished();
            break;
        case 3:
            this->printAllProjects();
            break;
        case 4:
            this->printSortedByDueDate();
            break;
        case 5:
            this->printTotalCostOfFinished();
            break;
    }


}

int UI::getCommand() {
    int cmd;
    cout<<"CMD: ";
    cin>>cmd;

    checkCommand(cmd);
    return cmd;
}

UI::UI(ProjectController pc) {
    this->pc = pc;

   this->insertData();



    while (true) {
        this->printMenu();
        try {
            int cmd = this->getCommand();
            this->executeCommand(cmd);
        } catch (const char* e) {
            std::cerr << "\n"<< e <<"\n";
        }
    }



}

void UI::addProject() {
    string name, customer, dueDate;
    int cost;

    cout<<"Name: ";
    cin>>name;

    cout<<"Customer: ";
    cin>>customer;

    cout<<"Due Date: ";
    cin>>dueDate;

    cout<<"Cost: ";
    cin>>cost;

    this->pc.addProject(name, customer, dueDate, cost, false);
}

void UI::printAllProjects() {
    vector<ProjectModel> projects = this->pc.getAllProjects();

    cout<<"##    NAME    |    CUSTOMER    |    DUEDATE    |    COST    |    ISDONE    ###\n";
    for(int i = 0; i < projects.size(); i++) {
        cout<<projects[i].getName()<<"      "<<projects[i].getCustomer()<<"      "<<projects[i].getDueDate()<<"      "<<projects[i].getCost()<<"      "<<projects[i].getIsDone()<<"\n";
    }
    cout<<"\n";
}

void UI::markProjectFinished() {
    string name, customer;
    cout<<"Name: ";
    cin>>name;

    cout<<"Customer: ";
    cin>>customer;

    this->pc.markProjectFinished(name, customer);

}

void UI::insertData() {
    this->pc.addProject("Stairs", "Flin", "15.04.2018", 18, false);
    this->pc.addProject("A", "B", "15.04.2017", 10, false);
    this->pc.addProject("Website", "SPD", "14.10.2016", 20, false);
    this->pc.addProject("Data", "XOY", "01.01.2015", 5, false);
    this->pc.addProject("MMM", "NNN", "10.02.2000", 50, false);
}

void UI::printTotalCostOfFinished() {
    cout<<"Total cost is: "<<this->pc.totalCostOfFinished();
}

void UI::printSortedByDueDate() {
    vector<ProjectModel> projects = this->pc.sortedUnfinishedByDueDate();

    cout<<"##    NAME    |    CUSTOMER    |    DUEDATE    |    COST    |    ISDONE    ###\n";
    for(int i = 0; i < projects.size(); i++) {
        cout<<projects[i].getName()<<"      "<<projects[i].getCustomer()<<"      "<<projects[i].getDueDate()<<"      "<<projects[i].getCost()<<"      "<<projects[i].getIsDone()<<"\n";
    }
    cout<<"\n";
}

/*
 * struct tm timeinfo;
    ...
    timeinfo = *localtime(&rawtime);
    ...
    date = mktime(&timeinfo);
 */
