#include <iostream>
#include "Adapter/RectangleAdapter.h"

using namespace std;

/*
 * https://sourcemaking.com/design_patterns/adapter
 * https://sourcemaking.com/design_patterns/adapter/cpp/1
 */

int main() {
     RectangleAdapter r(10,20,50,100);

     r.newDraw();
}