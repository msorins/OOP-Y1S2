#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main() {
    DynamicArray<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);

    for(int i=1; i<= arr.getLength(); i++)
        cout<<arr.get(i)<<" ";

}