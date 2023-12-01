#ifndef ALGORITHMSANDDATASTRUCTURES_STACKINTARRAY_H
#define ALGORITHMSANDDATASTRUCTURES_STACKINTARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackIntArray StackIntArray;
struct StackIntArray
{
    int* array;
    size_t arraySize;
    int top;
};

void RunTestsStackIntArrayInStackMemory();
void RunTestsStackIntArrayInHeapMemory();

///Use this for creating an integer stack in stack memory\n\n
///Makes the given integer stack ready to use by assigning default values and linking the given array to the stack.
void InitStackIntArray(StackIntArray* stack, int* array, size_t arraySize);

///Use this for creating an integer stack in heap memory\n\n
///Creates a StackIntArray and an integer array in the heap memory, links the array to the stack, assigns default values and
///returns the created stack.
StackIntArray* CreateStackIntArray(size_t arraySize);

///Use this for destroying the stack in the heap memory\n\n
///Frees array of the stack and the stack itself
void FreeStackIntArray(StackIntArray* stack);

///Use this for debug purposes
void PrintStackIntArray(StackIntArray* stack);

void PushStackIntArray(StackIntArray* stack, int valueToPush);
int PopStackIntArray(StackIntArray* stack);
int PeekStackIntArray(StackIntArray* stack);

#endif //ALGORITHMSANDDATASTRUCTURES_STACKINTARRAY_H
