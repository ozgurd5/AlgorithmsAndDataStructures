#include "BinarySearchTree.h"

void InitBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int* array, size_t capacity)
{
    ClearArrayUsingGivenValue_Int(array, 7, EMPTY_BST_NODE);

    binarySearchTree->array = array;
    binarySearchTree->capacity = capacity;
    binarySearchTree->size = 0;
}

BinarySearchTree* CreateBinarySearchTree_Int(size_t capacity)
{
    BinarySearchTree* newBinarySearchTree = (BinarySearchTree*) malloc(sizeof (BinarySearchTree));
    int* array = (int*) malloc(capacity * sizeof (int));
    ClearArrayUsingGivenValue_Int(array, capacity, EMPTY_BST_NODE);

    newBinarySearchTree->array = array;
    newBinarySearchTree->capacity = capacity;
    newBinarySearchTree->size = 0;

    return newBinarySearchTree;
}

void FreeBinarySearchTree_Int(BinarySearchTree* binarySearchTree)
{
    free(binarySearchTree->array);
    free(binarySearchTree);
}

void AddToBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToAdd)
{
    if (binarySearchTree->size == binarySearchTree->capacity)
    {
        printf("Binary search tree is full, can't add the value %d\n", valueToAdd);
        return;
    }

    size_t currentNodeIndex = 0;

    while (binarySearchTree->array[currentNodeIndex] != EMPTY_BST_NODE)
    {
        if (valueToAdd == binarySearchTree->array[currentNodeIndex]) return;
        else if (valueToAdd < binarySearchTree->array[currentNodeIndex]) currentNodeIndex = GetLeftChildIndexBinaryTree(currentNodeIndex);
        else currentNodeIndex = GetRightChildIndexBinaryTree(currentNodeIndex);

        if (currentNodeIndex >= binarySearchTree->capacity)
        {
            printf("Binary search tree capacity exceeded, can't add the value %d\n", valueToAdd);
            return;
        }
    }

    binarySearchTree->array[currentNodeIndex] = valueToAdd;
    binarySearchTree->size++;
}

size_t FindByValueInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToFind)
{
    size_t currentNodeIndex = 0;

    while (binarySearchTree->array[currentNodeIndex] != EMPTY_BST_NODE)
    {
        if (valueToFind == binarySearchTree->array[currentNodeIndex]) return currentNodeIndex;
        else if (valueToFind < binarySearchTree->array[currentNodeIndex]) currentNodeIndex = GetLeftChildIndexBinaryTree(currentNodeIndex);
        else currentNodeIndex = GetRightChildIndexBinaryTree(currentNodeIndex);

        if (currentNodeIndex >= binarySearchTree->capacity)
        {
            printf("Value %d doesn't exist at given binary search tree, returning INVALID_BST_INDEX\n", valueToFind);
            return INVALID_BST_INDEX;
        }
    }

    return currentNodeIndex; //Doesn't necessary, ide gives warning
}

