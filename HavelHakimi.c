#include "HavelHakimi.h"

void SelectionSort_IntArray(int* array, size_t arraySize)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        int biggest = array[i];
        size_t biggestIndex = i;

        for (size_t j = i + 1; j < arraySize; ++j)
        {
            if (array[j] > biggest)
            {
                biggest = array[j];
                biggestIndex = j;
            }
        }

        int temp = array[i];
        array[i] = array[biggestIndex];
        array[biggestIndex] = temp;
    }
}

void PrintSingleLineArray_Int(int* array, size_t arraySize)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        printf("%d", array[i]);
        if (i == arraySize - 1) printf("\n");
        else printf(" - ");
    }
}

bool IsEveryElement0InArray_Int(int* array, size_t arraySize)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        if (array[i] != 0) return false;
    }

    return true;
}

bool HasNegativeInArray_Int(int* array, size_t arraySize)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        if (array[i] < 0) return true;
    }

    return false;
}

void CopyPasteArray(int* arrayToCopy, size_t arrayToCopySize, int* arrayToPaste, size_t arrayToPasteSize)
{
    size_t loopNumber;
    if (arrayToCopySize > arrayToPasteSize) loopNumber = arrayToPasteSize;
    else loopNumber = arrayToCopySize;

    for (size_t i = 0; i < loopNumber; ++i)
    {
        arrayToPaste[i] = arrayToCopy[i];
    }
}

bool RunHavelHakimi(int* array, size_t arraySize)
{
    //We shouldn't change the original array
    int copyArray[arraySize];
    CopyPasteArray(array, arraySize, copyArray, arraySize);
    printf("Given array           : ");
    PrintSingleLineArray_Int(copyArray, arraySize);


    if (IsEveryElement0InArray_Int(copyArray, arraySize))
    {
        printf("Every node is 0, graph with given degrees can exist\n\n");
        return true;
    }

    if (HasNegativeInArray_Int(copyArray, arraySize))
    {
        printf("There are negative numbers in the given array, graph with given degrees can not exist\n\n");
        return false;
    }

    while (!IsEveryElement0InArray_Int(copyArray, arraySize))
    {
        SelectionSort_IntArray(copyArray, arraySize);
        printf("Array after sorting   : ");
        PrintSingleLineArray_Int(copyArray, arraySize);

        int j;
        int decrementAmount = 0;
        for (j = 1; j <= copyArray[0]; ++j)
        {
            copyArray[j]--;
            decrementAmount++;

            if (j == arraySize || copyArray[j] < 0) break;
        }

        copyArray[0] -= decrementAmount;

        printf("Array after decrements: ");
        PrintSingleLineArray_Int(copyArray, arraySize);

        if (j == arraySize)
        {
            printf("Node linked to every other node but still has unused degree, graph with given degrees can not exist\n\n");
            return false;
        }

        else if (copyArray[j] < 0)
        {
            printf("Got negative number, graph with given degrees can not exist\n\n");
            return false;
        }
    }

    printf("Graph with given degrees can exist\n\n");
    return true;
}

void TestHavelHakimi()
{
    int arrayTrue[] = {2, 2, 5, 2, 2, 2, 3, 4};
    int arrayZero[] = {0, 0, 0, 0, 0 , 0, 0, 0};
    int arrayNegative[] = {-2, 12, 1, 123, 55, 13, 81, 1};
    int arrayUnusedDegree[] = {2, 2, 9, 2, 2, 2, 3, 4};
    int arrayGotNegative[] = {2, 1, 5, 2, 2, 2, 3, 4};

    RunHavelHakimi(arrayTrue, 8);
    RunHavelHakimi(arrayZero, 8);
    RunHavelHakimi(arrayNegative, 8);
    RunHavelHakimi(arrayUnusedDegree, 8);
    RunHavelHakimi(arrayGotNegative, 8);
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