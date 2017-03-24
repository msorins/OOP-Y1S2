#include <iostream>
#include "DynamicArray.h"
#include "UI.h"
#include "Tests.h"

using namespace std;

int main() {
    Tests tests;

    while(true) {
        try {
            UI UIObj;


        } catch (const char* e) {
            // catch anything thrown within try block that derives from std::exception
            std::cerr << e;
        }
    }


}