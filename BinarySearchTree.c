#include "BinarySearchTree.h"

void InitBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int* array, size_t size)
{
    binarySearchTree->array = array;
    binarySearchTree->size = size;
}

BinarySearchTree* CreateBinarySearchTree_Int(size_t size)
{
    BinarySearchTree* newBinarySearchTree = (BinarySearchTree*) malloc(sizeof (BinarySearchTree));

    int* array = (int*) malloc(size * sizeof (int));
    ClearArray_Int(array, size);

    newBinarySearchTree->array = array;
    newBinarySearchTree->size = size;

    return newBinarySearchTree;
}

void RawPrintBinarySearchTree_Int(BinarySearchTree* binarySearchTree)
{
    size_t currentNodeIndex = 0;
    int nodeCapacityInLine = 1;
    int nodeInCurrentLine = 0;

    while(currentNodeIndex != binarySearchTree->size)
    {
        printf("%d(%lld)", binarySearchTree->array[currentNodeIndex], currentNodeIndex);

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

size_t GetLeftChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, size_t index)
{
    size_t leftIndex = index * 2 + 1;

    if (leftIndex < binarySearchTree->size) return leftIndex;
    else
    {
        printf("Error: Index %lld is out of array bounds and doesn't have left child, returning -1\n", index);
        return -1;
    }
}

size_t GetRightChildIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, size_t index)
{
    size_t rightIndex = index * 2 + 2;

    if (rightIndex < binarySearchTree->size) return rightIndex;
    else
    {
        printf("Error: Index %lld is out of array bounds and doesn't have right child, returning -1\n", index);
        return -1;
    }
}

size_t GetParentIndexBinarySearchTree_Int(BinarySearchTree* binarySearchTree, size_t index)
{
    size_t parentIndex;
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
        printf("Error: Index %lld is outside of array bounds, returning -1\n", index);
        return -1;
    }
}

void AddToBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToAdd)
{
    size_t currentNodeIndex = 0;
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

            printf("Error: Can't add the value %d because binary search tree is full\n", valueToAdd);
            return;
        }
    }

    binarySearchTree->array[currentNodeIndex] = valueToAdd;
}

size_t FindByValueInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToFind)
{
    size_t currentNodeIndex = 0;
    while (binarySearchTree->array[currentNodeIndex] != 0)
    {
        if (valueToFind == binarySearchTree->array[currentNodeIndex]) return currentNodeIndex;
        else if (valueToFind < binarySearchTree->array[currentNodeIndex]) currentNodeIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);
        else currentNodeIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, currentNodeIndex);

        if (currentNodeIndex == -1 || binarySearchTree->array[currentNodeIndex] == 0)
        {
            //We have to delete the error message coming from getting right or left child index functions to avoid confusion
            if (currentNodeIndex == -1)
            {
                printf("\x1b[1F"); //Move to beginning of previous line
                printf("\x1b[2K"); //Clear entire line
            }

            printf("Error: Value %d does not exist, returning -1\n", valueToFind);
            return -1;
        }
    }

    return currentNodeIndex;
}

void RemoveByValueInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToRemove)
{
    size_t indexToRemove = FindByValueInBinarySearchTree_Int(binarySearchTree, valueToRemove);

    //If value doesn't exist
    if (indexToRemove == -1)
    {
        //We have to delete the error message coming from FindByValueInBinarySearchTree_Int() to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        printf("Error: Value %d does not exist, can't remove\n", valueToRemove);
    }

    size_t rightChildIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, indexToRemove);
    size_t leftChildIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, indexToRemove);

    //Removing a node with no child - left and right is out of array bounds or empty
    if ((rightChildIndex == -1 && leftChildIndex == -1) || (binarySearchTree->array[rightChildIndex] == 0 && binarySearchTree->array[leftChildIndex] == 0))
    {
        if ((rightChildIndex == -1 && leftChildIndex == -1))
        {
            //We have to delete the error message coming from getting right or left child index functions to avoid confusion
            printf("\x1b[1F"); //Move to beginning of previous line
            printf("\x1b[2K"); //Clear entire line
            printf("\x1b[1F"); //Move to beginning of previous line
            printf("\x1b[2K"); //Clear entire line
        }

        binarySearchTree->array[indexToRemove] = 0;
    }

    //Removing a node with one child, which is left - right is out of array bounds or empty
    else if (rightChildIndex == -1 || binarySearchTree->array[rightChildIndex] == 0)
    {
        //We have to delete the error message coming from getting right child index function to avoid confusion
        if (rightChildIndex == -1)
        {
            printf("\x1b[1F"); //Move to beginning of previous line
            printf("\x1b[2K"); //Clear entire line
        }

        int leftChildValue = binarySearchTree->array[leftChildIndex];
        RemoveByValueInBinarySearchTree_Int(binarySearchTree, leftChildValue);
        binarySearchTree->array[indexToRemove] = leftChildValue;
    }

    //Removing a node with one child, which is right - left is out of array bounds or empty
    else if (leftChildIndex == -1 || binarySearchTree->array[leftChildIndex] == 0)
    {
        //We have to delete the error message coming from getting left child index function to avoid confusion
        if (leftChildIndex == -1)
        {
            printf("\x1b[1F"); //Move to beginning of previous line
            printf("\x1b[2K"); //Clear entire line
        }

        int rightChildValue = binarySearchTree->array[rightChildIndex];
        RemoveByValueInBinarySearchTree_Int(binarySearchTree, rightChildValue);
        binarySearchTree->array[indexToRemove] = rightChildValue;
    }

    //Removing a node with two children
    else
    {
        //Find and replace with the biggest value in the left tree

        //Start from left
        size_t currentIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, indexToRemove);
        size_t biggestValueInLeftTreeIndex = currentIndex;

        while (currentIndex != -1 && binarySearchTree->array[currentIndex] != 0)
        {
            //Go right until no right
            biggestValueInLeftTreeIndex = currentIndex;
            currentIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, currentIndex);
        }

        int biggestValueInLeftTree = binarySearchTree->array[biggestValueInLeftTreeIndex];
        RemoveByValueInBinarySearchTree_Int(binarySearchTree, biggestValueInLeftTree);
        binarySearchTree->array[indexToRemove] = biggestValueInLeftTree;
    }
}

