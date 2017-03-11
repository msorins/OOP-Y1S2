//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//
#pragma once
#include "MedRepository.h"

typedef struct {
    MedRepository *medRepository;
    MedRepository **pastMedRepositories;
    int crtPastIndex;
    int maxPastLength;

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
MedController *updateMedicationC(MedController *medController, char *orgName, double orgConcentration, char *name,
                                 double concentration, int quantity, int price);
MedRepository* listMedsC(MedController *medController);
MedRepository* listMedicationByNameC(MedController *medController, char *name);
MedRepository* listMedicationByConcentrationC(MedController *medController, double concentration);
MedRepository *listMedicationByQuantityC(MedController *medController, int quantity, int direction);

MedRepository *sortMedicationsC(MedRepository *medRepository, int (*cmp)(Medication *, Medication *));
int sortAscendingByName(Medication *A,Medication *B);
int sortAscendingByConcentration(Medication *A,Medication *B);
int sortAscendingByQuantity(Medication *A, Medication *B);
int sortDescendingByQuantity(Medication *A, Medication *B);

MedController* addStateC(MedController *medController);
MedController* undoStateC(MedController *medController);
MedController* redoStateC(MedController *medController);
MedRepository * deepCopyMedC(MedRepository *medRepository);

MedController* addInitialDataC(MedController *medController);

/*
 * Getters & setters
 */
MedRepository *getMedRepository(MedController *medController);