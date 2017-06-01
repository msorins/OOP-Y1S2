//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#ifndef INC_01OBSERVER_PRODUCTOBSERVER_H
#define INC_01OBSERVER_PRODUCTOBSERVER_H

#include <iostream>
#include <string>
#include "IObserver.h"

using namespace std;

class ProductObserver: public IObserver {
private:
    string name;
    int price;

public:
    //Constructor and destructor
    ProductObserver(string name);

private:
    void Update(int value) override;
};


#endif //INC_01OBSERVER_PRODUCTOBSERVER_H
