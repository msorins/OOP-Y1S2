//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//
#pragma once

typedef struct {
    char *name;
    double concentration;
    int quantity;
    int price;
} Medication;

/*
 * Constructors and Destructers
 */

Medication* createMedication(char *name, double concentration, int quantity, int price);
void deleteMedication(Medication *med);

/*
 * Getters
 */
char* getName(Medication *med);
double getConcentration(Medication *med);
int getQuantity(Medication *med);
int getPrice(Medication *med);

/*
 * Setters
 */
void setName(Medication *med, char *name);
void setConcentration(Medication *med, double concentration);
void setQuantity(Medication *med, int quantity);
void setPrice(Medication *med, int price);