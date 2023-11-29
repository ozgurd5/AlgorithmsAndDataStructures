#include<stdio.h>

#define cap 5

void Enqueue(int* queue, int* front, int* rear, int valueToEnqueue)
{
    if (*front == -1) (*front)++; //if creating from scratch
    if (*rear == cap) //if full
    {
        printf("Capacity full\n");
        return;
    }

    (*rear)++;
    queue[*rear] = valueToEnqueue;
}

int Dequeue(int* queue, int* front, int* rear)
{
    if (*front == -1 || *front == (*rear) + 1) //if creating from scratch || queue ended
    {
        printf("Queue is empty, returning 0\n");
        return 0;
    }

    return queue[(*front)++];
}

int PeekQueue(int* queue, int* front, int* rear)
{
    if (*front == -1 || *front == (*rear) + 1) //if creating from scratch || queue ended
    {
        printf("Queue is empty, returning 0\n");
        return 0;
    }

    return queue[*front];
}

//flush
//edge cases

int RunQueueTests()
{
    int queue[cap];
    int front = -1;
    int rear = -1;

    printf("f: %d,r: %d\n", front, rear);
    Enqueue(queue, &front, &rear, 5);
    printf("enqueue 5 and peek: %d\n", PeekQueue(queue, &front, &rear));
    printf("f: %d,r: %d\n", front, rear);
    printf("dequeue: %d\n", Dequeue(queue, &front, &rear));
    printf("f: %d,r: %d\n", front, rear);
    printf("dequeue: %d\n", Dequeue(queue, &front, &rear)); //queue ended
    printf("f: %d,r: %d\n", front, rear);
    Enqueue(queue, &front, &rear, 10);
    printf("enqueue 10 and peek: %d\n", PeekQueue(queue, &front, &rear));
    printf("f: %d,r: %d\n", front, rear);
    Enqueue(queue, &front, &rear, 8);
    printf("enqueue 8 and peek: %d\n", PeekQueue(queue, &front, &rear));
    printf("f: %d,r: %d\n", front, rear);
    printf("dequeue: %d\n", Dequeue(queue, &front, &rear));
    printf("f: %d,r: %d\n", front, rear);
    printf("dequeue: %d\n", Dequeue(queue, &front, &rear));
    printf("f: %d,r: %d\n", front, rear);
    printf("dequeue: %d\n", Dequeue(queue, &front, &rear)); //queue ended
    printf("f: %d,r: %d\n", front, rear);

    return 0;
}
