#ifndef ALGORITHMSANDDATASTRUCTURES_STACKINTARRAY_H
#define ALGORITHMSANDDATASTRUCTURES_STACKINTARRAY_H

#include <stdio.h>

typedef struct StackArrayInt StackArrayInt;
struct StackArrayInt
{
    int* array;
    size_t size;
    int top;
};

void RunTestsStackIntArrayInStackMemory();
void RunTestsIntArrayStackInHeapMemory();

///Use this for creating the stack in stack memory\n\n
///Makes the given integer stack ready to use by assigning default values and linking the given array to the stack.
void InitIntArrayStack(StackArrayInt* stack, int* array, size_t size);

///Use this for creating the stack in heap memory\n\n
///Creates a stack and an integer array in the heap memory, links the array to the stack, assigns default values and returns the created stack.
StackArrayInt* CreateIntArrayStack(size_t size);

///Use this for destroying the stack in heap memory\n\n
///Frees array of the stack and the stack itself
void FreeIntArrayStack(StackArrayInt* stack);

void PushIntArray(StackArrayInt* stack, int valueToPush);
int PopIntArray(StackArrayInt* stack);
int PeekStackIntArray(StackArrayInt* stack);

#endif //ALGORITHMSANDDATASTRUCTURES_STACKINTARRAY_H
