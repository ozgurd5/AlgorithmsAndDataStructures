#include "Stack_Int.h"

void InitStack_Int(Stack_Int* stack, int* array, size_t arraySize)
{
    //Link array
    stack->array = array;
    stack->arraySize = arraySize;

    //Assign default value
    stack->top = -1;
}

Stack_Int* CreateStack_Int(size_t arraySize)
{
    //Create stack in heap memory
    Stack_Int* stack = (Stack_Int*) malloc(sizeof (Stack_Int));

    //Create integer array in heap memory
    int* array = (int*) malloc(arraySize * sizeof (int));

    //Link array to the stack
    stack->array = array;
    stack->arraySize = arraySize;

    //Assign default value
    stack->top = -1;

    return stack;
}

void FreeStack_Int(Stack_Int* stack)
{
    free(stack->array);
    free(stack);
}

bool IsStackIntArrayEmpty(Stack_Int* stack)
{
    //Everytime we pop, we decrease top by 1. If top is -1, which is also the default value, we never pushed anything or popped everything.
    return stack->top == -1;
}

bool IsStackIntArrayFull(Stack_Int* stack)
{
    //If top in last index, stack is full
    return stack->top == stack->arraySize - 1;
}

void PushStack_Int(Stack_Int* stack, int valueToPush)
{
    if (IsStackIntArrayFull(stack))
    {
        printf("Error: Stack is full\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = valueToPush;
}

int PopStack_Int(Stack_Int* stack)
{
    if (IsStackIntArrayEmpty(stack))
    {
        printf("Error: Stack is empty, returning 0\n");
        return 0;
    }

    return stack->array[stack->top--];
}

int PeekStack_Int(Stack_Int* stack)
{
    if (IsStackIntArrayEmpty(stack))
    {
        printf("Error: Stack is empty, returning 0\n");
        return 0;
    }

    else return stack->array[stack->top];
}

void PrintStack_Int(Stack_Int* stack)
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

void RunStackTests(Stack_Int* stack)
{
    printf("() means top. Values that doesn't make sense are garbage values\n\n");

    //TESTS:
    //TRY TO PEEK AND POP WHILE EMPTY (NEVER ENQUEUED BEFORE)
    //PUSH AND PEEK
    //TRY TO PUSH WHILE FULL
    //POP AND PEEK
    //TRY TO PEEK AND POP WHILE EMPTY (POPPED EVERYTHING)

    //TRY TO PEEK AND POP WHILE EMPTY (NEVER ENQUEUED BEFORE)
    printf("Try to peek while empty (never pushed before), it will give empty queue error and return 0: %d\n", PeekStack_Int(stack));
    PrintStack_Int(stack);

    printf("Try to pop while empty (never pushed before), it will give empty queue error and return 0: %d\n", PopStack_Int(stack));
    PrintStack_Int(stack);
    //TRY TO PEEK AND POP WHILE EMPTY (NEVER ENQUEUED BEFORE)

    //PUSH AND PEEK
    PushStack_Int(stack, 5);
    printf("Push 5 and peek: %d\n", PeekStack_Int(stack));
    PrintStack_Int(stack);

    PushStack_Int(stack, 10);
    printf("Push 10 and peek: %d\n", PeekStack_Int(stack));
    PrintStack_Int(stack);

    PushStack_Int(stack, 15);
    printf("Push 15 and peek: %d\n", PeekStack_Int(stack));
    PrintStack_Int(stack);
    //PUSH AND PEEK

    //TRY TO PUSH WHILE FULL
    printf("Try to push 20 while full, it will give full capacity error\n");
    PushStack_Int(stack, 20);
    PrintStack_Int(stack);
    //TRY TO PUSH WHILE FULL

    //POP AND PEEK
    printf("Pop: %d\n", PopStack_Int(stack));
    PrintStack_Int(stack);

    printf("Peek: %d\n", PeekStack_Int(stack));
    PrintStack_Int(stack);

    printf("Pop: %d\n", PopStack_Int(stack));
    PrintStack_Int(stack);

    printf("Peek: %d\n", PeekStack_Int(stack));
    PrintStack_Int(stack);

    printf("Pop: %d\n", PopStack_Int(stack));
    PrintStack_Int(stack);
    //POP AND PEEK

    //TRY TO PEEK AND POP WHILE EMPTY (POPPED EVERYTHING)
    printf("Try to peek while empty (popped everything), it will give empty queue error and return 0: %d\n", PeekStack_Int(stack));
    PrintStack_Int(stack);

    printf("Try to pop while empty (popped everything), it will give empty queue error and return 0: %d\n", PopStack_Int(stack));
    PrintStack_Int(stack);
    //TRY TO PEEK AND POP WHILE EMPTY (POPPED EVERYTHING)
}

void TestInStackMemoryStack_Int()
{
    //Creating a stack that holds integer in stack memory
    int array[3];
    Stack_Int exampleStackIntArray;

    InitStack_Int(&exampleStackIntArray, array, 3);
    printf("A stack that holds integer with the size of 3 created in stack memory\n");

    RunStackTests(&exampleStackIntArray);
}

void TestInHeapMemoryStack_Int()
{
    //Creating a stack that holds integer in heap memory
    Stack_Int* exampleStackIntArray = CreateStack_Int(3);
    printf("A stack that holds integer with the size of 3 created in heap memory\n");

    RunStackTests(exampleStackIntArray);

    printf("Allocated memories for Stack_Int in heap memory freed");
    FreeStack_Int(exampleStackIntArray);
}