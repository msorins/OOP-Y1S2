//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#include "ISubject.h"

void ISubject::attach(IObserver *product) {
    this->list.push_back(product);
}

void ISubject::detach(IObserver *product) {
    this->list.erase( find(this->list.begin(), this->list.begin(), product) );
}

void ISubject::notify(int price) {
    for(auto crt : this->list) {
        crt->Update(price);
    }
}
