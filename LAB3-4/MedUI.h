//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//
#pragma once
#include "MedController.h"

typedef struct {
    MedController *medController;
}MedUi;


/*
 * Constructor end Destructor
 */
MedUi* createUI(MedController* medController);
void deleteUI(MedUi* medUi);


/*
 * Functionality
 */
void printMenu();
void startUI(MedUi* medUi);
int validateCommand(int cmd);
void decisionTree(MedUi *medUi, int cmd);
void listMedsUi(MedUi* medUi);

void addMedUi(MedUi* medUi);
void deleteMedUi(MedUi* medUi);