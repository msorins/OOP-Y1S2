//
// Created by Sorin Sebastian Mircea on 19/03/2017.
//

#pragma once
#include "MedRepository.h"
#define CAPACITY 10

typedef MedRepository* TElement;

typedef struct
{
    TElement* elems;
    int length;			// actual length of the array !!!
    int capacity;		// maximum capacity of the array !!!
} DynamicArray;

DynamicArray* createDynamicArray(int capacity);
void destroy(DynamicArray* dynArray);
void addArray(DynamicArray *dynArray, TElement t);
TElement get(DynamicArray* dynArray, int pos);
