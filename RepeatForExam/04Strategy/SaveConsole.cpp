//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#include "SaveConsole.h"

void SaveConsole::save() {
    cout<<"saved: " << this->msg << "\n";
}

SaveConsole::SaveConsole(string msg): msg{msg} {

}
