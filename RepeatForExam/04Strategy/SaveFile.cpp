//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#include "SaveFile.h"

SaveFile::SaveFile(const string &msg) : msg(msg) {}

void SaveFile::save() {
    ofstream out("fis.out");
    out<<"save: "<<" "<<this->msg<<"\n";
}
