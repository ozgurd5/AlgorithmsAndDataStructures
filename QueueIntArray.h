#ifndef ALGORITHMSANDDATASTRUCTURES_QUEUEINTARRAY_H
#define ALGORITHMSANDDATASTRUCTURES_QUEUEINTARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueIntArray QueueIntArray;
struct QueueIntArray
{
    int* array;

    ///Size of the array, may be empty or full, doesn't matter
    size_t arraySize;

    //queueSize is necessary to decide is the queue is full or empty, because in both conditions head =  tail + 1
    //If our queue wouldn't be circular, we wouldn't need this, but it is and we need this

    ///Size of the queue, only the full indexes
    size_t queueSize;

    int head;
    int tail;
};

void RunTestsQueueIntArrayInStackMemory();
void RunTestsQueueIntArrayInHeapMemory();

///Use this for debug purposes
void PrintQueueIntArray(QueueIntArray* queue);

///Use this for creating an integer queue in stack memory\n\n
///Makes the given integer queue ready to use by assigning default values and linking the given array to the queue.
void InitQueueIntArray(QueueIntArray* queue, int* array, size_t arraySize);

///Use this for creating an integer queue in heap memory\n\n
///Creates a QueueIntArray and an integer array in the heap memory, links the array to the queue, assigns default values and
///returns the created queue.
QueueIntArray* CreateQueueIntArray(size_t arraySize);

///Use this for destroying the queue in the heap memory\n\n
///Frees array of the queue and the queue itself
void FreeQueueIntArray(QueueIntArray* queue);

bool IsQueueIntArrayFull(QueueIntArray* queue);
bool IsQueueIntArrayEmpty(QueueIntArray* queue);

void EnqueueQueueIntArray(QueueIntArray* queue, int valueToEnqueue);
int DequeueQueueIntArray(QueueIntArray* queue);
int PeekQueueIntArray(QueueIntArray* queue);
void FlushQueueIntArray(QueueIntArray* queue);

#endif //ALGORITHMSANDDATASTRUCTURES_QUEUEINTARRAY_H
