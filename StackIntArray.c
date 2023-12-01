#include "StackIntArray.h"

void InitStackIntArray(StackIntArray* stack, int* array, size_t arraySize)
{
    //Link array
    stack->array = array;
    stack->arraySize = arraySize;

    //Assign default value
    stack->top = -1;
}

StackIntArray* CreateStackIntArray(size_t arraySize)
{
    //Create stack in heap memory
    StackIntArray* stack = (StackIntArray*) malloc(sizeof (StackIntArray));

    //Create integer array in heap memory
    int* array = (int*) malloc(arraySize * sizeof (int));

    //Link array to the stack
    stack->array = array;
    stack->arraySize = arraySize;

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
    return stack->top == stack->arraySize - 1;
}

void PushStackIntArray(StackIntArray* stack, int valueToPush)
{
    if (IsStackIntArrayFull(stack))
    {
        printf("Error: Stack is full\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = valueToPush;
}

int PopStackIntArray(StackIntArray* stack)
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

void PrintStackIntArray(StackIntArray* stack)
{
    printf("Top: %d -> Array: ", stack->top);

    for (int i = 0; i < stack->arraySize; ++i)
    {
        if (i == stack->top) printf("(");
        printf("%d", stack->array[i]);
        if (i == stack->top) printf(")");

        if (i == stack->arraySize - 1) printf("\n\n");
        else printf(", ");
    }
}

void RunStackTests(StackIntArray* stack)
{
    printf("() means top. Values that doesn't make sense are garbage values\n\n");

    //TESTS:
    //TRY TO PEEK AND POP WHILE EMPTY (NEVER ENQUEUED BEFORE)
    //PUSH AND PEEK
    //TRY TO PUSH WHILE FULL
    //POP AND PEEK
    //TRY TO PEEK AND POP WHILE EMPTY (POPPED EVERYTHING)

    //TRY TO PEEK AND POP WHILE EMPTY (NEVER ENQUEUED BEFORE)
    printf("Try to peek while empty (never pushed before), it will give empty queue error and return 0: %d\n", PeekStackIntArray(stack));
    PrintStackIntArray(stack);

    printf("Try to pop while empty (never pushed before), it will give empty queue error and return 0: %d\n", PopStackIntArray(stack));
    PrintStackIntArray(stack);
    //TRY TO PEEK AND POP WHILE EMPTY (NEVER ENQUEUED BEFORE)

    //PUSH AND PEEK
    PushStackIntArray(stack, 5);
    printf("Push 5 and peek: %d\n", PeekStackIntArray(stack));
    PrintStackIntArray(stack);

    PushStackIntArray(stack, 10);
    printf("Push 10 and peek: %d\n", PeekStackIntArray(stack));
    PrintStackIntArray(stack);

    PushStackIntArray(stack, 15);
    printf("Push 15 and peek: %d\n", PeekStackIntArray(stack));
    PrintStackIntArray(stack);
    //PUSH AND PEEK

    //TRY TO PUSH WHILE FULL
    printf("Try to push 20 while full, it will give full capacity error\n");
    PushStackIntArray(stack, 20);
    PrintStackIntArray(stack);
    //TRY TO PUSH WHILE FULL

    //POP AND PEEK
    printf("Pop: %d\n", PopStackIntArray(stack));
    PrintStackIntArray(stack);

    printf("Peek: %d\n", PeekStackIntArray(stack));
    PrintStackIntArray(stack);

    printf("Pop: %d\n", PopStackIntArray(stack));
    PrintStackIntArray(stack);

    printf("Peek: %d\n", PeekStackIntArray(stack));
    PrintStackIntArray(stack);

    printf("Pop: %d\n", PopStackIntArray(stack));
    PrintStackIntArray(stack);
    //POP AND PEEK

    //TRY TO PEEK AND POP WHILE EMPTY (POPPED EVERYTHING)
    printf("Try to peek while empty (popped everything), it will give empty queue error and return 0: %d\n", PeekStackIntArray(stack));
    PrintStackIntArray(stack);

    printf("Try to pop while empty (popped everything), it will give empty queue error and return 0: %d\n", PopStackIntArray(stack));
    PrintStackIntArray(stack);
    //TRY TO PEEK AND POP WHILE EMPTY (POPPED EVERYTHING)
}

void RunTestsStackIntArrayInStackMemory()
{
    //Creating a stack that holds integer and using array in stack memory
    int array[3];
    StackIntArray exampleStackIntArray;
    InitStackIntArray(&exampleStackIntArray, array, 3);

    printf("A stack that holds integer and using array with arraySize of 3 created in stack memory\n");

    RunStackTests(&exampleStackIntArray);
}

void RunTestsStackIntArrayInHeapMemory()
{
    //Creating a stack that holds integer using array in heap memory
    StackIntArray* exampleStackIntArray = CreateStackIntArray(3);
    printf("A stack that holds integer and using array with arraySize 3 created in heap memory\n");

    RunStackTests(exampleStackIntArray);

    printf("Allocated memories for StackIntArray in heap memory freed");
    FreeStackIntArray(exampleStackIntArray);
}