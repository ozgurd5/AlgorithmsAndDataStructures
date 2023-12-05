#ifndef ALGORITHMSANDDATASTRUCTURES_ARRAY_INT_H
#define ALGORITHMSANDDATASTRUCTURES_ARRAY_INT_H

#include <stdio.h>
#include <stdbool.h>

void TestArray_Int();

void PrintSingleLineArray_Int(int* array, size_t size);
bool HasNegativeInArray_Int(int* array, size_t size);
bool IsEveryElement0InArray_Int(int* array, size_t size);
void CopyPasteArray_Int(int* arrayToCopy, size_t arrayToCopySize, int* arrayToPaste, size_t arrayToPasteSize);

void SelectionSort_IntArray(int* array, size_t arraySize);
void TestSelectionSort_IntArray();

#endif //ALGORITHMSANDDATASTRUCTURES_ARRAY_INT_H
