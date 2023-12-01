#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackIntArray.h"

void InitStackIntArray(StackIntArray* stack, int* array, size_t size)
{
    //Link array
    stack->array = array;
    stack->size = size;

    //Assign default value
    stack->top = -1;
}

StackIntArray* CreateStackIntArray(size_t size)
{
    //Create stack in heap memory
    StackIntArray* stack = (StackIntArray*) malloc(sizeof (StackIntArray));

    //Create integer array in heap memory
    int* array = (int*) malloc(size * sizeof (int));

    //Link array to the stack
    stack->array = array;
    stack->size = size;

    //Assign default value
    stack->top = -1;

    return stack;
}

void FreeStackIntArray(StackIntArray* stack)
{
    free(stack->array);
    free(stack);
}

bool IsStackIntArrayEmpty(StackIntArray* stack)
{
    //Everytime we pop, we decrease top by 1. If top is -1, which is also the default value, we never pushed anything or popped everything.
    return stack->top == -1;
}

bool IsStackIntArrayFull(StackIntArray* stack)
{
    //If top in last index, stack is full
    return stack->top == stack->size - 1;
}

void PushIntArray(StackIntArray* stack, int valueToPush)
{
    if (IsStackIntArrayFull(stack))
    {
        printf("Error: Stack is full\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = valueToPush;
}

int PopIntArray(StackIntArray* stack)
{
    if (IsStackIntArrayEmpty(stack))
    {
        printf("Error: Stack is empty, returning 0\n");
        return 0;
    }

    return stack->array[stack->top--];
}

int PeekStackIntArray(StackIntArray* stack)
{
    if (IsStackIntArrayEmpty(stack))
    {
        printf("Error: Stack is empty, returning 0\n");
        return 0;
    }

    else return stack->array[stack->top];
}

void PrintCurrentStackIntArray(StackIntArray* stack)
{
    printf("Top: %d -> Array: ", stack->top);

    for (int i = 0; i < stack->size; ++i)
    {
        if (i == stack->top) printf("(");
        printf("%d", stack->array[i]);
        if (i == stack->top) printf(")");

        if (i == stack->size -1) printf("\n\n");
        else printf(", ");
    }
}

void RunStackTests(StackIntArray* stack)
{
    printf("() means top. Values that doesn't make sense are garbage values\n\n");

    PrintCurrentStackIntArray(stack);

    printf("Try to peek while empty (never pushed before), it will give empty queue error and return 0: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Try to pop while empty (never pushed before), it will give empty queue error and return 0: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 5);
    printf("Push 5 and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 10);
    printf("Push 10 and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 15);
    printf("Push 15 and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Try to push 20 while full, it will give full capacity error\n");
    PushIntArray(stack, 20);
    PrintCurrentStackIntArray(stack);

    printf("Pop: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Pop: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Pop: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Try to peek while empty (popped everything), it will give empty queue error and return 0: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Try to pop while empty (popped everything), it will give empty queue error and return 0: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);
}

void RunTestsStackIntArrayInStackMemory()
{
    //Creating a stack that holds integer and using array in stack memory
    int array[3];
    StackIntArray exampleStackIntArray;
    InitStackIntArray(&exampleStackIntArray, array, 3);

    printf("A stack that holds integer and using array with size of 3 created in stack memory\n");

    RunStackTests(&exampleStackIntArray);
}

void RunTestsStackIntArrayInHeapMemory()
{
    //Creating a stack that holds integer using array in heap memory
    StackIntArray* exampleStackIntArray = CreateStackIntArray(3);
    printf("A stack that holds integer and using array with size 3 created in heap memory\n");

    RunStackTests(exampleStackIntArray);

    printf("Allocated memories for StackIntArray in heap memory freed");
    FreeStackIntArray(exampleStackIntArray);
}