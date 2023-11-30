#include <stdio.h>
#include <stdlib.h>
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

    //Assign default values
    stack->size = size;
    stack->top = -1;

    return stack;
}

void FreeStackIntArray(StackIntArray* stack)
{
    free(stack->array);
    free(stack);
}

void PushIntArray(StackIntArray* stack, int valueToPush)
{
    if (stack->top == stack->size - 1) //If top in last index
    {
        printf("Error: Stack capacity full\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = valueToPush;
}

int PopIntArray(StackIntArray* stack)
{
    if (stack->top == -1) //-1 is default value of the top
    {
        printf("Error: Stack is empty, returning 0\n");
        return 0;
    }

    return stack->array[stack->top--];
}

int PeekStackIntArray(StackIntArray* stack)
{
    if (stack->top == -1) //-1 is default value of the top
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

    PushIntArray(stack, 5);
    printf("Push 5 and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 10);
    printf("Push 10 and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 15);
    printf("Push 15 and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Pop: %d\n", PopIntArray(stack));
    printf("Peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Pop: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Pop: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Try to pop, it will give empty queue error and return 0: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Try to peek, it will give empty queue error and return 0: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 5);
    printf("Push 5 again and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 10);
    printf("Push 10 again and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 15);
    printf("Push 15 again and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);

    printf("Try to push 20, it will give full capacity error\n");
    PushIntArray(stack, 20);
    PrintCurrentStackIntArray(stack);

    printf("Pop: %d\n", PopIntArray(stack));
    PrintCurrentStackIntArray(stack);

    PushIntArray(stack, 20);
    printf("Try to push 20 again and peek: %d\n", PeekStackIntArray(stack));
    PrintCurrentStackIntArray(stack);
}

void RunTestsStackIntArrayInHeapMemory()
{
    //Creating a stack that holds integer using array in heap memory
    StackIntArray* exampleStackIntArray = CreateStackIntArray(3);
    printf("A stack that holds integer and using array with size 3 created in heap memory\n");

    RunStackTests(exampleStackIntArray);
    FreeStackIntArray(exampleStackIntArray);
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