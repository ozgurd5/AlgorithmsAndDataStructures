#include "Heap_Int.h"

void InitHeap_Int(Heap_Int* heap, int* array)
{
    heap->array = array;
    heap->size = -1;
}

void RawPrintHeap_Int(Heap_Int* heap)
{
    int currentNodeIndex = 0;
    int nodeCapacityInLine = 1;
    int nodeInCurrentLine = 0;

    while(currentNodeIndex != heap->size)
    {
        printf("%d(%d)", heap->array[currentNodeIndex], currentNodeIndex);

        nodeInCurrentLine++;
        currentNodeIndex++;

        if (nodeInCurrentLine == nodeCapacityInLine)
        {
            printf("\n");

            nodeCapacityInLine *= 2;
            nodeInCurrentLine = 0;
        }

        else printf("-");
    }
}

//TODO: code repetition with binary search tree
size_t GetParentIndexHeap_Int(size_t index)
{
    size_t parentIndex;
    if (index % 2 == 1) parentIndex = index / 2;
    else parentIndex = index / 2 - 1;

    return parentIndex;
}

void MaxHeapify_Int(Heap_Int* heap)
{
    if (heap->size == 0) return;

    size_t currentIndex = heap->size;
    size_t currentParentIndex = GetParentIndexHeap_Int(heap->size);

    while(heap->array[currentIndex] > heap->array[currentParentIndex])
    {
        int tempValue = heap->array[currentIndex];
        heap->array[currentIndex] = heap->array[currentParentIndex];
        heap->array[currentParentIndex] = tempValue;

        currentIndex = currentParentIndex;
        currentParentIndex = GetParentIndexHeap_Int(currentIndex);

        if (currentIndex == 0) return;
    }
}

void AddHeap_Int(Heap_Int* heap, int valueToAdd)
{
    heap->size++;
    heap->array[heap->size] = valueToAdd;
    MaxHeapify_Int(heap);
}

void TestHeap_Int()
{
    int array[32];
    Heap_Int heapInt;
    InitHeap_Int(&heapInt, array);

    AddHeap_Int(&heapInt, 10);
    AddHeap_Int(&heapInt, 12);
    AddHeap_Int(&heapInt, 30);
    AddHeap_Int(&heapInt, 15);
    AddHeap_Int(&heapInt, 14);
    AddHeap_Int(&heapInt, 7);
    AddHeap_Int(&heapInt, 8);
    AddHeap_Int(&heapInt, 22);
    AddHeap_Int(&heapInt, 65);
    AddHeap_Int(&heapInt, 96);
    AddHeap_Int(&heapInt, 120);
    AddHeap_Int(&heapInt, 1443);

    RawPrintHeap_Int(&heapInt);
}