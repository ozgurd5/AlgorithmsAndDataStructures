#include <stdio.h>
#include <stdlib.h>
#include "QueueIntArray.h"

void InitQueueIntArray(QueueIntArray* queue, int* array, size_t size)
{
    //Link array
    queue->array = array;
    queue->size = size;

    //Assign default values
    queue->head = 0;
    queue->tail = -1;
}

void EnqueueIntArray(QueueIntArray* queue, int valueToEnqueue)
{
    //TODO: full check after circular

    if (queue->tail == queue->size - 1) //If tail is at the end, it's full
    {
        printf("Error: Queue capacity full\n");
        return;
    }

    (queue->array)[++(queue->tail)] = valueToEnqueue; //TODO: circular
}

int DequeueIntArray(QueueIntArray* queue)
{
    //-1 is the default value of the tail

    //Everytime we dequeue, we increase head by 1. When there is only one item, head and tail will point the same item. After we dequeued..
    //..the last  item, head will be increased by 1 and point the next item. So if head = tail + 1 that means everything is dequeued

    if (queue->tail == -1 || queue->head == queue->tail + 1) //If never enqueued or dequeued everything
    {
        printf("Error: Queue is empty, returning 0\n");
        return 0;
    }

    return queue->array[(queue->head)++]; //TODO: circular
}

int PeekQueueIntArray(QueueIntArray* queue)
{
    //-1 is the default value of the tail

    //Everytime we dequeue, we increase head by 1. When there is only one item, head and tail will point the same item. After we dequeued..
    //..the last  item, head will be increased by 1 and point the next item. So if head = tail + 1 that means everything is dequeued

    if (queue->tail == -1 || queue->head == queue->tail + 1) //If never enqueued or dequeued everything
    {
        printf("Error: Queue is empty, returning 0\n");
        return 0;
    }

    return queue->array[queue->head];
}

//todo: flush

void PrintHeadAndTail(QueueIntArray* queue)
{
    printf("Head: %d, Tail: %d\n\n", queue->head, queue->tail);
}

int RunTestsQueueIntArrayInStackMemory()
{
    //Creating queue that holds integer and using array in stack memory
    int queueArray[3];
    QueueIntArray exampleQueueIntArray;
    InitQueueIntArray(&exampleQueueIntArray, queueArray, 3);

    printf("A queue that holds integer and using array with size 3 created in stack memory\n");
    PrintHeadAndTail(&exampleQueueIntArray);

    EnqueueIntArray(&exampleQueueIntArray, 5);
    printf("Enqueue 5 and peek: %d\n", PeekQueueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    EnqueueIntArray(&exampleQueueIntArray, 10);
    printf("Enqueue 10 and peek: %d\n", PeekQueueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    EnqueueIntArray(&exampleQueueIntArray, 15);
    printf("Enqueue 15 and peek: %d\n", PeekQueueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    EnqueueIntArray(&exampleQueueIntArray, 20);
    printf("Try to enqueue 20, it will give full queue error\n");
    PrintHeadAndTail(&exampleQueueIntArray);

    printf("Dequeue: %d\n", DequeueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    printf("Peek: %d\n", PeekQueueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    printf("Dequeue: %d\n", DequeueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    printf("Peek: %d\n", PeekQueueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    printf("Dequeue: %d\n", DequeueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    printf("Try to peek, it will give empty queue error and return 0: %d\n", PeekQueueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    printf("Try to dequeue, it will give empty queue error and return 0: %d\n", DequeueIntArray(&exampleQueueIntArray));
    PrintHeadAndTail(&exampleQueueIntArray);

    return 0;
}
