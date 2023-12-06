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

void TestBinarySearchTree_Int();

void InitBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int* array, size_t size);
BinarySearchTree* CreateBinarySearchTree_Int(size_t size);
int GetLeftChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index);
int GetRightChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index);
int GetParentIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index);
void AddToBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToAdd);
int FindInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToFind);

#endif //ALGORITHMSANDDATASTRUCTURES_BINARYSEARCHTREE_H
