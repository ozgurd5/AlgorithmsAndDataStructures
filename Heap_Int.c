#include "Heap_Int.h"

void InitHeap_Int(Heap_Int* heap, int* array, size_t arraySize)
{
    heap->array = array;
    heap->arraySize = arraySize;
    heap->size = 0;
    heap->isMaxHeap = true;
}

Heap_Int* CreateHeap_Int(size_t arraySize)
{
    Heap_Int* heap = (Heap_Int*) malloc(sizeof(Heap_Int));

    heap->array = (int*) malloc(arraySize * sizeof(int));
    heap->arraySize = arraySize;
    heap->size = 0;
    heap->isMaxHeap = true;

    return heap;
}

void FreeHeap_Int(Heap_Int* heapToFree)
{
    free(heapToFree->array);
    free(heapToFree);
}

void RawPrintHeap_Int(Heap_Int* heap)
{
    size_t currentNodeIndex = 0;
    int nodeCapacityInLine = 1;
    int nodeInCurrentLine = 0;

    while(currentNodeIndex != heap->size)
    {
        printf("%d(%lld)", heap->array[currentNodeIndex], currentNodeIndex);

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

    if (nodeInCurrentLine != 0) printf("\n");
}

//TODO: code repetition with binary search tree
size_t GetParentIndexHeap_Int(size_t index)
{
    size_t parentIndex;
    if (index % 2 == 1) parentIndex = index / 2;
    else parentIndex = index / 2 - 1;

    return parentIndex;
}

size_t GetLeftChildIndexHeap_Int(size_t index)
{
    return index * 2 + 1;
}

size_t GetRightChildIndexHeap_Int(size_t index)
{
    return index * 2 + 2;
}

void MaxHeapifyTopBottom_Int(Heap_Int* heap)
{
    if (heap->size == 1) return;

    size_t currentIndex = 0;
    size_t currentChildIndex = 1;

    while (heap->array[currentIndex] < heap->array[currentChildIndex])
    {
        int tempValue = heap->array[currentIndex];
        heap->array[currentIndex] = heap->array[currentChildIndex];
        heap->array[currentChildIndex] = tempValue;

        currentChildIndex++;
    }

    heap->isMaxHeap = true;
}

void MaxHeapifyBottomUp_Int(Heap_Int* heap)
{
    if (heap->size == 1) return;

    size_t currentIndex = heap->size - 1;
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

    heap->isMaxHeap = true;
}

void AddHeap_Int(Heap_Int* heap, int valueToAdd)
{
    heap->array[heap->size] = valueToAdd;
    heap->size++;
    if (heap->isMaxHeap) MaxHeapifyBottomUp_Int(heap);
}

void RemoveFromHeap_Int(Heap_Int* heap)
{
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    if (heap->isMaxHeap) MaxHeapifyTopBottom_Int(heap);
}

void TestHeap_Int(Heap_Int* heap)
{
    printf("--Max Heap--\n");

    printf("\nAdd 10:\n");
    AddHeap_Int(heap, 10);
    RawPrintHeap_Int(heap);

    printf("\nAdd 6:\n");
    AddHeap_Int(heap, 6);
    RawPrintHeap_Int(heap);

    printf("\nAdd 20:\n");
    AddHeap_Int(heap, 20);
    RawPrintHeap_Int(heap);

    printf("\nAdd 30:\n");
    AddHeap_Int(heap, 30);
    RawPrintHeap_Int(heap);

    printf("\nAdd 25:\n");
    AddHeap_Int(heap, 25);
    RawPrintHeap_Int(heap);

    printf("\nAdd 15:\n");
    AddHeap_Int(heap, 15);
    RawPrintHeap_Int(heap);

    printf("\nAdd 50:\n");
    AddHeap_Int(heap, 50);
    RawPrintHeap_Int(heap);

    printf("\nAdd 13312:\n");
    AddHeap_Int(heap, 13312);
    RawPrintHeap_Int(heap);

    printf("\nRemove Root:\n");
    RemoveFromHeap_Int(heap);
    RawPrintHeap_Int(heap);
}

void TestInStackMemoryHeap_Int()
{
    int array[15];
    Heap_Int heap;
    InitHeap_Int(&heap, array, 15);

    TestHeap_Int(&heap);
}

void TestInHeapMemoryHeap_Int()
{
    Heap_Int* heap = CreateHeap_Int(15);
    TestHeap_Int(heap);

    TestHeap_Int(heap);
    FreeHeap_Int(heap);
}