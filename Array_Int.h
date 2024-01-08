#ifndef ALGORITHMSANDDATASTRUCTURES_ARRAY_INT_H
#define ALGORITHMSANDDATASTRUCTURES_ARRAY_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_BST_NODE INT_MIN
#define INVALID_BST_INDEX -1

void TestArray_Int();

void PrintSingleLineArray_Int(int* array, size_t size);
bool HasNegativeInArray_Int(int* array, size_t size);
bool IsEveryElement0InArray_Int(int* array, size_t size);
void CopyPasteArray_Int(int* arrayToCopy, size_t arrayToCopySize, int* arrayToPaste, size_t arrayToPasteSize);
void RotateArray_Int(int* array, size_t size, bool isRotatingRight);
void ClearArrayUsingZero_Int(int* array, size_t size);
void ClearArrayUsingGivenValue_Int(int* array, size_t size, int givenValue);

void SelectionSort_IntArray(int* array, size_t arraySize);
void TestSelectionSort_IntArray();

#endif //ALGORITHMSANDDATASTRUCTURES_ARRAY_INT_H
