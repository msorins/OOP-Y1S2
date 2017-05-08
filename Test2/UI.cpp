//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "UI.h"
#include "Exception.h"
#include "BP.h"
#include "BMI.h"

UI::UI(Person p) {
    this->p = p;

    while(true) {
        try {
            while(true) {
                this->writeMenu();
                this->parseCommand();
            }

        } catch(Exception ex) {

            std::cerr<<ex.what()<<"\n\n";
        }
    }


}

void UI::writeMenu() {
    cout<<"##########\n";
    cout<<"1. Add Analysis\n";
    cout<<"2. Am I healthy ?\n";
    cout<<"3. Write to file\n";
    cout<<"4. Show all analyses\n";
    cout<<"##########\n";
    cout<<"\n\n";
}

void UI::parseCommand() {
    int cmd;

    cin >> cmd;
    if(cmd < 0)
        throw Exception("Invalid command");
    switch(cmd){
        case 1:
            this->addAnalysis();
            break;
        case 2:
            this->amIHealthy();
            break;
        case 3:
            this->saveToFile();
            break;
        case 4:
            this->showAll();
            break;

    }


}

void UI::addAnalysis() {
    cout<<"##########\n";
    cout<<"1. BMI\n";
    cout<<"2. BP \n";
    cout<<"##########\n";

    int type;
    cin>>type;
    if(type < 1 || type > 2)
        throw Exception("Invalid command");

    if(type == 1) {
        string date;
        double bp;

        cout<<"BP: ";
        cin >> bp;

        cout<<"Date: ";
        cin>>date;

        Date formatedDate(date);

        BMI *bmi = new BMI(formatedDate, bp);
        this->p.addAnalysis(bmi);
    }

    if(type == 2) {
        string date;
        int sys, dia;

        cout<<"Systolic Value: ";
        cin >> sys;

        cout<<"Diastolic Value: ";
        cin>>dia;

        cout<<"Date: ";
        cin>>date;

        Date formatedDate(date);

        BP *bp = new BP(formatedDate, sys, dia);
        this->p.addAnalysis(bp);
    }

    cout<<"\n\nAnalysis added succesfully\n\n";
}

void UI::amIHealthy() {
    int month;
    cout<<"Month: ";
    cin>>month;

    if(month < 1 || month > 12)
        throw Exception("Invalid month");

    if(this->p.isHealthy(month))
        cout<<"\nYes you are healthy\n";
    else
        cout<<"\nNo, something is wrong with you\n";

}

void UI::saveToFile() {
    string file;
    string date;

    cout<<"File: ";
    cin>>file;

    cout<<"Date: ";
    cin>>date;
    Date formatedDate(date);

    this->p.writeToFile(file, formatedDate);

}

void UI::showAll() {
    vector<MedicalAnalysis*> all = this->p.getAllAnalyses();

    for(int i = 0; i < all.size(); i++)
        cout<<i<<": "<<all[i]->toString()<<"\n";
}
