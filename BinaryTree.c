#include "BinaryTree.h"

size_t GetParentIndexBinaryTree(size_t index)
{
    size_t parentIndex;
    if (index % 2 == 1) parentIndex = index / 2;
    else parentIndex = index / 2 - 1;

    return parentIndex;
}

size_t GetLeftChildIndexBinaryTree(size_t index)
{
    return index * 2 + 1;
}

size_t GetRightChildIndexBinaryTree(size_t index)
{
    return index * 2 + 2;
}

void RawPrintBinaryTree_Int(int* array, size_t size)
{
    size_t currentNodeIndex = 0;
    int nodeCapacityInLine = 1;
    int nodeInCurrentLine = 0;

    while(currentNodeIndex != size)
    {
        if (array[currentNodeIndex] == EMPTY_BST_NODE) printf("%c(%lld)", 'x', currentNodeIndex);
        else printf("%d(%lld)", array[currentNodeIndex], currentNodeIndex);

        nodeInCurrentLine++;
        currentNodeIndex++;

        if (nodeInCurrentLine == nodeCapacityInLine)
        {
            printf("\n");

            nodeCapacityInLine *= 2;
            nodeInCurrentLine = 0;
        }

        else printf(" - ");
    }

    if (nodeInCurrentLine != 0) printf("\n");
}