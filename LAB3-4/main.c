#include <stdio.h>
#include "MedRepository.h"
#include "MedController.h"
#include "MedUI.h"

void startProgram() {
    /*
     * Bootstrap program core components (Repo, Controller, UI)
     */
    MedRepository* medRepository = createRepository();
    MedController* medController = createController(medRepository);
    MedUi* medUi = createUI(medController);

    startUI(medUi);
}



int main() {
    startProgram();
    return 0;
}