#ifndef ALGORITHMSANDDATASTRUCTURES_STACKARRAY_H
#define ALGORITHMSANDDATASTRUCTURES_STACKARRAY_H

#include <stdio.h>

typedef struct StackArrayInt StackArrayInt;
struct StackArrayInt
{
    int* array;
    size_t size;
    int top;
};

int RunStackIntArrayTests();
void InitIntArrayStack(StackArrayInt* stack, int* array, size_t size);
void PushIntArray(StackArrayInt* stack, int valueToPush);
int PopIntArray(StackArrayInt* stack);
int PeekStackIntArray(StackArrayInt* stack);

#endif //ALGORITHMSANDDATASTRUCTURES_STACKARRAY_H
