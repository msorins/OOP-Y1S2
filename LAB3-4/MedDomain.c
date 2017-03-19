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
    /*
     * @param med: pointer to a med object
     * GETTER for name
     */
    return med->name;
}

double getConcentration(Medication *med) {
    /*
     * @param med: pointer to a med object
     * GETTER for concentration
     */
    return med->concentration;
}

int getQuantity(Medication *med) {
    /*
     * @param med: pointer to a med object
     * GETTER for quantity
     */
    return med->quantity;
}

int getPrice(Medication *med) {
    /*
     * @param med: pointer to a med object
     * GETTER for price
     */
    return med->price;
}

void setName(Medication *med, char *name) {
    /*
     * @param med: pointer to a med object
     * @param name: string pointer with the name
     * SETTER for name
     */
    med->name = name;
}

void setConcentration(Medication *med, double concentration) {
    /*
    * @param med: pointer to a med object
    * @param concentration: new concentration that must be st
    * SETTER for concentration
    */
    med->concentration = concentration;
}

void setQuantity(Medication *med, int quantity) {
    /*
    * @param med: pointer to a med object
    * @param quantity: new quantity that must be st
    * SETTER for quantity
    */
    med->quantity = quantity;
}

void setPrice(Medication *med, int price) {
    /*
    * @param med: pointer to a med object
    * @param price: new price that must be st
    * SETTER for price
    */
    med->price = price;
}

