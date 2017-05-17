//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#ifndef LAB5_6_EXCEPTION_H
#define LAB5_6_EXCEPTION_H
#include <iostream>
using namespace std;

class Exception {
private:
    string msg;
public:
    Exception(char const* const message) throw();
    virtual char const* what() const throw();
};


#endif //LAB5_6_EXCEPTION_H