void RemoveByValueInBinarySearchTree_Int(BinarySearchTree* binarySearchTree, int valueToRemove)
{
    size_t indexToRemove = FindByValueInBinarySearchTree_Int(binarySearchTree, valueToRemove);

    if (indexToRemove == INVALID_BST_INDEX)
    {
        //We have to delete the error message coming from FindByValueInBinarySearchTree_Int() to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        printf("Error: Value %d does not exist, can't remove\n", valueToRemove);
        return;
    }

    size_t rightChildIndex = GetRightChildIndexBinaryTree(indexToRemove);
    size_t leftChildIndex = GetLeftChildIndexBinaryTree(indexToRemove);

    //Removing a node without children - left and right exceeds capacity or empty
    if ((rightChildIndex >= binarySearchTree->capacity && leftChildIndex >= binarySearchTree->capacity)
        || (binarySearchTree->array[rightChildIndex] == EMPTY_BST_NODE && binarySearchTree->array[leftChildIndex] == EMPTY_BST_NODE))
        binarySearchTree->array[indexToRemove] = EMPTY_BST_NODE;

    //Removing a node with one child, which is right - left exceeds capacity or empty
    else if (rightChildIndex >= binarySearchTree->capacity || binarySearchTree->array[rightChildIndex] == EMPTY_BST_NODE)
    {
        int leftChildValue = binarySearchTree->array[leftChildIndex];
        binarySearchTree->size++; //Recursive call will decrease the size too
        RemoveByValueInBinarySearchTree_Int(binarySearchTree, leftChildValue);
        binarySearchTree->array[indexToRemove] = leftChildValue;
    }

    //Removing a node with one child, which is left - right exceeds capacity or empty
    else if (leftChildIndex >= binarySearchTree->capacity || binarySearchTree->array[leftChildIndex] == EMPTY_BST_NODE)
    {
        int rightChildValue = binarySearchTree->array[rightChildIndex];
        binarySearchTree->size++; //Recursive call will decrease the size too
        RemoveByValueInBinarySearchTree_Int(binarySearchTree, rightChildValue);
        binarySearchTree->array[indexToRemove] = rightChildValue;
    }

    //Removing a node with two children
    else
    {
        //Find and replace with the biggest value in the left tree

        //Start from left
        size_t currentIndex = GetLeftChildIndexBinaryTree(indexToRemove);
        size_t biggestValueInLeftTreeIndex = currentIndex;

        while (currentIndex < binarySearchTree->capacity && binarySearchTree->array[currentIndex] != EMPTY_BST_NODE)
        {
            //Go right until no right
            biggestValueInLeftTreeIndex = currentIndex;
            currentIndex = GetRightChildIndexBinaryTree(currentIndex);
        }

        int biggestValueInLeftTree = binarySearchTree->array[biggestValueInLeftTreeIndex];
        binarySearchTree->size++; //Recursive call will decrease the size too
        RemoveByValueInBinarySearchTree_Int(binarySearchTree, biggestValueInLeftTree);
        binarySearchTree->array[indexToRemove] = biggestValueInLeftTree;
    }

    binarySearchTree->size--;
}

void RunTestsBinarySearchTree_Int(BinarySearchTree* binarySearchTree)
{
    //TESTS
    //ADD
    //FIND
    //REMOVE

    //ADD
    printf("\nAdd 10:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 10);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd 10, which is already added:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 10);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd 39, which is the root and already added:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 39);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd 70:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 70);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd 30:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 30);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nTry to add 200:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 200);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd -6:\n");
    AddToBinarySearchTree_Int(binarySearchTree, -6);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd -7:\n");
    AddToBinarySearchTree_Int(binarySearchTree, -7);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd -5:\n");
    AddToBinarySearchTree_Int(binarySearchTree, -5);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nTry to Add -10:\n");
    AddToBinarySearchTree_Int(binarySearchTree, -10);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);
    //ADD

    //FIND
    printf("\nIndex of the value -6: %lld\n", FindByValueInBinarySearchTree_Int(binarySearchTree, -6));
    printf("\nIndex of the value 30: %lld\n", FindByValueInBinarySearchTree_Int(binarySearchTree, 30));
    printf("\nIndex of the value 10: %lld\n\n", FindByValueInBinarySearchTree_Int(binarySearchTree, 10));
    printf("Index of the value 200, which doesn't exist: %lld\n", FindByValueInBinarySearchTree_Int(binarySearchTree, 200));
    //FIND

    //REMOVE
    printf("\nRemove -7, which its children exceeds capacity:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, -7);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nRemove -6, which only has a right child:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, -6);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nRemove 70:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 70);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nRemove 39, which only has a left child:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 39);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nAdd 25, 40, -10 and 5 to fill the binary tree:\n");
    AddToBinarySearchTree_Int(binarySearchTree, 25);
    AddToBinarySearchTree_Int(binarySearchTree, 40);
    AddToBinarySearchTree_Int(binarySearchTree, -10);
    AddToBinarySearchTree_Int(binarySearchTree, 5);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);

    printf("\nRemove 10, which is the root and has two children:\n");
    RemoveByValueInBinarySearchTree_Int(binarySearchTree, 10);
    RawPrintBinaryTree_Int(binarySearchTree->array, binarySearchTree->capacity);
    //REMOVE
}

void TestInStackMemoryBinarySearchTree_Int()
{
    BinarySearchTree binarySearchTree;
    int array[7];
    InitBinarySearchTree_Int(&binarySearchTree, array, 7);

    RunTestsBinarySearchTree_Int(&binarySearchTree);
}

void TestInHeapMemoryBinarySearchTree_Int()
{
    BinarySearchTree* binarySearchTree = CreateBinarySearchTree_Int(7);
    RunTestsBinarySearchTree_Int(binarySearchTree);
    FreeBinarySearchTree_Int(binarySearchTree);
}
