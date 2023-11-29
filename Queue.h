#ifndef ALGORITHMSANDDATASTRUCTURES_QUEUE_H
#define ALGORITHMSANDDATASTRUCTURES_QUEUE_H

int RunQueueTests();
void Enqueue(int* queue, int* front, int* rear, int valueToEnqueue);
int Dequeue(int* queue, int* front, int* rear);
int PeekQueue(int* queue, int* front, int* rear);

#endif //ALGORITHMSANDDATASTRUCTURES_QUEUE_H
