//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//

#include <cxxabi.h>
#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "MedController.h"
#include "MedRepository.h"
#include "MedDomain.h"

MedController* createController(MedRepository* medRepo) {
    MedController* newController = (MedController*) malloc(sizeof(MedController));

    newController->medRepository = medRepo;
    return newController;
}

void deleteController(MedController* medController) {
    // 1st free the componenet
    destroyRepo(medController -> medRepository);

    // then free the object itself
    free(medController);
}

MedController* addMedicationC(MedController *medController, char *name, double concentration, int quantity, int price) {
    Medication* newMedication = createMedication(name, concentration, quantity, price);

    if(doesMedExistsR(medController->medRepository, name, concentration) == 0)
        addMedicationR(medController->medRepository, newMedication);
    else {
        //If the med already exists

        //Get it
        Medication* foundMed = getMedR(medController->medRepository, name, concentration);

        //Add current concentration
        foundMed->quantity += quantity;

        //Update it
        updateMedicationR(medController->medRepository, foundMed->name, foundMed->concentration, foundMed->name, foundMed->concentration,
                          foundMed->quantity, foundMed->price);
    }


    return medController;
}

MedRepository* listMedsC(MedController *medController) {
    return medController->medRepository;
}

MedController* deleteMedicationC(MedController *medController, char *name, double concentration) {
    if(doesMedExistsR(medController->medRepository, name, concentration) == 1)
        deleteMedicationR(medController->medRepository, name, concentration);
    else {
        printf("Your med does not exist, sorry \n");
        return medController;
    }
}

MedController *updateMedicationC(MedController *medController, char *orgName, double orgConcentration, char *name,
                                 double concentration, int quantity, int price) {

    if(doesMedExistsR(medController->medRepository, orgName, orgConcentration) == 0) {
        printf("Requested med does not exist, sorry \n");
        return medController;
    }

    updateMedicationR(medController->medRepository, orgName, orgConcentration, name, concentration, quantity, price);
    return medController;
}

MedRepository *listMedicationByNameC(MedController *medController, char *name) {
    int i;
    MedRepository* resMed = createRepository();
    MedRepository* crtMed = medController->medRepository;

    for(i = 1; i <= crtMed->length; i++)
        if(strstr(crtMed->medications[i]->name, name)) {
            addMedicationR(resMed, crtMed->medications[i]);
        }

    MedRepository* sortedRepo = sortMedicationsC(resMed, sortAscendingByName);
    return sortedRepo;
}

MedRepository *sortMedicationsC(MedRepository *medRepository, int (*cmp)(Medication *, Medication *)) {
    int i, j;
    MedRepository* newMedRep = medRepository;
    Medication* aux;

    for(i = 1; i <= newMedRep->length; i++)
        for(j = i+1; j<= newMedRep->length; j++)
            if(cmp(newMedRep->medications[i], newMedRep->medications[j])) {
                aux = newMedRep -> medications[i];
                newMedRep -> medications[i] = newMedRep -> medications[j];
                newMedRep -> medications[j] = aux;
            }

    return newMedRep;
}

int sortAscendingByName(Medication *A,Medication *B) {
    return strcmp(A->name, B->name);
}

MedRepository *listMedicationByConcentrationC(MedController *medController, double concentration) {
    int i;
    MedRepository* resMed = createRepository();
    MedRepository* crtMed = medController->medRepository;

    for(i = 1; i <= crtMed->length; i++)
        if(crtMed->medications[i]->concentration <= concentration) {
            addMedicationR(resMed, crtMed->medications[i]);
        }

    return sortMedicationsC(resMed, sortAscendingByConcentration);
}

int sortAscendingByConcentration(Medication *A, Medication *B) {
    return A->concentration > B->concentration;
}

int sortAscendingByQuantity(Medication *A, Medication *B) {
    return A->quantity > B-> quantity;
}

int sortDescendingByQuantity(Medication *A, Medication *B) {
    return A->quantity < B-> quantity;
}


MedRepository *listMedicationByQuantityC(MedController *medController, int quantity, int direction) {
    int i;
    MedRepository* resMed = createRepository();
    MedRepository* crtMed = medController->medRepository;

    for(i = 1; i <= crtMed->length; i++)
        if(crtMed->medications[i]->quantity <= quantity) {
            addMedicationR(resMed, crtMed->medications[i]);
        }

    MedRepository* sortedMed;
    if(direction == 0)
        sortedMed = sortMedicationsC(resMed, sortAscendingByQuantity);
    else
        sortedMed = sortMedicationsC(resMed, sortDescendingByQuantity);

    return sortedMed;
}
