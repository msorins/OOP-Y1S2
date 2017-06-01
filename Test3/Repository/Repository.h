//
// Created by Sorin Sebastian Mircea on 29/05/2017.
//

#ifndef WLM_REPOSITORY_H
#define WLM_REPOSITORY_H
#include <iostream>
#include <vector>
#include <string>
#include "../MODEL/Bill.h"

using namespace std;

class Repository {
public:
    vector<Bill>  billsList;
    string file;
public:
    //Constructor or destructor
    Repository(const string &file);


    //CRUD
    void add(Bill bill);

    //Functionality
    void loadFromFile(string file);
    vector<Bill> getAll();
    void sortByDueDate();
    vector<int> getPosOfUnpaidBills();
    int totalUnpaidBillsForCompany(string name);
    bool cmp(Bill a, Bill b);

};


#endif //WLM_REPOSITORY_H
