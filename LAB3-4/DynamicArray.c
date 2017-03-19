//
// Created by Sorin Sebastian Mircea on 19/03/2017.
//

#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray* dinArray = (DynamicArray*)malloc(sizeof(DynamicArray));
    // make sure that the space was allocated
    if (dinArray == NULL)
        return NULL;

    dinArray->capacity = capacity;
    dinArray->length = 0;

    // allocate space for the elements
    dinArray->elems = (TElement*)malloc(capacity * sizeof(TElement));
    if (dinArray->elems == NULL)
        return NULL;

    return dinArray;
}

void destroy(DynamicArray* dynArray)
{
    /*
     * @param arr: pointer to the dynamic array
     * destroy the array
     */
    if (dynArray == NULL)
        return;

    free(dynArray->elems);
    dynArray->elems = NULL;


    free(dynArray);
    dynArray = NULL;
}

// Resizes the array, allocating more space.
void resize(DynamicArray* dynArray)
{
    /*
     * @param arr: pointer to the dynamic array1
     */
    if (dynArray == NULL)
        return;

    dynArray->capacity *= 4;
    dynArray->elems = (TElement*)realloc(dynArray->elems, dynArray->capacity * sizeof(TElement));
}

void addArray(DynamicArray *dynArray, TElement t)
{
    /*
     * @param arr: pointer to the dynamic array
     * @param t: the element
     */
    if (dynArray == NULL)
        return;
    if (dynArray->elems == NULL)
        return;

    if (dynArray->length == dynArray->capacity)
        resize(dynArray);
    dynArray->elems[dynArray->length++] = t;
}


TElement get(DynamicArray* dynArray, int pos)
{
    /*
     * @param arr: pointer to the dynamic array
     * @param pos: index position
     */
    return dynArray->elems[pos];
}

