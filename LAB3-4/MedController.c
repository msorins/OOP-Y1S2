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

MedController *addMedicationC(MedController *medController, char *name, double concentration, int quantity, int price) {
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
        updateMedicationR(medController->medRepository, foundMed->name, foundMed->concentration, foundMed->quantity, foundMed->price);
    }


    return medController;
}

MedRepository * listMedsC(MedController *medController) {
    return medController->medRepository;
}

MedController *deleteMedicationC(MedController *medController, char *name, double concentration) {
    if(doesMedExistsR(medController->medRepository, name, concentration) == 1)
        deleteMedicationR(medController->medRepository, name, concentration);
    else {
        printf("Your med does not exist, sorry \n");
        return medController;
    }
}
