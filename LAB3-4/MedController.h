//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//
#pragma once
#include "MedRepository.h"

typedef struct {
    MedRepository *medRepository;
}MedController;


/*
 * Constructor end Destructor
 */
MedController *createController(MedRepository* medRepository);
void deleteController(MedController* medController);

/*
 * Functions
 */
MedController* addMedicationC(MedController *medController, char *name, double concentration, int quantity, int price);
MedController* deleteMedicationC(MedController *medController, char *name, double concentration);
MedRepository * listMedsC(MedController *medController);


/*
 * Getters & setters
 */
MedRepository *getMedRepository(MedController *medController);