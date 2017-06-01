//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#include "ProductObserver.h"

ProductObserver::ProductObserver(string name) {
    this->name = name;
}

void ProductObserver::Update(int value) {
    this->price = value;
    cout<<"Product " << this->name << ". Price: " << this->price <<" \n";
}
