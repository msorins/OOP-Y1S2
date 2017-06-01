//
// Created by Sorin Sebastian Mircea on 29/05/2017.
//

#include "Bill.h"

Bill::Bill(const string name, const string serial, double sum, bool isPaid) : name(name), serial(serial), sum(sum),
                                                                             isPaid(isPaid) {}

const string &Bill::getName() const {
    return name;
}

void Bill::setName(const string &name) {
    Bill::name = name;
}

const string &Bill::getSerial() const {
    return serial;
}

void Bill::setSerial(const string &serial) {
    Bill::serial = serial;
}

int Bill::getSum() const {
    return sum;
}

void Bill::setSum(int sum) {
    Bill::sum = sum;
}

bool Bill::isIsPaid() const {
    return isPaid;
}

void Bill::setIsPaid(bool isPaid) {
    Bill::isPaid = isPaid;
}
