//
// Created by Sorin Sebastian Mircea on 20/03/2017.
//
#pragma  once
#include <stdlib.h>
#include "MedDomain.h"
#include "MedController.h"

typedef struct {
    Medication *med;
    int code; // 1 - add , 2 - delete, 3 - update
}Operation;

