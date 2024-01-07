#include "Heap_Int.h"

void InitHeap_Int(Heap_Int* heap, int* array, size_t arraySize, bool isMaxHeap)
{
    heap->array = array;
    heap->arraySize = arraySize;
    heap->size = 0;
    heap->isMaxHeap = isMaxHeap;
}

Heap_Int* CreateHeap_Int(size_t arraySize, bool isMaxHeap)
{
    Heap_Int* heap = (Heap_Int*) malloc(sizeof(Heap_Int));

    heap->array = (int*) malloc(arraySize * sizeof(int));
    heap->arraySize = arraySize;
    heap->size = 0;
    heap->isMaxHeap = isMaxHeap;

    return heap;
}

void FreeHeap_Int(Heap_Int* heapToFree)
{
    free(heapToFree->array);
    free(heapToFree);
}

void AddHeap_Int(Heap_Int* heap, int valueToAdd)
{
    if (heap->size == heap->arraySize)
    {
        printf("Heap is full, can't add the value %d\n", valueToAdd);
        return;
    }

    heap->array[heap->size] = valueToAdd;
    heap->size++;

    if (heap->isMaxHeap) MaxHeapifyBottomUp_Int(heap);
    else MinHeapifyBottomUp_Int(heap);
}

void RemoveFromHeap_Int(Heap_Int* heap)
{
    if (heap->size == 0)
    {
        printf("Heap is empty, can't remove from heap\n");
        return;
    }

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    if (heap->isMaxHeap) MaxHeapifyTopDown_Int(heap);
    else MinHeapifyTopDown_Int(heap);
}

void MaxHeapifyTopDown_Int(Heap_Int* heap)
{
    if (heap->size == 1 || heap->size == 0) return;

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
    if (heap->size == 1 || heap->size == 0) return;

    size_t currentIndex = heap->size - 1;
    size_t currentParentIndex = GetParentIndexBinaryTree(heap->size);

    while(heap->array[currentIndex] > heap->array[currentParentIndex])
    {
        int tempValue = heap->array[currentIndex];
        heap->array[currentIndex] = heap->array[currentParentIndex];
        heap->array[currentParentIndex] = tempValue;

        currentIndex = currentParentIndex;
        currentParentIndex = GetParentIndexBinaryTree(currentIndex);

        if (currentIndex == 0) break;
    }
}

void MinHeapifyTopDown_Int(Heap_Int* heap)
{
    if (heap->size == 1 || heap->size == 0) return;

    size_t currentIndex = 0;
    size_t currentLeftChildIndex = 1;
    size_t currentRightChildIndex = 2;

    while (currentLeftChildIndex < heap->size && (heap->array[currentIndex] > heap->array[currentLeftChildIndex]
                                                  || heap->array[currentIndex] > heap->array[currentRightChildIndex]))
    {
        if (heap->array[currentLeftChildIndex] < heap->array[currentRightChildIndex])
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

void MinHeapifyBottomUp_Int(Heap_Int* heap)
{
    if (heap->size == 1 || heap->size == 0) return;

    size_t currentIndex = heap->size - 1;
    size_t currentParentIndex = GetParentIndexBinaryTree(heap->size);

    while(heap->array[currentIndex] < heap->array[currentParentIndex])
    {
        int tempValue = heap->array[currentIndex];
        heap->array[currentIndex] = heap->array[currentParentIndex];
        heap->array[currentParentIndex] = tempValue;

        currentIndex = currentParentIndex;
        currentParentIndex = GetParentIndexBinaryTree(currentIndex);

        if (currentIndex == 0) break;
    }
}

void TestHeap_Int(Heap_Int* heap)
{
    if (heap->isMaxHeap) printf("\n-----Max Heap-----\n");
    else printf("\n-----Min Heap-----\n");

    printf("\nTry to Remove Root from empty heap:\n");
    RemoveFromHeap_Int(heap);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 10:\n");
    AddHeap_Int(heap, 10);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nRemove Root:\n");
    RemoveFromHeap_Int(heap);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nTry to Remove Root from empty heap:\n");
    RemoveFromHeap_Int(heap);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 6:\n");
    AddHeap_Int(heap, 6);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 6 to test duplicates:\n");
    AddHeap_Int(heap, 6);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 20:\n");
    AddHeap_Int(heap, 20);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 20 to test duplicates::\n");
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

    printf("\nAdd -20:\n");
    AddHeap_Int(heap, -20);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd -40:\n");
    AddHeap_Int(heap, -40);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 1221:\n");
    AddHeap_Int(heap, 1221);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 90:\n");
    AddHeap_Int(heap, 90);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nAdd 50:\n");
    AddHeap_Int(heap, 50);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nTry to Add 120, which exceeds capacity:\n");
    AddHeap_Int(heap, 120);
    RawPrintBinaryTree_Int(heap->array, heap->size);

    printf("\nRemove Root:\n");
    RemoveFromHeap_Int(heap);
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
    int maxArray[12];
    Heap_Int maxHeap;
    InitHeap_Int(&maxHeap, maxArray, 12, true);
    TestHeap_Int(&maxHeap);

    int minArray[12];
    Heap_Int minHeap;
    InitHeap_Int(&minHeap, minArray, 12, false);
    TestHeap_Int(&minHeap);
}

void TestInHeapMemoryHeap_Int()
{
    Heap_Int* maxHeap = CreateHeap_Int(12, true);
    TestHeap_Int(maxHeap);
    FreeHeap_Int(maxHeap);

    Heap_Int* minHeap = CreateHeap_Int(12, false);
    TestHeap_Int(minHeap);
    FreeHeap_Int(minHeap);
}