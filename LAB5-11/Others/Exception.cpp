//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#include "Exception.h"

Exception::Exception(char const *const message) throw() {
    this->msg=message;
}

char const *Exception::what() const throw(){
    return this->msg.c_str();
}
