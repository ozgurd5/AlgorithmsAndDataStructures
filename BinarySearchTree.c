#include "BinarySearchTree.h"

void InitBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int* array, size_t size)
{
    binarySearchTree->array = array;
    binarySearchTree->size = size;
}

BinarySearchTree* CreateBinarySearchTree_Int(size_t size)
{
    int* array = (int*) malloc(size * sizeof (int));
    BinarySearchTree* newBinaryTree = (BinarySearchTree*) malloc(sizeof (BinarySearchTree));

    newBinaryTree->array = array;
    newBinaryTree->size = size;

    return newBinaryTree;
}

int GetLeftChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index)
{
    int leftIndex = index * 2 + 1;

    if (leftIndex < binarySearchTree->size) return leftIndex;
    else
    {
        printf("Error: Index %d is out of array bounds and doesn't have left child, returning 0", index);
        return 0;
    }
}

int GetRightChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index)
{
    int rightIndex = index * 2 + 2;

    if (rightIndex < binarySearchTree->size) return rightIndex;
    else
    {
        printf("Error: Index %d is out of array bounds and doesn't have right child, returning 0", index);
        return 0;
    }
}

int GetParentIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index)
{
    int parentIndex;
    if (index % 2 == 1) parentIndex = index / 2;
    else parentIndex = index / 2 - 1;

    if (index == 0)
    {
        printf("Error: Root doesn't have any parent, returning 0");
        return 0;
    }

    else if (parentIndex < binarySearchTree->size) return parentIndex;

    else
    {
        printf("Error: Index %d is outside of array bounds, returning 0", index);
        return 0;
    }
}

void AddToBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToAdd)
{
    int currentNodeIndex = 0;
    while (binarySearchTree->array[currentNodeIndex] != 0)
    {
        if (valueToAdd == binarySearchTree->array[currentNodeIndex]) return;
        else if (valueToAdd < binarySearchTree->array[currentNodeIndex]) currentNodeIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);
        else currentNodeIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);
    }

    binarySearchTree->array[currentNodeIndex] = valueToAdd;
}

int FindInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToFind)
{
    int currentNodeIndex = 0;
    while (binarySearchTree->array[currentNodeIndex] != 0)
    {
        if (valueToFind == binarySearchTree->array[currentNodeIndex]) return currentNodeIndex;
        else if (valueToFind < binarySearchTree->array[currentNodeIndex]) currentNodeIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);
        else currentNodeIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);
    }

    return currentNodeIndex;
}

void TestBinarySearchTree_Int()
{
    BinarySearchTree binarySearchTree;
    int array[64];
    ClearArray_Int(array, 64);
    InitBinarySearchTree_Int(&binarySearchTree, array, 64);

    //
    binarySearchTree.array[0] = 39;
    binarySearchTree.array[1] = 27;
    binarySearchTree.array[2] = 45;
    binarySearchTree.array[3] = 18;
    binarySearchTree.array[4] = 29;
    binarySearchTree.array[5] = 40;
    binarySearchTree.array[6] = 54;
    //

    //TESTS
    //GET RIGHT CHILD INDEX
    //GET LEFT CHILD INDEX
    //GET PARENT INDEX
    //ADD
    //FIND

    //REMOVE
    //PRINT
    //MAKE BINARY TREE A BINARY SEARCH TREE

    //
    printf("BINARY SEARCH TREE: VALUE(INDEX)\n");
    printf("              39(0)\n");
    printf("     27(1)            45(2)\n");
    printf("18(3)     29(4)  40(5)     54(6)\n\n");
    //

    //GET RIGHT CHILD INDEX
    int rootRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 0);
    printf("Right child index of the root: %d\n", rootRightChildIndex);
    printf("Right child value of the root: %d\n", binarySearchTree.array[rootRightChildIndex]);

    int secondIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 2);
    printf("\nRight child index of the second index: %d\n", secondIndexRightChildIndex);
    printf("Right child value of the second index: %d\n", binarySearchTree.array[secondIndexRightChildIndex]);

    int sixthIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 6);
    printf("\nRight child index of the sixth index (empty space, inside of array bounds): %d\n", sixthIndexRightChildIndex);
    printf("Right child value of the sixth index (empty space, inside of array bounds): %d\n\n", binarySearchTree.array[sixthIndexRightChildIndex]);

    int sixtySixthIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 66);
    printf("\nTry to get right child index of the sixty sixth index (outside of array bounds): %d\n", sixtySixthIndexRightChildIndex);
    //GET RIGHT CHILD INDEX

    //GET LEFT CHILD INDEX
    int rootLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(&binarySearchTree, 0);
    printf("\nLeft child index of the root: %d\n", rootLeftChildIndex);
    printf("Left child value of the root: %d\n", binarySearchTree.array[rootLeftChildIndex]);

    int secondIndexLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(&binarySearchTree, 2);
    printf("\nLeft child index of the second index: %d\n", secondIndexLeftChildIndex);
    printf("Left child value of the second index: %d\n", binarySearchTree.array[secondIndexLeftChildIndex]);

    int sixthIndexLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(&binarySearchTree, 6);
    printf("\nLeft child index of the sixth index (empty space, inside of array bounds): %d\n", sixthIndexLeftChildIndex);
    printf("Left child value of the sixth index (empty space, inside of array bounds): %d\n\n", binarySearchTree.array[sixthIndexLeftChildIndex]);

    int sixtySixthIndexLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(&binarySearchTree, 66);
    printf("\nTry to get left child index of the sixty sixth index (outside of array bounds): %d\n\n", sixtySixthIndexLeftChildIndex);
    //GET LEFT CHILD INDEX

    //GET PARENT INDEX
    int rootParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 0);
    printf("\nParent index of the root: %d\n", rootParentIndex);

    int secondIndexParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 2);
    printf("\nParent index of the second index: %d\n", secondIndexParentIndex);
    printf("Parent value of the second index: %d\n", binarySearchTree.array[secondIndexParentIndex]);

    int sixthIndexParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 6);
    printf("\nParent index of the sixth index: %d\n", sixthIndexParentIndex);
    printf("Parent value of the sixth index: %d\n\n", binarySearchTree.array[sixthIndexParentIndex]);

    int _132thIndexParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 132);
    printf("\nTry to get parent index of the 132th index (outside of array bounds): %d\n", _132thIndexParentIndex);
    //GET PARENT INDEX

    //ADD

    //add normal
    //add while empty
    //try to add while full
    
    //ADD
}
