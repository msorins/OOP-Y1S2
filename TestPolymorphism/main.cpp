#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout<<"Animal can speak\n";
    }
};

class Dog: public Animal {
public:
    virtual void speak() {
        cout<<"Dog can speak\n";
    }
};

class Cat: public Animal {
public:
    virtual void speak() {
        cout<<"Cat can speak\n";
    }
};

int main() {
     Animal animalObj;
     Dog dogObj;
     Cat catObj;

     //Animal can speak
     Animal obj1 = dogObj;
     obj1.speak();

     //Dog can speak
     Dog obj2 = dogObj;
     obj2.speak();

     // Dog can speak
     Animal* obj = &dogObj;
     obj->speak();

     // Cat can speak
     Animal* obj3 = &catObj;
     obj3->speak();
}