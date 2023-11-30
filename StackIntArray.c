#include <stdio.h>
#include <stdlib.h>
#include "StackIntArray.h"

void InitIntArrayStack(StackArrayInt* stack, int* array, size_t size)
{
    //Link array
    stack->array = array;
    stack->size = size;

    //Assign default value
    stack->top = -1;
}

StackArrayInt* CreateIntArrayStack(size_t size)
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

void FreeIntArrayStack(StackArrayInt* stack)
{
    free(stack->array);
    free(stack);
}

void PushIntArray(StackArrayInt* stack, int valueToPush)
{
    if (stack->top == stack->size - 1) //If top in last index
    {
        printf("Error: Capacity full\n");
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
    //Creating integer array stack in stack memory
    int stackArray[3];
    StackArrayInt exampleStackArrayInt;
    InitIntArrayStack(&exampleStackArrayInt, stackArray, 3);

    printf("An integer stack using array with capacity of 3 created in stack memory\n");

    PushIntArray(&exampleStackArrayInt, 5);
    printf("Push 5 and peek: %d\n", PeekStackIntArray(&exampleStackArrayInt));

    PushIntArray(&exampleStackArrayInt, 10);
    printf("Push 10 and peek: %d\n", PeekStackIntArray(&exampleStackArrayInt));

    printf("Pop: %d\n", PopIntArray(&exampleStackArrayInt));

    printf("Peek: %d\n", PeekStackIntArray(&exampleStackArrayInt));

    PushIntArray(&exampleStackArrayInt, 10);
    printf("Push 10 again and peek: %d\n", PeekStackIntArray(&exampleStackArrayInt));

    PushIntArray(&exampleStackArrayInt, 15);
    printf("Push 15 and peek: %d\n", PeekStackIntArray(&exampleStackArrayInt));

    printf("Try to push 20, it will give full capacity error\n");
    PushIntArray(&exampleStackArrayInt, 20);

    printf("Pop: %d\n", PopIntArray(&exampleStackArrayInt));

    PushIntArray(&exampleStackArrayInt, 20);
    printf("Try to push 20 again and peek: %d\n", PeekStackIntArray(&exampleStackArrayInt));
}

void RunTestsIntArrayStackInHeapMemory()
{
    //Creating integer stack array in heap memory
    StackArrayInt* exampleStackArrayInt2 = CreateIntArrayStack(3);
    printf("An integer stack using array with capacity of 3 created in heap memory\n");

    PushIntArray(exampleStackArrayInt2, 5);
    printf("Push 5 and peek: %d\n", PeekStackIntArray(exampleStackArrayInt2));

    PushIntArray(exampleStackArrayInt2, 10);
    printf("Push 10 and peek: %d\n", PeekStackIntArray(exampleStackArrayInt2));

    printf("Pop: %d\n", PopIntArray(exampleStackArrayInt2));

    printf("Peek: %d\n", PeekStackIntArray(exampleStackArrayInt2));

    PushIntArray(exampleStackArrayInt2, 10);
    printf("Push 10 again and peek: %d\n", PeekStackIntArray(exampleStackArrayInt2));

    PushIntArray(exampleStackArrayInt2, 15);
    printf("Push 15 and peek: %d\n", PeekStackIntArray(exampleStackArrayInt2));

    printf("Try to push 20, it will give full capacity error\n");
    PushIntArray(exampleStackArrayInt2, 20);

    printf("Pop: %d\n", PopIntArray(exampleStackArrayInt2));

    PushIntArray(exampleStackArrayInt2, 20);
    printf("Try to push 20 again and peek: %d\n", PeekStackIntArray(exampleStackArrayInt2));

    FreeIntArrayStack(exampleStackArrayInt2);
}