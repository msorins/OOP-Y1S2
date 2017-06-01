#include <iostream>
#include "SaveConsole.h"
#include "SaveFile.h"

int main() {
    //ISave *saveProcess = new SaveConsole("msg");

    ISave *saveProcess = new SaveFile("msg");
    saveProcess->save();
}