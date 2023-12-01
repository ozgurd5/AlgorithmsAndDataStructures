#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

QueueIntArray* CreateQueueIntArray(size_t size)
{
    //Create queue in heap memory
    QueueIntArray* queue = (QueueIntArray*) malloc(sizeof (QueueIntArray));

    //Create integer array in heap memory
    int* array = (int*) malloc(size * sizeof (int));

    //Link array to the queue
    queue->array = array;
    queue->size = size;

    //Assign default values
    queue->head = 0;
    queue->tail = -1;

    return queue;
}

void FreeQueueIntArray(QueueIntArray* queue)
{
    free(queue->array);
    free(queue);
}

bool IsQueueIntArrayFull(QueueIntArray* queue)
{
    //If tail is at the end, it's full
    return queue->tail == queue->size - 1;
}

bool IsQueueIntArrayEmpty(QueueIntArray* queue)
{
    //-1 is the default value of the tail, that means we never enqueued before

    //Everytime we dequeue, we increase head by 1. When there is only one item, head and tail will point the same item. After we dequeued..
    //..the last item, head will be increased by 1 and point the next item. So if head = tail + 1, everything is dequeued

    //If never enqueued or dequeued everything
    return queue->tail == -1 || queue->head == queue->tail + 1;
}

void EnqueueIntArray(QueueIntArray* queue, int valueToEnqueue)
{
    if (IsQueueIntArrayFull(queue))
    {
        printf("Error: Queue is full\n");
        return;
    }

    (queue->array)[++(queue->tail)] = valueToEnqueue; //TODO: circular
}

int DequeueIntArray(QueueIntArray* queue)
{
    if (IsQueueIntArrayEmpty(queue))
    {
        printf("Error: Queue is empty, returning 0\n");
        return 0;
    }

    return queue->array[(queue->head)++]; //TODO: circular
}

int PeekQueueIntArray(QueueIntArray* queue)
{
    if (IsQueueIntArrayEmpty(queue))
    {
        printf("Error: Queue is empty, returning 0\n");
        return 0;
    }

    return queue->array[queue->head];
}

void PrintQueueIntArray(QueueIntArray* queue)
{
    printf("Head index: %d, Tail index: %d -> Array: ", queue->head, queue->tail);

    for (int i = 0; i < queue->size; ++i)
    {
        if (i == queue->tail) printf("[");
        if (i == queue->head) printf("(");

        printf("%d", queue->array[i]);

        if (i == queue->head) printf(")");
        if (i == queue->tail) printf("]");

        if (i == queue->size -1) printf("\n\n");
        else printf(", ");
    }
}

void RunTests(QueueIntArray* queue)
{
    printf("() means head, [] means tail. Values that doesn't make sense are garbage values\n\n");

    PrintQueueIntArray(queue);

    printf("Try to peek while empty (never enqueued before), it will give empty queue error and return 0: %d\n", PeekQueueIntArray(queue));
    PrintQueueIntArray(queue);

    printf("Try to dequeue while empty (never enqueued before), it will give empty queue error and return 0: %d\n", DequeueIntArray(queue));
    PrintQueueIntArray(queue);

    EnqueueIntArray(queue, 5);
    printf("Enqueue 5 and peek: %d\n", PeekQueueIntArray(queue));
    PrintQueueIntArray(queue);

    EnqueueIntArray(queue, 10);
    printf("Enqueue 10 and peek: %d\n", PeekQueueIntArray(queue));
    PrintQueueIntArray(queue);

    EnqueueIntArray(queue, 15);
    printf("Enqueue 15 and peek: %d\n", PeekQueueIntArray(queue));
    PrintQueueIntArray(queue);

    EnqueueIntArray(queue, 20);
    printf("Try to enqueue 20 while full, it will give full queue error\n");
    PrintQueueIntArray(queue);

    printf("Dequeue: %d\n", DequeueIntArray(queue));
    PrintQueueIntArray(queue);

    printf("Peek: %d\n", PeekQueueIntArray(queue));
    PrintQueueIntArray(queue);

    printf("Dequeue: %d\n", DequeueIntArray(queue));
    PrintQueueIntArray(queue);

    printf("Peek: %d\n", PeekQueueIntArray(queue));
    PrintQueueIntArray(queue);

    printf("Dequeue: %d\n", DequeueIntArray(queue));
    PrintQueueIntArray(queue);

    printf("Try to peek while empty (dequeued everything), it will give empty queue error and return 0: %d\n", PeekQueueIntArray(queue));
    PrintQueueIntArray(queue);

    printf("Try to dequeue while empty (dequeued everything), it will give empty queue error and return 0: %d\n", DequeueIntArray(queue));
    PrintQueueIntArray(queue);
}

void RunTestsQueueIntArrayInStackMemory()
{
    //Creating a queue that holds integer and using array in stack memory
    int queueArray[3];
    QueueIntArray exampleQueueIntArray;
    InitQueueIntArray(&exampleQueueIntArray, queueArray, 3);

    printf("A queue that holds integer and using array with size 3 created in stack memory\n");

    RunTests(&exampleQueueIntArray);
}

void RunTestsQueueIntArrayInHeapMemory()
{
    //Creating a queue that holds integer and using array in stack memory
    QueueIntArray* exampleQueueIntArray = CreateQueueIntArray(3);

    printf("A queue that holds integer and using array with size 3 created in heap memory\n");

    RunTests(exampleQueueIntArray);

    printf("Allocated memories for QueueIntArray in heap memory freed");
    FreeQueueIntArray(exampleQueueIntArray);
}
