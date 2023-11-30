#ifndef ALGORITHMSANDDATASTRUCTURES_QUEUEINTARRAY_H
#define ALGORITHMSANDDATASTRUCTURES_QUEUEINTARRAY_H

typedef struct QueueIntArray QueueIntArray;
struct QueueIntArray
{
    int* array;
    size_t size;
    int head;
    int tail;
};

void RunTestsQueueIntArrayInStackMemory();

void EnqueueIntArray(QueueIntArray* queue, int valueToEnqueue);
int DequeueIntArray(QueueIntArray* queue);
int PeekQueueIntArray(QueueIntArray* queue);

#endif //ALGORITHMSANDDATASTRUCTURES_QUEUEINTARRAY_H
