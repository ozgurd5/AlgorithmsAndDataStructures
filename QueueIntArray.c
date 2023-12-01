
#include "QueueIntArray.h"

void InitQueueIntArray(QueueIntArray* queue, int* array, size_t arraySize)
{
    //Link array
    queue->array = array;
    queue->arraySize = arraySize;

    //Assign default values
    queue->queueSize = 0;
    queue->head = 0;
    queue->tail = -1;
}

QueueIntArray* CreateQueueIntArray(size_t arraySize)
{
    //Create queue in heap memory
    QueueIntArray* queue = (QueueIntArray*) malloc(sizeof (QueueIntArray));

    //Create integer array in heap memory
    int* array = (int*) malloc(arraySize * sizeof (int));

    //Link array to the queue
    queue->array = array;
    queue->arraySize = arraySize;

    //Assign default values
    queue->queueSize = 0;
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
    return queue->queueSize == queue->arraySize;
}

bool IsQueueIntArrayEmpty(QueueIntArray* queue)
{
    return queue->queueSize == 0;
}

void EnqueueIntArray(QueueIntArray* queue, int valueToEnqueue)
{
    if (IsQueueIntArrayFull(queue))
    {
        printf("Error: Queue is full\n");
        return;
    }

    queue->queueSize++;

    //To make the queue circular, we must not just increase the tail, we also ensure that after the last index of the array, tail would be pointing..
    //..the first index of the array, so we can have a loop.
    queue->tail++;
    queue->tail = queue->tail % (int)queue->arraySize;

    queue->array[queue->tail] = valueToEnqueue;
}

int DequeueIntArray(QueueIntArray* queue)
{
    if (IsQueueIntArrayEmpty(queue))
    {
        printf("Error: Queue is empty, returning 0\n");
        return 0;
    }

    queue->queueSize--;

    //Same loop logic applies to the head too
    int valueToReturn = queue->array[queue->head];
    queue->head++;
    queue->head = queue->head % (int)queue->arraySize;

    return valueToReturn;
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
    printf("Head index: %d, Tail index: %d, Size: %lld -> Array: ", queue->head, queue->tail, queue->queueSize);

    for (int i = 0; i < queue->arraySize; ++i)
    {
        if (i == queue->tail) printf("[");
        if (i == queue->head) printf("(");

        printf("%d", queue->array[i]);

        if (i == queue->head) printf(")");
        if (i == queue->tail) printf("]");

        if (i == queue->arraySize - 1) printf("\n\n");
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

    printf("A queue that holds integer and using array with arraySize 3 created in stack memory\n");

    RunTests(&exampleQueueIntArray);
}

void RunTestsQueueIntArrayInHeapMemory()
{
    //Creating a queue that holds integer and using array in stack memory
    QueueIntArray* exampleQueueIntArray = CreateQueueIntArray(3);

    printf("A queue that holds integer and using array with arraySize 3 created in heap memory\n");

    RunTests(exampleQueueIntArray);

    printf("Allocated memories for QueueIntArray in heap memory freed");
    FreeQueueIntArray(exampleQueueIntArray);
}
