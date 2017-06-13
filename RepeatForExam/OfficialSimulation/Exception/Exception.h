//
// Created by Sorin Sebastian Mircea on 13/06/2017.
//

#include <iostream>
using namespace std;

class Exception {
private:
    string msg;
public:
    Exception(char const* const message) throw();
    virtual char const* what() const throw();
};


