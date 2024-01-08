#ifndef ALGORITHMSANDDATASTRUCTURES_BINARYTREE_H
#define ALGORITHMSANDDATASTRUCTURES_BINARYTREE_H

#include <stdio.h>
#include "BinarySearchTree.h"

size_t GetParentIndexBinaryTree(size_t index);
size_t GetLeftChildIndexBinaryTree(size_t index);
size_t GetRightChildIndexBinaryTree(size_t index);
void RawPrintBinaryTree_Int(int* array, size_t size);

#endif //ALGORITHMSANDDATASTRUCTURES_BINARYTREE_H
