#include <iostream>
#include "DynamicArray.h"
#include "UI.h"
#include "Tests.h"

using namespace std;


int main() {
    Tests tests;

    DynamicArray<int> a;
    a.push_back(1);
    a = a + 2;
    a = 3 + a;

    for(int i = 1; i<=a.getLength(); i++)
        cout<< a.get(i)<<" ";


    while(true) {
        try {
            UI UIObj;


        } catch (const char* e) {
            // catch anything thrown within try block that derives from std::exception
            std::cerr << e;
        }
    }




}