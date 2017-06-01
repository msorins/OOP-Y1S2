#include <iostream>
#include <fstream>
#include "Subject/ActionSubject.h"
#include "Observer/ProductObserver.h"

using namespace std;

int main() {
    ActionSubject carSubject("Lamborghini");

    ProductObserver costelObserver("Costel");
    ProductObserver ionObserver("Ion");

    carSubject.attach(&costelObserver);
    carSubject.attach(&ionObserver);

    carSubject.notify(35);

    carSubject.detach(&costelObserver);

    carSubject.notify(99);
    return 0;
}