void RunTestsBinarySearchTree_Int(BinarySearchTree* binarySearchTree, BinarySearchTree* fullBinarySearchTree, BinarySearchTree* emptyBinarySearchTree)
{
    //TESTS
    //PRINT RAW
    //GET RIGHT CHILD INDEX
    //GET LEFT CHILD INDEX
    //GET PARENT INDEX
    //ADD
    //FIND
    //REMOVE

    //PRINT RAW
    printf("Try to print empty binary search tree:\n");
    RawPrintBinarySearchTree_Int(emptyBinarySearchTree);

    printf("\nPrint Binary Search Tree:\n");
    RawPrintBinarySearchTree_Int(binarySearchTree);
    //PRINT RAW

    //GET RIGHT CHILD INDEX
    size_t rootRightChildIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, 0);
    printf("\nRight child index of the root: %lld\n", rootRightChildIndex);
    printf("Right child value of the root: %d\n", binarySearchTree->array[rootRightChildIndex]);

    size_t secondIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, 2);
    printf("\nRight child index of the second index: %lld\n", secondIndexRightChildIndex);
    printf("Right child value of the second index: %d\n", binarySearchTree->array[secondIndexRightChildIndex]);

    size_t sixthIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, 6);
    printf("\nRight child index of the sixth index (empty space, inside of array bounds): %lld\n", sixthIndexRightChildIndex);
    printf("Right child value of the sixth index (empty space, inside of array bounds): %d\n\n", binarySearchTree->array[sixthIndexRightChildIndex]);

    size_t sixtySixthIndexRightChildIndex = GetRightChildIndexBinarySearchTree_Int(binarySearchTree, 66);
    printf("Try to get right child index of the sixty sixth index (outside of array bounds): %lld\n", sixtySixthIndexRightChildIndex);
    //GET RIGHT CHILD INDEX

    //GET LEFT CHILD INDEX
    size_t rootLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, 0);
    printf("\nLeft child index of the root: %lld\n", rootLeftChildIndex);
    printf("Left child value of the root: %d\n", binarySearchTree->array[rootLeftChildIndex]);

    size_t secondIndexLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, 2);
    printf("\nLeft child index of the second index: %lld\n", secondIndexLeftChildIndex);
    printf("Left child value of the second index: %d\n", binarySearchTree->array[secondIndexLeftChildIndex]);

    size_t sixthIndexLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, 6);
    printf("\nLeft child index of the sixth index (empty space, inside of array bounds): %lld\n", sixthIndexLeftChildIndex);
    printf("Left child value of the sixth index (empty space, inside of array bounds): %d\n\n", binarySearchTree->array[sixthIndexLeftChildIndex]);

    size_t sixtySixthIndexLeftChildIndex = GetLeftChildIndexBinarySearchTree_Int(binarySearchTree, 66);
    printf("Try to get left child index of the sixty sixth index (outside of array bounds): %lld\n\n", sixtySixthIndexLeftChildIndex);
    //GET LEFT CHILD INDEX

    //GET PARENT INDEX
    size_t rootParentIndex = GetParentIndexBinarySearchTree_Int(binarySearchTree, 0);
    printf("Parent index of the root: %lld\n", rootParentIndex);

    size_t secondIndexParentIndex = GetParentIndexBinarySearchTree_Int(binarySearchTree, 2);
    printf("\nParent index of the second index: %lld\n", secondIndexParentIndex);
    printf("Parent value of the second index: %d\n", binarySearchTree->array[secondIndexParentIndex]);

    size_t sixthIndexParentIndex = GetParentIndexBinarySearchTree_Int(binarySearchTree, 6);
    printf("\nParent index of the sixth index: %lld\n", sixthIndexParentIndex);
    printf("Parent value of the sixth index: %d\n\n", binarySearchTree->array[sixthIndexParentIndex]);

    size_t _132thIndexParentIndex = GetParentIndexBinarySearchTree_Int(binarySearchTree, 132);
    printf("Try to get parent index of the 132th index (outside of array bounds): %lld\n", _132thIndexParentIndex);
    //GET PARENT INDEX

    //ADD
    printf("\nAdd 10:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 10);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nAdd 10, which is already added:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 10);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nAdd 39, which is the root and already added:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 39);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nAdd 70:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 70);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nAdd 30:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 30);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nTry to add 200:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 200);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nAdd 10 to the empty binary search tree:\n");
    AddToBinarySearchTree_Int(emptyBinarySearchTree, 10);
    RawPrintBinarySearchTree_Int(emptyBinarySearchTree);

    printf("\nAdd 10 to the full binary search tree:\n");
    AddToBinarySearchTree_Int(fullBinarySearchTree, 10);
    RawPrintBinarySearchTree_Int(fullBinarySearchTree);
    //ADD

    //FIND
    printf("\nFind the index of the value 39: %lld\n", FindByValueInBinarySearchTree_Int(binarySearchTree, 39));
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nFind the index of the value 10: %lld\n", FindByValueInBinarySearchTree_Int(binarySearchTree, 10));
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\n");
    printf("Find the index of the value 200, which doesn't exist: %lld\n", FindByValueInBinarySearchTree_Int(binarySearchTree, 200));
    RawPrintBinarySearchTree_Int(binarySearchTree);
    //FIND

    //REMOVE
    printf("\nRemove the node with value 39 which has two children:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 39);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nRemove the node with value 29 which has no child:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 29);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nRemove the node with value 54 which has a child in right:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 54);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nRemove the node with value 18 which has a child in left:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 18);
    RawPrintBinarySearchTree_Int(binarySearchTree);

    printf("\nRemove the node with value 200 which doesn't exist:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 200);
    RawPrintBinarySearchTree_Int(binarySearchTree);
    //REMOVE
}

void TestInStackMemoryBinarySearchTree_Int()
{
    BinarySearchTree binarySearchTree;
    int array[15];
    ClearArray_Int(array, 15);
    InitBinarySearchTree_Int(&binarySearchTree, array, 15);

    //Manual fill
    binarySearchTree.array[0] = 39;
    binarySearchTree.array[1] = 27;
    binarySearchTree.array[2] = 45;
    binarySearchTree.array[3] = 18;
    binarySearchTree.array[4] = 29;
    binarySearchTree.array[5] = 40;
    binarySearchTree.array[6] = 54;

    BinarySearchTree fullBinarySearchTree;
    int array3[7];
    ClearArray_Int(array3, 7);
    InitBinarySearchTree_Int(&fullBinarySearchTree, array3, 7);

    //Manual fill
    fullBinarySearchTree.array[0] = 39;
    fullBinarySearchTree.array[1] = 27;
    fullBinarySearchTree.array[2] = 45;
    fullBinarySearchTree.array[3] = 18;
    fullBinarySearchTree.array[4] = 29;
    fullBinarySearchTree.array[5] = 40;
    fullBinarySearchTree.array[6] = 54;

    BinarySearchTree emptyBinarySearchTree;
    int array2[15];
    ClearArray_Int(array2, 15);
    InitBinarySearchTree_Int(&emptyBinarySearchTree, array2, 15);

    RunTestsBinarySearchTree_Int(&binarySearchTree, &fullBinarySearchTree, &emptyBinarySearchTree);
}

void TestInHeapMemoryBinarySearchTree_Int()
{
    BinarySearchTree* binarySearchTree = CreateBinarySearchTree_Int(15);

    //Manual fill
    binarySearchTree->array[0] = 39;
    binarySearchTree->array[1] = 27;
    binarySearchTree->array[2] = 45;
    binarySearchTree->array[3] = 18;
    binarySearchTree->array[4] = 29;
    binarySearchTree->array[5] = 40;
    binarySearchTree->array[6] = 54;

    BinarySearchTree* fullBinarySearchTree = CreateBinarySearchTree_Int(7);

    //Manual fill
    fullBinarySearchTree->array[0] = 39;
    fullBinarySearchTree->array[1] = 27;
    fullBinarySearchTree->array[2] = 45;
    fullBinarySearchTree->array[3] = 18;
    fullBinarySearchTree->array[4] = 29;
    fullBinarySearchTree->array[5] = 40;
    fullBinarySearchTree->array[6] = 54;

    BinarySearchTree* emptyBinarySearchTree = CreateBinarySearchTree_Int(15);

    RunTestsBinarySearchTree_Int(binarySearchTree, fullBinarySearchTree, emptyBinarySearchTree);
}
