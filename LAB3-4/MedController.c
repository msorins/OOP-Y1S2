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
    newController->pastMedRepositories = (MedRepository**) malloc(sizeof(MedRepository*) * 1000);

    newController->pastMedRepositories[1] = medRepo;
    newController->crtPastIndex = 1;
    newController->maxPastLength = 1;

    addInitialDataC(newController);

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

    //Add a new state to the controller
    addStateC(medController);

    return medController;
}

MedRepository* listMedsC(MedController *medController) {
    return medController->medRepository;
}

MedController* deleteMedicationC(MedController *medController, char *name, double concentration) {
    if(doesMedExistsR(medController->medRepository, name, concentration) == 1) {
        deleteMedicationR(medController->medRepository, name, concentration);

        //Add a new state to the controller
        addStateC(medController);
    }
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

    //Add a new state to the controller
    addStateC(medController);

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

MedController *addStateC(MedController *medController) {
    medController->maxPastLength += 1;
    medController->crtPastIndex = medController->maxPastLength;
    medController->pastMedRepositories[ medController->maxPastLength ] = deepCopyMedC(medController->medRepository);
    return medController;
}

MedController *undoStateC(MedController *medController) {
    if(medController->crtPastIndex <= 1) {
        printf("Can't undo anymore ;)\n");
        return medController;
    }

    medController->crtPastIndex -= 1;
    medController->medRepository = medController->pastMedRepositories[ medController->crtPastIndex ];
    return medController;
}

MedController *redoStateC(MedController *medController) {
    if(medController->crtPastIndex >= medController->maxPastLength) {
        printf("Can't redo anymore ;)\n");
        return medController;
    }

    medController->crtPastIndex += 1;
    medController->medRepository = medController->pastMedRepositories[ medController->crtPastIndex ];
    return  medController;
}

MedRepository * deepCopyMedC(MedRepository *medRepository) {
    int i;
    MedRepository* newMedRepository = createRepository();
    Medication* newMedication;
    newMedRepository->length = medRepository->length;

    for(i=1; i <= medRepository->length; i++) {
        newMedication = createMedication(medRepository->medications[i]->name, medRepository->medications[i]->concentration, medRepository->medications[i]->quantity, medRepository->medications[i]->price);
        newMedRepository->medications[i] = newMedication;
    }

    return newMedRepository;
}

MedController *addInitialDataC(MedController *medController) {
    char* aux;

    aux = "synthroid";
    addMedicationC(medController, aux , 1.5, 5, 10);

    aux = "crestor";
    addMedicationC(medController, aux , 1.15, 50, 70);

    aux = "ventolin";
    addMedicationC(medController, aux , 61.5, 1, 100);

    aux = "nexium";
    addMedicationC(medController, aux , 4.5, 10, 35);

    aux = "paracetamol";
    addMedicationC(medController, aux , 3.14, 10, 23);

    aux = "nurofen";
    addMedicationC(medController, aux , 6.5, 105, 300);

    aux = "homeogen";
    addMedicationC(medController, aux , 0.15, 23, 10);

    aux = "siroup";
    addMedicationC(medController, aux , 61.5, 50, 60);

    aux = "sb";
    addMedicationC(medController, aux , 81.5, 5, 80);

    aux = "sa";
    addMedicationC(medController, aux , 54.3, 60, 60);

    return medController;
}



