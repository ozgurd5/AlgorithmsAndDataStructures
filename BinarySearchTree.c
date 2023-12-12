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

void RawPrintBinarySearchTree_Int(BinarySearchTree* binarySearchTree)
{
    int currentNodeIndex = 0;
    int nodeCapacityInLine = 1;
    int nodeInCurrentLine = 0;

    while(currentNodeIndex != binarySearchTree->size)
    {
        printf("%d(%d)", binarySearchTree->array[currentNodeIndex], currentNodeIndex);

        nodeInCurrentLine++;
        currentNodeIndex++;

        if (nodeInCurrentLine == nodeCapacityInLine)
        {
            printf("\n");

            nodeCapacityInLine *= 2;
            nodeInCurrentLine = 0;
        }

        else printf("-");
    }
}

int GetLeftChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index)
{
    int leftIndex = index * 2 + 1;

    if (leftIndex < binarySearchTree->size) return leftIndex;
    else
    {
        printf("Error: Index %d is out of array bounds and doesn't have left child, returning -1\n", index);
        return -1;
    }
}

int GetRightChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index)
{
    int rightIndex = index * 2 + 2;

    if (rightIndex < binarySearchTree->size) return rightIndex;
    else
    {
        printf("Error: Index %d is out of array bounds and doesn't have right child, returning -1\n", index);
        return -1;
    }
}

int GetParentIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int index)
{
    int parentIndex;
    if (index % 2 == 1) parentIndex = index / 2;
    else parentIndex = index / 2 - 1;

    if (index == 0)
    {
        printf("Error: Root doesn't have any parent, returning -1\n");
        return -1;
    }

    else if (parentIndex < binarySearchTree->size) return parentIndex;

    else
    {
        printf("Error: Index %d is outside of array bounds, returning -1\n", index);
        return -1;
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

        if (currentNodeIndex == -1)
        {
            //We have to delete the error message coming from getting right or left child index functions to avoid confusion
            printf("\x1b[1F"); //Move to beginning of previous line
            printf("\x1b[2K"); //Clear entire line

            printf("Error: Can't add the value %d because binary search list is full\n", valueToAdd);
            return;
        }
    }

    binarySearchTree->array[currentNodeIndex] = valueToAdd;
}

int FindByValueInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToFind)
{
    int currentNodeIndex = 0;
    while (binarySearchTree->array[currentNodeIndex] != 0)
    {
        if (valueToFind == binarySearchTree->array[currentNodeIndex]) return currentNodeIndex;
        else if (valueToFind < binarySearchTree->array[currentNodeIndex]) currentNodeIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);
        else currentNodeIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);

        if (currentNodeIndex == -1)
        {
            //We have to delete the error message coming from getting right or left child index functions to avoid confusion
            printf("\x1b[1F"); //Move to beginning of previous line
            printf("\x1b[2K"); //Clear entire line

            printf("Error: Value %d does not exist, returning -1\n", valueToFind);
            return -1;
        }
    }

    return currentNodeIndex;
}

void RemoveByValueInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToRemove)
{
    int indexToRemove = FindByValueInBinarySearchTree_Int(binarySearchTree, valueToRemove);

    //If index doesn't exist
    if (indexToRemove == -1)
    {
        //We have to delete the error message coming from FindByValueInBinarySearchTree_Int() to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        printf("Error: Value %d does not exist, can't remove\n", valueToRemove);
    }

    int rightIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, indexToRemove);
    int leftIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, indexToRemove);

    //Removing a node with no child - left and right is out of array bounds or empty
    if ((rightIndex == -1 && leftIndex == -1) || binarySearchTree->array[rightIndex] == 0 && binarySearchTree->array[leftIndex] == 0)
    {
        //We have to delete the error message coming from getting right or left child index functions to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        binarySearchTree->array[indexToRemove] = 0;
    }

    //Removing a node with a child (has left) - right is out of array bounds or empty
    else if (rightIndex == -1 || binarySearchTree->array[rightIndex] == 0)
    {
        //We have to delete the error message coming from getting right or left child index functions to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        binarySearchTree->array[indexToRemove] = binarySearchTree->array[leftIndex];
        binarySearchTree->array[leftIndex] = 0;
    }

    //Removing a node with a child (has right) - left is out of array bounds or empty
    else if (leftIndex == -1 || binarySearchTree->array[leftIndex] == 0)
    {
        //We have to delete the error message coming from getting right or left child index functions to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        binarySearchTree->array[indexToRemove] = binarySearchTree->array[rightIndex];
        binarySearchTree->array[rightIndex] = 0;
    }

    //Removing a node with two children
    else
    {
        //Find and remove the biggest value in the left tree

        //We may choose to remove the smallest value in the right tree but this one is better because biggest in the left tree has either one child..
        //..or no child. Smallest in the right tree might have two child and in that condition we would have to start another recursion. This is..
        //..not ideal in big trees and can cause stack overflow.

        int previousLeftChildIndex = 0;
        int currentLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, indexToRemove);

        while (currentLeftChildIndex != -1 || binarySearchTree->array[currentLeftChildIndex] != 0)
        {
            previousLeftChildIndex = currentLeftChildIndex;
            currentLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, currentLeftChildIndex);
        }

        //When the loop ends, currentLeftChildIndex is -1 or index of an empty node, previousLeftChildIndex is the biggest value in the left tree

        //We can't just replace indexToRemove with previousLeftChildIndex because previousLeftChild might have a right child.
        RemoveByValueInBinarySearchTree_Int(binarySearchTree, previousLeftChildIndex);
    }
}

