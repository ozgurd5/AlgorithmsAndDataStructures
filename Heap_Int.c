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

void MaxHeapifyTopBottom_Int(Heap_Int* heap)
{
    if (heap->size == 1) return;

    size_t currentIndex = 0;
    size_t currentLeftChildIndex = 1;
    size_t currentRightChildIndex = 2;

    while (currentLeftChildIndex < heap->size && (heap->array[currentIndex] < heap->array[currentLeftChildIndex]
            || heap->array[currentIndex] < heap->array[currentRightChildIndex]))
    {
        if (heap->array[currentLeftChildIndex] > heap->array[currentRightChildIndex])
        {
            int temp = heap->array[currentIndex];
            heap->array[currentIndex] = heap->array[currentLeftChildIndex];
            heap->array[currentLeftChildIndex] = temp;

            currentIndex = currentLeftChildIndex;
        }

        else
        {
            int temp = heap->array[currentIndex];
            heap->array[currentIndex] = heap->array[currentRightChildIndex];
            heap->array[currentRightChildIndex] = temp;

            currentIndex = currentRightChildIndex;
        }

        currentLeftChildIndex = GetLeftChildIndexBinaryTree(currentIndex);
        currentRightChildIndex = GetRightChildIndexBinaryTree(currentIndex);
    }

}

void MaxHeapifyBottomUp_Int(Heap_Int* heap)
{
    if (heap->size == 1) return;

    size_t currentIndex = heap->size - 1;
    size_t currentParentIndex = GetParentIndexBinaryTree(heap->size);

    while(heap->array[currentIndex] > heap->array[currentParentIndex])
    {
        int tempValue = heap->array[currentIndex];
        heap->array[currentIndex] = heap->array[currentParentIndex];
        heap->array[currentParentIndex] = tempValue;

        currentIndex = currentParentIndex;
        currentParentIndex = GetParentIndexBinaryTree(currentIndex);

        if (currentIndex == 0) return;
    }
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
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 6:\n");
    AddHeap_Int(heap, 6);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 20:\n");
    AddHeap_Int(heap, 20);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 30:\n");
    AddHeap_Int(heap, 30);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 25:\n");
    AddHeap_Int(heap, 25);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 15:\n");
    AddHeap_Int(heap, 15);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 13312:\n");
    AddHeap_Int(heap, 13312);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nRemove Root:\n");
    RemoveFromHeap_Int(heap);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nRemove Root:\n");
    RemoveFromHeap_Int(heap);
    RawPrintBinaryTree_Int(heap->array, heap->size);
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