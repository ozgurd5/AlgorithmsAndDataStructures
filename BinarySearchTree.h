#ifndef ALGORITHMSANDDATASTRUCTURES_BINARYSEARCHTREE_H
#define ALGORITHMSANDDATASTRUCTURES_BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Array_Int.h"

///\n 0th index must NOT be empty
///\n\n Value 0 means empty
typedef struct BinarySearchTree BinarySearchTree;
struct BinarySearchTree
{
    int* array;
    size_t size;
};

void TestInStackMemoryBinarySearchTree_Int();
void TestInHeapMemoryBinarySearchTree_Int();

void InitBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int* array, size_t size);
BinarySearchTree* CreateBinarySearchTree_Int(size_t size);
void AddToBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToAdd);
size_t FindByValueInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToFind);

#endif //ALGORITHMSANDDATASTRUCTURES_BINARYSEARCHTREE_H
