#include <iostream>
using namespace std;

int foo(int x);
int poo(int x);
int PRINC(int x, int (*f)(int));

int main()
{
    //int (*fcnPtr)(int) = foo; // assign fcnPtr to function foo
    //(*fcnPtr)(5); // call function foo(5) through fcnPtr.

    cout<< PRINC(5, foo)<<"\n";
    cout<< PRINC(5, poo);
    return 0;
}

int foo(int x)
{
    return x*2;
}

int poo(int x) {
    return x / 2;
}

int PRINC(int x, int (*f)(int)) {
    return f(x);
}