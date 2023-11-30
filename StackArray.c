#include<stdio.h>
#include "StackArray.h"

///Makes integer stack ready to use by assigning default values and linking the given array to the stack
void InitIntArrayStack(StackArrayInt* stack, int* array, size_t size)
{
    stack->array = array;
    stack->size = size;
    stack->top = -1;
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

int RunStackIntArrayTests()
{
    //Creating an integer stack that uses array
    int stackArray[2];
    StackArrayInt exampleStackArrayInt;
    InitIntArrayStack(&exampleStackArrayInt, stackArray, 2);

    printf("An integer stack using array with capacity of 3 created\n");

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

    return 0;
}
