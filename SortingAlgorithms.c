#include "SortingAlgorithms.h"

void SelectionSort_IntArray(int* array, size_t size)
{
    if (size == 1) return;

    for (size_t i = 0; i < size; ++i)
    {
        size_t biggestIndex = i;

        for (size_t j = i + 1; j < size; ++j)
        {
            if (array[j] > array[biggestIndex]) biggestIndex = j;
        }

        int temp = array[i];
        array[i] = array[biggestIndex];
        array[biggestIndex] = temp;
    }
}

void InsertionSort_IntArray(int* array, size_t size)
{
    if (size == 1) return;

    for (size_t i = 1; i < size; ++i)
    {
        size_t j = i;

        while (j != 0 && array[j] > array[j - 1])
        {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;

            j--;
        }
    }
}

void BubbleSort_IntArray(int* array, size_t size)
{
    if (size == 1) return;

    for (size_t i = 0; i < size; ++i)
    {
        size_t j = i + 1;

        if (array[i] < array[j])
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    BubbleSort_IntArray(array, size - 1);
}

void Merge_IntArray(int* array, size_t left, size_t middle, size_t right)
{
    size_t currentTempIndex = 0;
    size_t currentLeftIndex = left;
    size_t currentRightIndex = middle + 1;

    int temp[right + 1];

    while (currentLeftIndex <= middle && currentRightIndex <= right)
    {
        if (array[currentLeftIndex] > array[currentRightIndex])
        {
            temp[currentTempIndex] = array[currentLeftIndex];
            currentLeftIndex++;
        }

        else
        {
            temp[currentTempIndex] = array[currentRightIndex];
            currentRightIndex++;
        }

        currentTempIndex++;
    }

    if (currentLeftIndex > middle)
    {
        while (currentRightIndex <= right)
        {
            temp[currentTempIndex] = array[currentRightIndex];
            currentRightIndex++;
            currentTempIndex++;
        }
    }

    else
    {
        while (currentLeftIndex <= middle)
        {
            temp[currentTempIndex] = array[currentLeftIndex];
            currentLeftIndex++;
            currentTempIndex++;
        }
    }

    for (int i = 0; i < currentTempIndex; i++)
    {
        array[i] = temp[i];
    }
}

void MergeSortRecursion_IntArray(int* array, size_t left, size_t right)
{
    if (left >= right) return;

    size_t middle = left + ((right - left) / 2); //Prevents overflow

    MergeSortRecursion_IntArray(array, left, middle);
    MergeSortRecursion_IntArray(array, middle + 1, right);

    Merge_IntArray(array, left, middle, right);
}

void MergeSort_IntArray(int* array, size_t size)
{
    if (size == 1) return;

    MergeSortRecursion_IntArray(array, 0, size - 1);
}

void QuickSortPartition_IntArray(int* array, size_t left, size_t right, size_t* pivot)
{
    while (true)
    {
        while (array[*pivot] >= array[right] && *pivot != right)
        {
            right--;
        }

        if (*pivot == right) break;
        else if (array[*pivot] < array[right])
        {
            int temp = array[*pivot];
            array[*pivot] = array[right];
            array[right] = temp;

            *pivot = right;
        }

        while (array[*pivot] <= array[left] && *pivot != left)
        {
            left++;
        }

        if (*pivot == left) break;
        else if (array[*pivot] > array[left])
        {
            int temp = array[*pivot];
            array[*pivot] = array[left];
            array[left] = temp;

            *pivot = left;
        }
    }
}

void QuickSortRecursion_IntArray(int* array, size_t left, size_t right)
{
    if (left >= right) return;

    size_t pivot = left;
    QuickSortPartition_IntArray(array, left, right, &pivot);

    if (pivot == 0) return;
    QuickSortRecursion_IntArray(array, left, pivot - 1);
    QuickSortRecursion_IntArray(array, pivot + 1, right);
}

void QuickSort_IntArray(int* array, size_t size)
{
    if (size == 1) return;

    QuickSortRecursion_IntArray(array, 0, size - 1);
}

void HeapSort_IntArray(int* array, size_t size)
{
    int heapArray[size];
    Heap_Int heap;
    InitHeap_Int(&heap, heapArray, size, true);

    for (int i = 0; i < size; ++i)
    {
        AddHeap_Int(&heap, array[i]);
    }

    for (int i = 0; i < size; ++i)
    {
        array[i] = RemoveFromHeap_Int(&heap);
    }
}

void TestSelectionSort_IntArray()
{
    int array[] = {12, -33, 1, -51, 1213, 45, 66};

    printf("Array before sorting:\n");
    PrintSingleLineArray_Int(array, 7);

    printf("\nArray after sorting:\n");
    SelectionSort_IntArray(array, 7);
    PrintSingleLineArray_Int(array, 7);
}

void TestInsertionSort_IntArray()
{
    int array[] = {12, -33, 1, -51, 1213, 45, 66};

    printf("Array before sorting:\n");
    PrintSingleLineArray_Int(array, 7);

    printf("\nArray after sorting:\n");
    InsertionSort_IntArray(array, 7);
    PrintSingleLineArray_Int(array, 7);
}

void TestBubbleSort_IntArray()
{
    int array[] = {12, -33, 1, -51, 1213, 45, 66};

    printf("Array before sorting:\n");
    PrintSingleLineArray_Int(array, 7);

    printf("\nArray after sorting:\n");
    InsertionSort_IntArray(array, 7);
    PrintSingleLineArray_Int(array, 7);
}

/*void TestMergeSort_IntArray()
{
    int array[] = {12, -33, 1, -51, 1213, 45, 66};

    printf("Array before sorting:\n");
    PrintSingleLineArray_Int(array, 7);

    printf("\nArray after sorting:\n");
    MergeSort_IntArray(array, 7);
    PrintSingleLineArray_Int(array, 7);
}*/

void TestQuickSort_IntArray()
{
    int array[] = {12, -33, 1, -51, 1213, 45, 66};

    printf("Array before sorting:\n");
    PrintSingleLineArray_Int(array, 7);

    printf("\nArray after sorting:\n");
    QuickSort_IntArray(array, 7);
    PrintSingleLineArray_Int(array, 7);
}

void TestHeapSort_IntArray()
{
    int array[] = {12, -33, 1, -51, 1213, 45, 66};

    printf("Array before sorting:\n");
    PrintSingleLineArray_Int(array, 7);

    printf("\nArray after sorting:\n");
    HeapSort_IntArray(array, 7);
    PrintSingleLineArray_Int(array, 7);
}