#include <stdio.h>
#include <stdlib.h>
#include "StackIntArray.h"

void InitStackIntArray(StackArrayInt* stack, int* array, size_t size)
{
    //Link array
    stack->array = array;
    stack->size = size;

    //Assign default value
    stack->top = -1;
}

StackArrayInt* CreateStackIntArray(size_t size)
{
    //Create stack in heap memory
    StackArrayInt* createdStack = (StackArrayInt*) malloc(sizeof (StackArrayInt));

    //Create integer array in heap memory
    int* intArray = (int*) malloc(size * sizeof (int));

    //Link array to the stack
    createdStack->array = intArray;

    //Assign default values
    createdStack->size = size;
    createdStack->top = -1;

    return createdStack;
}

void FreeStackIntArray(StackArrayInt* stack)
{
    free(stack->array);
    free(stack);
}

void PushIntArray(StackArrayInt* stack, int valueToPush)
{
    if (stack->top == stack->size - 1) //If top in last index
    {
        printf("Error: Stack capacity full\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = valueToPush;
}

int PopIntArray(StackArrayInt* stack)
{
    if (stack->top == -1) //-1 is default value of the top
    {
        printf("Error: Stack is empty, returning 0\n");
        return 0;
    }

    return stack->array[stack->top--];
}

int PeekStackIntArray(StackArrayInt* stack)
{
    if (stack->top == -1) //-1 is default value of the top
    {
        printf("Error: Stack is empty, returning 0\n");
        return 0;
    }

    else return stack->array[stack->top];
}

void RunTestsStackIntArrayInStackMemory()
{
    //Creating stack that holds integer and using array in stack memory
    int stackArray[3];
    StackArrayInt exampleStackIntArray;
    InitStackIntArray(&exampleStackIntArray, stackArray, 3);

    printf("A stack that holds integer and using array with size of 3 created in stack memory\n");

    //TODO: empty check

    PushIntArray(&exampleStackIntArray, 5);
    printf("Push 5 and peek: %d\n", PeekStackIntArray(&exampleStackIntArray));

    PushIntArray(&exampleStackIntArray, 10);
    printf("Push 10 and peek: %d\n", PeekStackIntArray(&exampleStackIntArray));

    printf("Pop: %d\n", PopIntArray(&exampleStackIntArray));

    printf("Peek: %d\n", PeekStackIntArray(&exampleStackIntArray));

    PushIntArray(&exampleStackIntArray, 10);
    printf("Push 10 again and peek: %d\n", PeekStackIntArray(&exampleStackIntArray));

    PushIntArray(&exampleStackIntArray, 15);
    printf("Push 15 and peek: %d\n", PeekStackIntArray(&exampleStackIntArray));

    printf("Try to push 20, it will give full capacity error\n");
    PushIntArray(&exampleStackIntArray, 20);

    printf("Pop: %d\n", PopIntArray(&exampleStackIntArray));

    PushIntArray(&exampleStackIntArray, 20);
    printf("Try to push 20 again and peek: %d\n", PeekStackIntArray(&exampleStackIntArray));
}

void RunTestsStackIntArrayInHeapMemory()
{
    //Creating stack that holds integer using array in heap memory
    StackArrayInt* exampleStackIntArray = CreateStackIntArray(3);
    printf("A stack that holds integer and using array with size 3 created in heap memory\n");

    PushIntArray(exampleStackIntArray, 5);
    printf("Push 5 and peek: %d\n", PeekStackIntArray(exampleStackIntArray));

    PushIntArray(exampleStackIntArray, 10);
    printf("Push 10 and peek: %d\n", PeekStackIntArray(exampleStackIntArray));

    printf("Pop: %d\n", PopIntArray(exampleStackIntArray));

    printf("Peek: %d\n", PeekStackIntArray(exampleStackIntArray));

    PushIntArray(exampleStackIntArray, 10);
    printf("Push 10 again and peek: %d\n", PeekStackIntArray(exampleStackIntArray));

    PushIntArray(exampleStackIntArray, 15);
    printf("Push 15 and peek: %d\n", PeekStackIntArray(exampleStackIntArray));

    printf("Try to push 20, it will give full capacity error\n");
    PushIntArray(exampleStackIntArray, 20);

    printf("Pop: %d\n", PopIntArray(exampleStackIntArray));

    PushIntArray(exampleStackIntArray, 20);
    printf("Try to push 20 again and peek: %d\n", PeekStackIntArray(exampleStackIntArray));

    FreeStackIntArray(exampleStackIntArray);
    printf("Stack freed!");
}