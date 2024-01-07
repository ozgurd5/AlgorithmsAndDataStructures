#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BinaryTree.h"

typedef struct Heap_Int Heap_Int;
struct Heap_Int
{
    int* array;
    size_t arraySize;
    size_t size;
    bool isMaxHeap;
};

void TestInStackMemoryHeap_Int();
void TestInHeapMemoryHeap_Int();

void InitHeap_Int(Heap_Int* heap, int* array, size_t arraySize);
Heap_Int* CreateHeap_Int(size_t arraySize);
void FreeHeap_Int(Heap_Int* heapToFree);
void MaxHeapifyTopBottom_Int(Heap_Int* heap);
void MaxHeapifyBottomUp_Int(Heap_Int* heap);
void AddHeap_Int(Heap_Int* heap, int valueToAdd);
void RemoveFromHeap_Int(Heap_Int* heap);