void TestBinarySearchTree_Int()
{
    BinarySearchTree emptyBinarySearchTree;
    int array2[15];
    ClearArray_Int(array2, 15);
    InitBinarySearchTree_Int(&emptyBinarySearchTree, array2, 15);

    BinarySearchTree fullBinarySearchTree;
    int array3[6];
    ClearArray_Int(array3, 6);
    InitBinarySearchTree_Int(&fullBinarySearchTree, array3, 6);

    //
    fullBinarySearchTree.array[0] = 39;
    fullBinarySearchTree.array[1] = 27;
    fullBinarySearchTree.array[2] = 45;
    fullBinarySearchTree.array[3] = 18;
    fullBinarySearchTree.array[4] = 29;
    fullBinarySearchTree.array[5] = 40;
    fullBinarySearchTree.array[6] = 54;
    //

    BinarySearchTree binarySearchTree;
    int array[15];
    ClearArray_Int(array, 15);
    InitBinarySearchTree_Int(&binarySearchTree, array, 15);

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
    //PRINT RAW
    //GET RIGHT CHILD INDEX
    //GET LEFT CHILD INDEX
    //GET PARENT INDEX
    //ADD
    //FIND
    //REMOVE

    //MAKE BINARY TREE A BINARY SEARCH TREE

    //PRINT RAW
    printf("Try to print empty binary search tree:\n");
    RawPrintBinarySearchTree_Int(&emptyBinarySearchTree);

    printf("\nPrint Binary Search Tree:\n");
    RawPrintBinarySearchTree_Int(&binarySearchTree);
    //PRINT RAW

    //GET RIGHT CHILD INDEX
    int rootRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 0);
    printf("\nRight child index of the root: %d\n", rootRightChildIndex);
    printf("Right child value of the root: %d\n", binarySearchTree.array[rootRightChildIndex]);

    int secondIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 2);
    printf("\nRight child index of the second index: %d\n", secondIndexRightChildIndex);
    printf("Right child value of the second index: %d\n", binarySearchTree.array[secondIndexRightChildIndex]);

    int sixthIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 6);
    printf("\nRight child index of the sixth index (empty space, inside of array bounds): %d\n", sixthIndexRightChildIndex);
    printf("Right child value of the sixth index (empty space, inside of array bounds): %d\n\n", binarySearchTree.array[sixthIndexRightChildIndex]);

    int sixtySixthIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(&binarySearchTree, 66);
    printf("Try to get right child index of the sixty sixth index (outside of array bounds): %d\n", sixtySixthIndexRightChildIndex);
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
    printf("Try to get left child index of the sixty sixth index (outside of array bounds): %d\n\n", sixtySixthIndexLeftChildIndex);
    //GET LEFT CHILD INDEX

    //GET PARENT INDEX
    int rootParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 0);
    printf("Parent index of the root: %d\n", rootParentIndex);

    int secondIndexParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 2);
    printf("\nParent index of the second index: %d\n", secondIndexParentIndex);
    printf("Parent value of the second index: %d\n", binarySearchTree.array[secondIndexParentIndex]);

    int sixthIndexParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 6);
    printf("\nParent index of the sixth index: %d\n", sixthIndexParentIndex);
    printf("Parent value of the sixth index: %d\n\n", binarySearchTree.array[sixthIndexParentIndex]);

    int _132thIndexParentIndex = GetParentIndexBinarySearchTree_Int(&binarySearchTree, 132);
    printf("Try to get parent index of the 132th index (outside of array bounds): %d\n", _132thIndexParentIndex);
    //GET PARENT INDEX

    //ADD
    printf("\nAdd 10:\n");
    AddToBinarySearchTree_Int(&binarySearchTree, 10);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nAdd 10, which is already added:\n");
    AddToBinarySearchTree_Int(&binarySearchTree, 10);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nAdd 39, which is the root and already added:\n");
    AddToBinarySearchTree_Int(&binarySearchTree, 39);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nAdd 70:\n");
    AddToBinarySearchTree_Int(&binarySearchTree, 70);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nAdd 30:\n");
    AddToBinarySearchTree_Int(&binarySearchTree, 30);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nTry to add 200:\n");
    AddToBinarySearchTree_Int(&binarySearchTree, 200);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nAdd 10 to the empty binary search tree:\n");
    AddToBinarySearchTree_Int(&emptyBinarySearchTree, 10);
    RawPrintBinarySearchTree_Int(&emptyBinarySearchTree);
    //ADD

    //FIND
    printf("\nFind the index of the value 39: %d\n", FindByValueInBinarySearchTree_Int(&binarySearchTree, 39));
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nFind the index of the value 10: %d\n", FindByValueInBinarySearchTree_Int(&binarySearchTree, 10));
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\n");
    printf("Find the index of the value 200, which doesn't exist: %d\n", FindByValueInBinarySearchTree_Int(&binarySearchTree, 200));
    RawPrintBinarySearchTree_Int(&binarySearchTree);
    //FIND

    //REMOVE
    printf("\nRemove the node with value 10 which has no child:\n");
    RemoveByValueInBinarySearchTree_Int(&binarySearchTree, 10);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    //problem: deleting error line
    printf("\nRemove the node with value 54 which has a child in right:\n");
    RemoveByValueInBinarySearchTree_Int(&binarySearchTree, 54);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    //left child only

    //problem: idk
    printf("\nRemove the node with value 39 which has two children:\n");
    RemoveByValueInBinarySearchTree_Int(&binarySearchTree, 39);
    RawPrintBinarySearchTree_Int(&binarySearchTree);

    printf("\nRemove the node with value 200 which doesn't exist:\n");
    RemoveByValueInBinarySearchTree_Int(&binarySearchTree, 200);
    RawPrintBinarySearchTree_Int(&binarySearchTree);
    //REMOVE
}
