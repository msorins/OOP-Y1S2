//
// Created by Sorin Sebastian Mircea on 31/05/2017.
//

#include "Picture.h"

void Picture::draw() {
    cout<<"draw a picture: " << this->name<<"\n";
    for (auto &&item : gList) {
        item->draw();
    }

    cout<<"\n";
}

void Picture::add(IGraphic *comp) {
    this->gList.push_back(comp);
}

void Picture::remove(IGraphic *comp) {
    this->gList.erase(find(this->gList.begin(), this->gList.end(), comp));
}

Picture::Picture(const string &name) : name(name) {}
