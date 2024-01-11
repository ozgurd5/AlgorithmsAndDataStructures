#ifndef ALGORITHMSANDDATASTRUCTURES_SORTINGALGORITHMS_H
#define ALGORITHMSANDDATASTRUCTURES_SORTINGALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include "Array_Int.h"
#include "Heap_Int.h"

void SelectionSort_IntArray(int* array, size_t size);
void InsertionSort_IntArray(int* array, size_t size);
void BubbleSort_IntArray(int* array, size_t size);
void MergeSort_IntArray(int* array, size_t size);
void QuickSort_IntArray(int* array, size_t size);
void HeapSort_IntArray(int* array, size_t size);

void TestSelectionSort_IntArray();
void TestInsertionSort_IntArray();
void TestBubbleSort_IntArray();
//void TestMergeSort_IntArray();
void TestQuickSort_IntArray();
void TestHeapSort_IntArray();

#endif //ALGORITHMSANDDATASTRUCTURES_SORTINGALGORITHMS_H
