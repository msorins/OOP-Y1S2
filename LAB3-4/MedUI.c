//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//

#include <cxxabi.h>
#include <printf.h>
#include <stdlib.h>
#include "MedUI.h"
#include "MedRepository.h"
#include "MedDomain.h"

MedUi *createUI(MedController *medController) {
    MedUi* newUI = (MedUi *)malloc(sizeof(MedUi));

    newUI->medController = medController;
    return newUI;
}

void deleteUI(MedUi *medUi) {
    //1st free the components
    deleteController(medUi->medController);

    //then free the object itself
    free(medUi);
}

void printMenu() {
    printf("\####################################################\n");
    printf("0 - list meds\n");
    printf("1 - add a med\n");
    printf("2 - delete a med\n");
    printf("3 - update a med\n");
    printf("4 - sell by name\n");
    printf("5 - sell by price\n");
    printf("6 - see short supply\n");
    printf("7 - undo .\n");
    printf("8 - redo .\n");
    printf("\####################################################\n");
}

void startUI(MedUi* medUi) {
    int cmd;

    while(1) {
        printMenu();
        scanf("%d", &cmd);

        if(cmd == -1)
            exit(0);

        if(!validateCommand(cmd)) {
            printf("Invalid command, must be a number between 1 and 8");
            continue;
        }

        decisionTree(medUi, cmd);



    }
}

int validateCommand(int cmd) {
    /*
     * Returns 1 if command is valid, 0 otherwise
     */
    if(cmd >= 0 && cmd <= 8)
        return 1;
    return 0;
}

void decisionTree(MedUi *medUi, int cmd) {
    switch(cmd) {
        case 0:
            listMedsUi(medUi);
            break;
        case 1:
            addMedUi(medUi);
            break;
        case 2:
            deleteMedUi(medUi);
            break;
        case 3:
            //update a med
            break;
        case 4:
            //sel by name
            break;
        case 5:
            //sell by price
            break;
        case 6:
            //see short supply
            break;
        case 7:
            //undo
            break;
        case 8:
            //redo
            break;
        default:
            break;
    }
}

void addMedUi(MedUi *medUi) {

    char* name = (char*) malloc(sizeof(char) * 100);
    char* aux = (char*) malloc(sizeof(char) * 100);
    double concentration = 0.0;
    int quantity = 0;
    int price = 0;

    printf("Med name \n");
    scanf("%s100", name);

    printf("Concentration \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%lf", &concentration) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }

    printf("Quantity \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%d", &quantity) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }

    printf("Price \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%d", &price) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }

    addMedicationC(medUi->medController, name, concentration, quantity, price);
}

void listMedsUi(MedUi *medUi) {
    int i;
    MedRepository* crtMedRepository = listMedsC(medUi->medController);

    printf("Name  |  Concentration  |  Quantity  |  Price\n");
    for(i = 1 ; i <= crtMedRepository->length; i++) {
        printf("%s    %lf    %d    %d\n", crtMedRepository->medications[i]->name,
               crtMedRepository->medications[i]->concentration,
               crtMedRepository->medications[i]->quantity,
               crtMedRepository->medications[i]->price);
    }
}

void deleteMedUi(MedUi *medUi) {
    char* name = (char*) malloc(sizeof(char) * 100);
    char* aux = (char*) malloc(sizeof(char) * 100);
    double concentration = 0.0;

    printf("Med name \n");
    scanf("%s100", name);

    printf("Concentration \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%lf", &concentration) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }

    deleteMedicationC(medUi->medController, name, concentration);
}

