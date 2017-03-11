//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//
#pragma once
#include "MedDomain.h"

typedef struct {
    Medication** medications;
    int length;
} MedRepository;

/*
 * Constructors and destructors
 */
MedRepository* createRepository();
void destroyRepo(MedRepository* medRepo);


/*
 * Getters and setters
 */
int getLengthR(MedRepository *medRepo);


/*
 * Functionality
 */

MedRepository* addMedicationR(MedRepository *medRepo, Medication *medObj);
int doesMedExistsR(MedRepository *medRepository, char *name, double concentration);
MedRepository *updateMedicationR(MedRepository *medRepository, char *orgName, double orgConcentration, char *name,
                                 double concentration, int quantity, int price);
Medication *getMedR(MedRepository *medRepository, char *name, double concentration);
MedRepository* deleteMedicationR(MedRepository *medRepository, char *name, double concentration);
