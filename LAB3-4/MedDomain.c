//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//
#include "MedDomain.h"

#include <cxxabi.h>
#include <stdlib.h>

Medication *createMedication(char *name, double concentration, int quantity, int price) {
/**
 * Allocates a new Medication Object
 * @name: char pointer
 * @concentration: double pointer
 * @quantity: int pointer
 * @price: int pointer
 */
    Medication *m = (Medication*) malloc(sizeof(Medication));

    m->name = name;
    m->concentration = concentration;
    m->quantity = quantity;
    m->price = price;

    //Return the pointer to the newly created Medication
    return m;
}

void deleteMedication(Medication *med) {
/**
 * Dealocates a medication object
 */
    //First the parameter
    free(med->name);

    //Then the object itself
    free(med);
}

char *getName(Medication *med) {
    return med->name;
}

double getConcentration(Medication *med) {
    return med->concentration;
}

int getQuantity(Medication *med) {
    return med->quantity;
}

int getPrice(Medication *med) {
    return med->price;
}

void setName(Medication *med, char *name) {
    med->name = name;
}

void setConcentration(Medication *med, double concentration) {
    med->concentration = concentration;
}

void setQuantity(Medication *med, int quantity) {
    med->quantity = quantity;
}

void setPrice(Medication *med, int price) {
    med->price = price;
}

