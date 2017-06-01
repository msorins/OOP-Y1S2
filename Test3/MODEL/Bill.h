//
// Created by Sorin Sebastian Mircea on 29/05/2017.
//

#ifndef WLM_BILL_H
#define WLM_BILL_H
#include <iostream>
#include <string>
using namespace std;


class Bill {
private:
    string name;
    string serial;
    double sum;
    bool isPaid;

public:
    //Constructor
    Bill(const string name, const string serial, double sum, bool isPaid);

    //Setters and getters
    const string &getName() const;

    void setName(const string &name);

    const string &getSerial() const;

    void setSerial(const string &serial);

    int getSum() const;

    void setSum(int sum);

    bool isIsPaid() const;

    void setIsPaid(bool isPaid);
};


#endif //WLM_BILL_H
