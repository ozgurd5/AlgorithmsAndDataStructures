#ifndef ALGORITHMSANDDATASTRUCTURES_QUEUE_INT_H
#define ALGORITHMSANDDATASTRUCTURES_QUEUE_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue_Int Queue_Int;
struct Queue_Int
{
    int* array;

    ///\n Size of the array, may be empty or full, doesn't matter
    size_t arraySize;

    //queueSize is necessary to decide is the queue is full or empty, because in both conditions head =  tail + 1
    //If our queue wouldn't be circular, we wouldn't need this, but it is and we need this

    ///\n Size of the queue, only the full indexes
    size_t queueSize;

    int head;
    int tail;
};

void TestInStackMemoryQueue_Int();
void TestInHeapMemoryQueue_Int();

///\n Use this for debug purposes
void PrintQueue_Int(Queue_Int* queue);

///\n Use this for creating an integer queue in stack memory\n\n
///Makes the given integer queue ready to use by assigning default values and linking the given array to the queue.
void InitQueue_Int(Queue_Int* queue, int* array, size_t arraySize);

///\n Use this for creating an integer queue in heap memory\n\n
///Creates a Queue_Int and an integer array in the heap memory, links the array to the queue, assigns default values and
///returns the created queue.
Queue_Int* CreateQueue_Int(size_t arraySize);

///\n Use this for destroying the queue in the heap memory\n\n
///Frees array of the queue and the queue itself
void FreeQueue_Int(Queue_Int* queue);

bool IsQueueFull_Int(Queue_Int* queue);
bool IsQueueEmpty_Int(Queue_Int* queue);

void EnqueueQueue_Int(Queue_Int* queue, int valueToEnqueue);
int DequeueQueue_Int(Queue_Int* queue);
int PeekQueue_Int(Queue_Int* queue);
void FlushQueue_Int(Queue_Int* queue);

#endif //ALGORITHMSANDDATASTRUCTURES_QUEUE_INT_H
