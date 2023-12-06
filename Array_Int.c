#include "Array_Int.h"

void PrintSingleLineArray_Int(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("%lld: %d", i, array[i]);
        if (i == size - 1) printf("\n");
        else printf(" / ");
    }
}

void PrintArray_Int(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("%lld: %d\n", i, array[i]);
    }
}

bool IsEveryElement0InArray_Int(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != 0) return false;
    }

    return true;
}

bool HasNegativeInArray_Int(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] < 0) return true;
    }

    return false;
}

void CopyPasteArray_Int(int* arrayToCopy, size_t arrayToCopySize, int* arrayToPaste, size_t arrayToPasteSize)
{
    size_t loopNumber;
    if (arrayToCopySize > arrayToPasteSize) loopNumber = arrayToPasteSize;
    else loopNumber = arrayToCopySize;

    for (size_t i = 0; i < loopNumber; ++i)
    {
        arrayToPaste[i] = arrayToCopy[i];
    }
}

void ReverseArray_Int(int* array, size_t size)
{
    int temp;

    //i starts from beginning and goes to the middle, j starts from the end and goes to the middle
    size_t j = size - 1;
    for (size_t i = 0; i < size / 2; ++i)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        j--;
    }
}

void RotateArray_Int(int* array, size_t size, bool isRotatingRight)
{
    if (isRotatingRight)
    {
        int last = array[size - 1];

        for (size_t i = size - 1 ; i > 0; --i)
        {
            array[i] = array[i - 1];
        }

        array[0] = last;
    }

    else
    {
        int first = array[0];

        for (size_t i = 0; i < size - 1; ++i)
        {
            array[i] = array [i + 1];
        }

        array[size - 1] = first;
    }
}

void ClearArray_Int(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = 0;
    }
}

