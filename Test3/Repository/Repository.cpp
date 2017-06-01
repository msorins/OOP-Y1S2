//
// Created by Sorin Sebastian Mircea on 29/05/2017.
//

#include "Repository.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Repository::Repository(const string &file) : file(file) {
    this->loadFromFile(file);
}

void Repository::loadFromFile(string file) {
    ifstream fin(file);
    string crtLine;
    int i, nr = 0;
    double sum;
    bool isPaid;
    string crtNameS, crtSerialS, crtSumS, crtIsPaidS;

    while(!fin.eof()) {
        crtLine.erase(crtLine.begin(), crtLine.end());
        crtNameS.erase(crtNameS.begin(), crtNameS.end());
        crtSumS.erase(crtSumS.begin(), crtSumS.end());
        crtIsPaidS.erase(crtIsPaidS.begin(), crtIsPaidS.end());
        getline(fin, crtLine);

        nr = 0;
        int x = crtLine.size();
        if(x == 0)
            break;
        for(i = 0; i < crtLine.size() -1 ; i++) {
            if(crtLine[i] == ';') {
                nr++;
                continue;
            }
            if(crtLine[i] == ' ')
                continue;

            if(nr == 0)
                crtNameS   += crtLine[i];
            if(nr == 1)
                crtSerialS += crtLine[i];
            if(nr == 2)
                crtSumS    += crtLine[i];
            if(nr == 3)
                crtIsPaidS += crtLine[i];
        }

        sum = stod(crtSumS);
        char first = crtIsPaidS[0];
        if(first == 'f')
            isPaid = false;
        else
            isPaid = true;


        this->add(Bill(crtNameS, crtSerialS, sum, isPaid));
    }
}

vector<Bill> Repository::getAll() {
    return this->billsList;
}


vector<int> Repository::getPosOfUnpaidBills() {
    return vector<int>();
}

int Repository::totalUnpaidBillsForCompany(string name) {
    int res = 0;
    for(int i = 0; i < this->billsList.size(); i++) {
        if(this->billsList[i].isIsPaid() == false && this->billsList[i].getName().compare(name) == 0) {
            res++;
        }
    }

    return res;
}

void Repository::add(Bill bill) {
    this->billsList.push_back(bill);
}

void Repository::sortByDueDate() {
    /*
     * Se sorteaza bill-urile
     * Ca input se foloseste this->billsList
     * Nu se returneaza nimic, se editeaz alista intern
     */
    for(int i = 0; i < this->billsList.size(); i++)
        for(int j = i + 1; j < this->billsList.size(); j++)
                if(this->billsList[i].getSum() > this->billsList[j].getSum())
                    swap(this->billsList[i], this->billsList[j]);
}

bool Repository::cmp(Bill a, Bill b) {
    return a.getSum() < b.getSum();
}
