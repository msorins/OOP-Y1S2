//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_TESTS_H
#define LAB5_6_TESTS_H


#include "MovieController.h"

class Tests {
private:
    MovieController movieController;
public:
    Tests();
    void testAdminAdd();
    void testAdminDel();
    void testAdminUpdate();
    void testUserAdd();
    void testUserDel();
};


#endif //LAB5_6_TESTS_H
