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
void RunTestsQueueIntArrayInHeapMemory();

///Use this for creating an integer queue in stack memory\n\n
///Makes the given integer queue ready to use by assigning default values and linking the given array to the queue.
void InitQueueIntArray(QueueIntArray* queue, int* array, size_t size);

///Use this for creating an integer queue in heap memory\n\n
///Creates a QueueIntArray and an integer array in the heap memory, links the array to the queue, assigns default values and
///returns the created queue.
QueueIntArray* CreateQueueIntArray(size_t size);

///Use this for destroying the queue in the heap memory\n\n
///Frees array of the queue and the queue itself
void FreeQueueIntArray(QueueIntArray* queue);

///Use this for debug purposes
void PrintQueueIntArray(QueueIntArray* queue);

void EnqueueIntArray(QueueIntArray* queue, int valueToEnqueue);
int DequeueIntArray(QueueIntArray* queue);
int PeekQueueIntArray(QueueIntArray* queue);

#endif //ALGORITHMSANDDATASTRUCTURES_QUEUEINTARRAY_H
