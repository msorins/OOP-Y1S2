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
    printf("4 - filter by name\n");
    printf("5 - filter by concentration\n");
    printf("6 - see short supply ( ASC )\n");
    printf("7 - see short supply ( DESC )\n");
    printf("8 - undo .\n");
    printf("9 - redo .\n");
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
            updateMedUI(medUi);
            break;
        case 4:
            listMedUIByName(medUi);
            break;
        case 5:
            listMedUIByConcentration(medUi);
            break;
        case 6:
            listMedUIByQuantity(medUi, 0);
            break;
        case 7:
            listMedUIByQuantity(medUi, 1);
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

void updateMedUI(MedUi *medUi) {
    char* orgName = (char*) malloc(sizeof(char) * 100);
    char* name = (char*) malloc(sizeof(char) * 100);
    char* aux = (char*) malloc(sizeof(char) * 100);
    double orgConcentration = 0.0;
    double concentration = 0.0;
    int quantity = 0;
    int price = 0;

    //Reading part
    printf("Original med name \n");
    scanf("%s100", orgName);

    printf("Original concentration \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%lf", &orgConcentration) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }


    printf("New med name \n");
    scanf("%s100", name);

    printf("New concentration \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%lf", &concentration) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }

    printf("New quantity \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%d", &quantity) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }

    printf("New price \n");
    scanf("%s100", aux);
    if(sscanf(aux, "%d", &price) == 0) {
        printf("Invalid format, sorry :)\n");
        return;
    }

    //Actually call the update function
    updateMedicationC(medUi->medController, orgName, orgConcentration, name, concentration, quantity, price);
}

void listMedUIByName(MedUi *medUi) {
    int i;
    char* name = (char*) malloc(sizeof(char) * 100);

    //Reading part
    printf("Med name \n");
    scanf("%s100", name);

    MedRepository* crtMedRepository = listMedicationByNameC(medUi->medController, name);

    printf("Name  |  Concentration  |  Quantity  |  Price\n");
    for(i = 1 ; i <= crtMedRepository->length; i++) {
        printf("%s    %lf    %d    %d\n", crtMedRepository->medications[i]->name,
               crtMedRepository->medications[i]->concentration,
               crtMedRepository->medications[i]->quantity,
               crtMedRepository->medications[i]->price);
    }
}

void listMedUIByConcentration(MedUi *medUi) {
    int i;
    double concentration = 0;
    //R1eading part
    printf("Max concentration\n");
    scanf("%lf", &concentration);

    MedRepository* crtMedRepository = listMedicationByConcentrationC(medUi->medController, concentration);

    printf("Name  |  Concentration  |  Quantity  |  Price\n");
    for(i = 1 ; i <= crtMedRepository->length; i++) {
        printf("%s    %lf    %d    %d\n", crtMedRepository->medications[i]->name,
               crtMedRepository->medications[i]->concentration,
               crtMedRepository->medications[i]->quantity,
               crtMedRepository->medications[i]->price);
    }
}

void listMedUIByQuantity(MedUi *medUi, int direction) {
    int i;
    int quantity = 0;
    //R1eading part
    printf("Max quantity\n");
    scanf("%d", &quantity);

    MedRepository* crtMedRepository = listMedicationByQuantityC(medUi->medController, quantity, direction);

    printf("Name  |  Concentration  |  Quantity  |  Price\n");
    for(i = 1 ; i <= crtMedRepository->length; i++) {
        printf("%s    %lf    %d    %d\n", crtMedRepository->medications[i]->name,
               crtMedRepository->medications[i]->concentration,
               crtMedRepository->medications[i]->quantity,
               crtMedRepository->medications[i]->price);
    }
}

