//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "Exception.h"


Exception::Exception(char const *const message) throw() {
    this->msg=message;
}

char const *Exception::what() const throw(){
    return this->msg.c_str();
}
