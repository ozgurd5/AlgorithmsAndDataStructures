#ifndef ALGORITHMSANDDATASTRUCTURES_STACK_INT_H
#define ALGORITHMSANDDATASTRUCTURES_STACK_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack_Int Stack_Int;
struct Stack_Int
{
    int* array;
    size_t arraySize;
    int top;
};

void TestInStackMemoryStack_Int();
void TestInHeapMemoryStack_Int();

///\n Use this for creating an integer stack in stack memory\n\n
///Makes the given integer stack ready to use by assigning default values and linking the given array to the stack.
void InitStack_Int(Stack_Int* stack, int* array, size_t arraySize);

///\n Use this for creating an integer stack in heap memory\n\n
///Creates a Stack_Int and an integer array in the heap memory, links the array to the stack, assigns default values and
///returns the created stack.
Stack_Int* CreateStack_Int(size_t arraySize);

///\n Use this for destroying the stack in the heap memory\n\n
///Frees array of the stack and the stack itself
void FreeStack_Int(Stack_Int* stack);

///\n Use this for debug purposes
void PrintStack_Int(Stack_Int* stack);

void PushStack_Int(Stack_Int* stack, int valueToPush);
int PopStack_Int(Stack_Int* stack);
int PeekStack_Int(Stack_Int* stack);

#endif //ALGORITHMSANDDATASTRUCTURES_STACK_INT_H
