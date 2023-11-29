#include<stdio.h>
#include "Stack.h"

#define cap 2

void Push(int* stack, int* top, int valueToPush)
{
    if (*top == cap - 1)
    {
        printf("Capacity full\n");
        return;
    }

    (*top)++;
    stack[*top] = valueToPush;
}

int Pop(int* stack, int* top)
{
    if (*top == -1)
    {
        printf("Stack is empty, returning 0\n");
        return 0;
    }

    return stack[(*top)--];
}

int PeekStack(int* stack, int* top)
{
    if (*top == -1)
    {
        printf("Stack is empty, returning 0\n");
        return 0;
    }

    else return stack[*top];
}

int RunStackTests()
{
    int stack[cap];
    int top = -1;

    int num = PeekStack(stack, &top); //empty error
    num = Pop(stack, &top); //empty error

    Push(stack, &top, 5);
    printf("push 5 and peek: %d\n", PeekStack(stack, &top));

    Push(stack, &top, 10);
    printf("push 10 and peek: %d\n", PeekStack(stack, &top));
    printf("pop: %d\n", Pop(stack, &top));
    printf("peek: %d\n", PeekStack(stack, &top));
    Push(stack, &top, 10);
    Push(stack, &top, 10); //cap full error

    return 0;
}