void TestArray_Int()
{
    //TESTS
    //PRINT
    //PRINT SINGLE LINE
    //IS EVERY ELEMENT 0
    //HAS NEGATIVE
    //COPY PASTE - SAME SIZE
    //COPY PASTE - COPY BIGGER
    //COPY PASTE - PASTE BIGGER
    //REVERSE - ODD
    //REVERSE - EVEN
    //ROTATE RIGHT
    //ROTATE LEFT
    //CLEAR

    int arrayPositive[] = {1, 2, 3, 4, 5, 6};
    int arrayNegative[] = {-1, -2, -3, -4, -5, -6};
    int arrayZero[] = {0, 0, 0, 0, 0, 0};

    int arraySmall1[] = {10, 20, 30, 40};
    int arrayBig1[] = {50, 60, 70, 80, 90, 100};

    int arraySmall2[] = {100, 200, 300, 400};
    int arrayBig2[] = {500, 600, 700, 800, 900, 1000};

    int arrayOdd[] = {1, 2, 3, 4, 5};
    int arrayEven[] = {1, 2, 3, 4};

    //PRINT
    printf("Positive array:\n");
    PrintArray_Int(arrayPositive, 6);
    //PRINT

    //PRINT SINGLE LINE
    printf("Negative array: ");
    PrintSingleLineArray_Int(arrayNegative, 6);
    printf("Zero array: ");
    PrintSingleLineArray_Int(arrayZero, 6);
    //PRINT SINGLE LINE

    //IS EVERY ELEMENT 0
    printf("\nIs every element zero for Positive Array: %d\n", IsEveryElement0InArray_Int(arrayPositive, 6));
    printf("Is every element zero for Negative Array: %d\n", IsEveryElement0InArray_Int(arrayNegative, 6));
    printf("Is every element zero for Zero Array: %d\n", IsEveryElement0InArray_Int(arrayZero, 6));
    //IS EVERY ELEMENT 0

    //HAS NEGATIVE
    printf("\nHas Positive Array negative: %d\n", HasNegativeInArray_Int(arrayPositive, 6));
    printf("Has Negative Array negative: %d\n", HasNegativeInArray_Int(arrayNegative, 6));
    printf("Has Zero Array negative: %d\n", HasNegativeInArray_Int(arrayZero, 6));
    //HAS NEGATIVE

    //COPY PASTE - SAME SIZE
    printf("\nCopy Positive Array and paste to the Negative Array:\n");
    CopyPasteArray_Int(arrayPositive, 6, arrayNegative, 6);

    printf("Positive array: ");
    PrintSingleLineArray_Int(arrayPositive, 6);
    printf("Negative array: ");
    PrintSingleLineArray_Int(arrayNegative, 6);
    //COPY PASTE - SAME SIZE

    //COPY PASTE - COPY BIGGER
    printf("\nSmaller Array: ");
    PrintSingleLineArray_Int(arraySmall1, 4);
    printf("Bigger Array: ");
    PrintSingleLineArray_Int(arrayBig1, 6);

    printf("\nCopy Bigger Array and paste to the Smaller Array:\n");
    CopyPasteArray_Int(arrayBig1, 6, arraySmall1, 4);
    printf("Smaller Array: ");
    PrintSingleLineArray_Int(arraySmall1, 4);
    printf("Bigger Array: ");
    PrintSingleLineArray_Int(arrayBig1, 6);
    //COPY PASTE - COPY BIGGER

    //COPY PASTE - COPY SMALLER
    printf("\nSmaller Array: ");
    PrintSingleLineArray_Int(arraySmall2, 4);
    printf("Bigger Array: ");
    PrintSingleLineArray_Int(arrayBig2, 6);

    printf("\nCopy Smaller Array and paste to the Bigger Array:\n");
    CopyPasteArray_Int(arraySmall2, 6, arrayBig2, 4);
    printf("Smaller Array: ");
    PrintSingleLineArray_Int(arraySmall2, 4);
    printf("Bigger Array: ");
    PrintSingleLineArray_Int(arrayBig2, 6);
    //COPY PASTE - COPY SMALLER

    //REVERSE - ODD
    printf("\nOdd Array: ");
    PrintSingleLineArray_Int(arrayOdd, 5);
    ReverseArray_Int(arrayOdd, 5);

    printf("Odd Array reversed: ");
    PrintSingleLineArray_Int(arrayOdd, 5);
    //REVERSE - ODD

    //REVERSE - EVEN
    printf("\nEven Array: ");
    PrintSingleLineArray_Int(arrayEven, 4);
    ReverseArray_Int(arrayEven, 4);

    printf("Even Array reversed: ");
    PrintSingleLineArray_Int(arrayEven, 4);
    //REVERSE - EVEN

    //ROTATE RIGHT
    printf("\nArray Positive rotated right: ");
    RotateArray_Int(arrayPositive, 6, true);
    PrintSingleLineArray_Int(arrayPositive, 6);
    printf("Array Positive rotated right again: ");
    RotateArray_Int(arrayPositive, 6, true);
    PrintSingleLineArray_Int(arrayPositive, 6);
    //ROTATE RIGHT

    //ROTATE LEFT
    printf("\nArray Negative (which is same as the positive) rotated left: ");
    RotateArray_Int(arrayNegative, 6, false);
    PrintSingleLineArray_Int(arrayNegative, 6);
    printf("Array Negative (which is same as the positive) rotated left again: ");
    RotateArray_Int(arrayNegative, 6, false);
    PrintSingleLineArray_Int(arrayNegative, 6);
    //ROTATE LEFT

    //CLEAR
    printf("\nArray Negative (which is same as the positive) after cleaning: ");
    ClearArray_Int(arrayNegative, 6);
    PrintSingleLineArray_Int(arrayNegative, 6);
    //CLEAR
}

//

void SelectionSort_IntArray(int* array, size_t arraySize)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        size_t biggestIndex = i;

        for (size_t j = i + 1; j < arraySize; ++j)
        {
            if (array[j] > array[biggestIndex]) biggestIndex = j;
        }

        int temp = array[i];
        array[i] = array[biggestIndex];
        array[biggestIndex] = temp;
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