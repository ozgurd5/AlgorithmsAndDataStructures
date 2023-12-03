#include "Queue_Int.h"

void InitQueue_Int(Queue_Int* queue, int* array, size_t arraySize)
{
    //Link array
    queue->array = array;
    queue->arraySize = arraySize;

    //Assign default values
    queue->queueSize = 0;
    queue->head = 0;
    queue->tail = -1;
}

Queue_Int* CreateQueue_Int(size_t arraySize)
{
    Queue_Int* queue = (Queue_Int*) malloc(sizeof (Queue_Int));
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

void FreeQueue_Int(Queue_Int* queue)
{
    free(queue->array);
    free(queue);
}

bool IsQueueFull_Int(Queue_Int* queue)
{
    return queue->queueSize == queue->arraySize;
}

bool IsQueueEmpty_Int(Queue_Int* queue)
{
    return queue->queueSize == 0;
}

void EnqueueQueue_Int(Queue_Int* queue, int valueToEnqueue)
{
    if (IsQueueFull_Int(queue))
    {
        printf("Error: Queue is full\n");
        return;
    }

    queue->queueSize++;

    //To make the queue circular, we must not just increase the tail, we also ensure that after the last index of the array, tail must be point..
    //..to the first index of the array, so we can have a loop.
    queue->tail++;
    queue->tail = queue->tail % (int)queue->arraySize;

    queue->array[queue->tail] = valueToEnqueue;
}

int DequeueQueue_Int(Queue_Int* queue)
{
    if (IsQueueEmpty_Int(queue))
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

int PeekQueue_Int(Queue_Int* queue)
{
    if (IsQueueEmpty_Int(queue))
    {
        printf("Error: Queue is empty, returning 0\n");
        return 0;
    }

    return queue->array[queue->head];
}

void FlushQueue_Int(Queue_Int* queue)
{
    //TODO: SHOULD I MAKE THE SIZE ZERO INSTEAD OF DEQUEUE EVERYTHING?

    while (!IsQueueEmpty_Int(queue))
    {
        DequeueQueue_Int(queue);
    }
}

void PrintQueue_Int(Queue_Int* queue)
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

void RunQueueTests(Queue_Int* queue)
{
    printf("() means head, [] means tail. Values that doesn't make sense are garbage values\n\n");

    //TESTS:
    //TRY TO PEEK AND DEQUEUE WHILE EMPTY (NEVER ENQUEUED BEFORE)
    //ENQUEUE AND PEEK
    //TRY TO ENQUEUE WHILE FULL
    //DEQUEUE AND PEEK
    //TRY TO PEEK AND DEQUEUE WHILE EMPTY (DEQUEUED EVERYTHING)
    //ENQUEUE, FLUSH AND PEEK
    //ENQUEUE UNTIL FULL, FLUSH AND PEEK

    //PEEK AND DEQUEUE WHILE EMPTY (NEVER ENQUEUED BEFORE)
    printf("Try to peek while empty (never enqueued before), it will give empty queue error and return 0: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    printf("Try to dequeue while empty (never enqueued before), it will give empty queue error and return 0: %d\n", DequeueQueue_Int(queue));
    PrintQueue_Int(queue);
    //PEEK AND DEQUEUE WHILE EMPTY (NEVER ENQUEUED BEFORE)

    //ENQUEUE AND PEEK
    EnqueueQueue_Int(queue, 5);
    printf("Enqueue 5 and peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    EnqueueQueue_Int(queue, 10);
    printf("Enqueue 10 and peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    EnqueueQueue_Int(queue, 15);
    printf("Enqueue 15 and peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);
    //ENQUEUE AND PEEK

    //ENQUEUE WHILE FULL
    EnqueueQueue_Int(queue, 20);
    printf("Try to enqueue 20 while full, it will give full queue error\n");
    PrintQueue_Int(queue);
    //ENQUEUE WHILE FULL

    //DEQUEUE AND PEEK
    printf("Dequeue: %d\n", DequeueQueue_Int(queue));
    PrintQueue_Int(queue);

    printf("Peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    printf("Dequeue: %d\n", DequeueQueue_Int(queue));
    PrintQueue_Int(queue);

    printf("Peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    printf("Dequeue: %d\n", DequeueQueue_Int(queue));
    PrintQueue_Int(queue);
    //DEQUEUE AND PEEK

    //PEEK AND DEQUEUE WHILE EMPTY (DEQUEUED EVERYTHING)
    printf("Try to peek while empty (dequeued everything), it will give empty queue error and return 0: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    printf("Try to dequeue while empty (dequeued everything), it will give empty queue error and return 0: %d\n", DequeueQueue_Int(queue));
    PrintQueue_Int(queue);
    //PEEK AND DEQUEUE WHILE EMPTY (DEQUEUED EVERYTHING)

    //ENQUEUE, FLUSH AND PEEK
    EnqueueQueue_Int(queue, 5);
    printf("Enqueue 5 and peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    FlushQueue_Int(queue);
    printf("Flush the queue and try to peek, it will give empty queue error and return 0: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);
    //ENQUEUE, FLUSH AND PEEK

    //ENQUEUE UNTIL FULL, FLUSH AND PEEK
    EnqueueQueue_Int(queue, 5);
    printf("Enqueue 5 and peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    EnqueueQueue_Int(queue, 10);
    printf("Enqueue 10 and peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    EnqueueQueue_Int(queue, 15);
    printf("Enqueue 15 and peek: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);

    FlushQueue_Int(queue);
    printf("Flush the queue and try to peek, it will give empty queue error and return 0: %d\n", PeekQueue_Int(queue));
    PrintQueue_Int(queue);
    //ENQUEUE UNTIL FULL, FLUSH AND PEEK
}

void TestInStackMemoryQueue_Int()
{
    //Creating a queue that holds integer in stack memory
    int queueArray[3];
    Queue_Int exampleQueueIntArray;

    InitQueue_Int(&exampleQueueIntArray, queueArray, 3);
    printf("A queue that holds integer with the size of 3 created in stack memory\n");

    RunQueueTests(&exampleQueueIntArray);
}

void TestInHeapMemoryQueue_Int()
{
    //Creating a queue that holds integer in heap memory
    Queue_Int* exampleQueueIntArray = CreateQueue_Int(3);
    printf("A queue that holds integer with the size 3 created in heap memory\n");

    RunQueueTests(exampleQueueIntArray);

    printf("Allocated memories for Queue_Int in heap memory freed");
    FreeQueue_Int(exampleQueueIntArray);
}
