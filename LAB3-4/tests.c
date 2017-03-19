//
// Created by Sorin Sebastian Mircea on 19/03/2017.
//

#include <assert.h>
#include "MedRepository.h"
#include "MedController.h"
#include "tests.h"
#include "MedDomain.h"

void runTests() {
    MedRepository* medRepository = createRepository();
    MedController* medController = createController(medRepository);

    testAdd(medController);
    testDelete(medController);
    testUpdate(medController);
    testFilterByName(medController);
    testFilterByConcentration(medController);
    testFilterByQuantity(medController);
    testUndo(medController);
}

void testAdd(MedController *medController) {
    addMedicationC(medController, "Sorinium", 1.15, 3, 10);
    assert(medController->medRepository->length == 11);

    addMedicationC(medController, "Sorinium", 1.15, 3, 10);
    assert(medController->medRepository->length == 11);

    addMedicationC(medController, "Kadmium", 3.5, 3, 10);
    assert(medController->medRepository->length == 12);

    addMedicationC(medController, "Kadmium", 3.6, 2, 10);
    assert(medController->medRepository->length == 13);

    addMedicationC(medController, "PC", 1.15, 3, 10);
    assert(medController->medRepository->length == 14);

    addMedicationC(medController, "PC", 1.15, 3, 10);
    assert(medController->medRepository->length == 14);
}

void testDelete(MedController *medController) {
    deleteMedicationC(medController, "Sorinium", 1.15);
    assert(medController->medRepository->length == 13);

    deleteMedicationC(medController, "Sorinium", 1.15);
    assert(medController->medRepository->length == 13);

    deleteMedicationC(medController, "Sorinium", 1.10);
    assert(medController->medRepository->length == 13);

    deleteMedicationC(medController, "Sorinium", 1.10);
    assert(medController->medRepository->length == 13);

    deleteMedicationC(medController, "PC", 1.15);
    assert(medController->medRepository->length == 12);

    deleteMedicationC(medController, "Kadmium", 3.5);
    assert(medController->medRepository->length == 11);

    deleteMedicationC(medController, "Kadmium", 3.6);
    assert(medController->medRepository->length == 10);

}

void testUpdate(MedController *medController) {
    addMedicationC(medController, "Sorinium", 1.15, 3, 10);
    updateMedicationC(medController, "Sorinium", 1.15, "Borinium", 2, 3, 4);

    assert(medController->medRepository->length == 11);

    deleteMedicationC(medController, "Sorinium", 1.15);
    assert(medController->medRepository->length == 11);

    deleteMedicationC(medController, "Borinium", 1.15);
    assert(medController->medRepository->length == 11);

    deleteMedicationC(medController, "Borinium", 2);
    assert(medController->medRepository->length == 10);


}

void testFilterByName(MedController *medController) {
    MedRepository* res ;
    res = listMedicationByNameC(medController, "xxx");
    assert(res->length == 0);

    res = listMedicationByNameC(medController, "&^%$#");
    assert(res->length == 0);

    res = listMedicationByNameC(medController, "a");
    assert(res->length == 2);

    res = listMedicationByNameC(medController, "e");
    assert(res->length == 6);

    res = listMedicationByNameC(medController, "ac");
    assert(res->length == 1);
}

void testFilterByConcentration(MedController *medController) {
    int i;
    MedRepository* res ;

    res = listMedicationByConcentrationC(medController, 2);
    for(i = 1 ; i <= res->length; i++) {
        if(res->medications[i]->concentration >2 )
            assert(0);
    }

    res = listMedicationByConcentrationC(medController, 5);
    for(i = 1 ; i <= res->length; i++) {
        if(res->medications[i]->concentration > 5 )
            assert(0);
    }


}

void testFilterByQuantity(MedController *medController) {
    int i;
    MedRepository* res ;

    res = listMedicationByQuantityC(medController, 10, 0);
    for(i = 1 ; i <= res->length; i++) {
        if(res->medications[i]->quantity >10 )
            assert(0);
    }

    res = listMedicationByQuantityC(medController, 3, 0);
    for(i = 1 ; i <= res->length; i++) {
        if(res->medications[i]->quantity > 3 )
            assert(0);
    }
}

void testUndo(MedController *medController) {
    int x = medController->medRepository->length;


    addMedicationC(medController, "X", 1.15, 3, 10);
    addMedicationC(medController, "Y", 1.16, 3, 10);
    addMedicationC(medController, "Z", 1.17, 3, 10);


    assert(medController->medRepository->length == x + 3 );

    undoStateC(medController);
    assert(medController->medRepository->length == x + 2 );

    undoStateC(medController);
    assert(medController->medRepository->length == x + 1 );

    undoStateC(medController);
    assert(medController->medRepository->length == x  );

    x = medController->medRepository->length;
    deleteMedicationC(medController, "synthroid", 1.5);
    assert(medController->medRepository->length == x - 1 );

    undoStateC(medController);
    assert(medController->medRepository->length == 13 );
}

void testRedo(MedController *medController) {

    int x = medController->medRepository->length;


    addMedicationC(medController, "X", 1.15, 3, 10);
    addMedicationC(medController, "Y", 1.16, 3, 10);
    addMedicationC(medController, "Z", 1.17, 3, 10);
    undoStateC(medController);
    undoStateC(medController);
    undoStateC(medController);

    assert(medController->medRepository->length == x);



}
