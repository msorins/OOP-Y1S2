//
// Created by Sorin Sebastian Mircea on 19/03/2017.
//

#include "MedController.h"

#ifndef LAB3_4_TESTS_H
#define LAB3_4_TESTS_H

#endif //LAB3_4_TESTS_H


void runTests();
void testAdd(MedController *medController);
void testDelete(MedController *medController);
void testUpdate(MedController *medController);
void testFilterByName(MedController *medController);
void testFilterByConcentration(MedController *medController);
void testFilterByQuantity(MedController *medController);
void testUndo(MedController *medController);
void testRedo(MedController *medController);