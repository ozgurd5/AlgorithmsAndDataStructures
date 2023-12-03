#include <stdio.h>
#include <stdlib.h>
#include "LinkedList_IntID.h"

Node_IntID* CreateNode_IntID(int id, int value)
{
    Node_IntID* newNode = (Node_IntID*)malloc(sizeof (Node_IntID));

    newNode->id = id;
    newNode->value = value;

    //Default value
    newNode->next = NULL;

    return newNode;
}

void PrintList_IntID(Node_IntID* head)
{
    Node_IntID* currentNode = head;

    int listIndex = 0;
    while (currentNode != NULL)
    {
        if (listIndex == 0) printf("Head -> ");
        else printf("%d -> ", listIndex);

        printf("Id: %d - Value: %d\n", currentNode->id, currentNode->value);
        currentNode = currentNode->next;

        listIndex++;
    }
}

void AddToStartOfList_IntID(Node_IntID** headPointer, int id, int value)
{
    Node_IntID* newNode = CreateNode_IntID(id, value);

    newNode->next = *headPointer;
    *headPointer = newNode;
}

void AppendToList_IntID(Node_IntID* head, int id, int value)
{
    Node_IntID* newNode = CreateNode_IntID(id, value);

    Node_IntID* currentNode = head;
    while (currentNode->next != NULL) currentNode = currentNode->next;

    currentNode->next = newNode;
}

Node_IntID* FindByIDInList_IntID(Node_IntID* head, int id)
{
    Node_IntID* currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->id == id) return currentNode;
        else currentNode = currentNode->next;
    }

    //This section only works when no id matches. When id matches, the function returns and does not execute this lines
    printf("\nError: Node with id %d does not exist, FindByIDInList_IntID() stopped, returning NULL\n", id);
    return NULL;
}

Node_IntID* FindPreviousByIDInList_IntID(Node_IntID* head, int id)
{
    Node_IntID* currentNode = head;
    Node_IntID* currentPreviousNode = NULL;

    //Error flag
    int isIDMatched = 0;

    while (currentNode != NULL)
    {
        if (currentNode->id == id)
        {
            isIDMatched = 1;
            break;
        }

        currentPreviousNode = currentNode;
        currentNode = currentNode->next;
    }

    //Error 1
    if (!isIDMatched)
    {
        printf("\nError: Node with id %d does not exist, FindPreviousByIDInList_IntID() stopped, returning NULL\n", id);
        return NULL;
    }

    //Error 2
    if (currentPreviousNode == NULL)
    {
        printf("\nError: Node with id %d is head, it has no previous node, returning NULL\n", id);
        return NULL;
    }

    return currentPreviousNode;
}

void RemoveFirstInList_IntID(Node_IntID** headPointer)
{
    //If first node is the only node in the list
    if ((*headPointer)->next == NULL)
    {
        free(*headPointer);
        *headPointer = NULL;
    }

    //If not, just make second node the head
    else
    {
        Node_IntID *firstNode = *headPointer;
        *headPointer = (*headPointer)->next;
        free(firstNode);
    }
}

void RemoveLastInList_IntID(Node_IntID** headPointer)
{
    //If head is the last node in the list
    if ((*headPointer)->next == NULL)
    {
        RemoveFirstInList_IntID(headPointer);
        return;
    }

    Node_IntID* currentNode = *headPointer;
    Node_IntID* currentPreviousNode = NULL;

    while (currentNode->next != NULL)
    {
        currentPreviousNode = currentNode;
        currentNode = currentNode->next;
    }

    currentPreviousNode->next = NULL;
    free(currentNode);
}

void RemoveByIDInList_IntID(Node_IntID** headPointer, int id)
{
    //If removing first node
    if ((*headPointer)->id == id)
    {
        RemoveFirstInList_IntID(headPointer);
        return;
    }

    //Since we need to link previous to the next, first we need to find previous
    Node_IntID* currentPreviousNode = FindPreviousByIDInList_IntID(*headPointer, id);

    //If node with given id doesn't exist, return
    if (currentPreviousNode == NULL)
    {
        //We have to delete the error message coming from FindPreviousByIDInList_IntID() to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        printf("\nError: Node with id %d does not exist, RemoveByIDInList_IntID() stopped, returning NULL\n", id);
        return;
    }

    Node_IntID *currentNode = currentPreviousNode->next;
    currentPreviousNode->next = currentNode->next;
    free(currentNode);
}

void InsertBeforeByIDIntoList_IntID(Node_IntID** headPointer, int newNodeID, int newNodeValue, int insertTargetID)
{
    //If inserting before first node, just use AddToStartOfList_IntID()
    if ((*headPointer)->id == insertTargetID)
    {
        AddToStartOfList_IntID(headPointer, newNodeID, newNodeValue);
        return;
    }

    Node_IntID* currentPreviousNode = FindPreviousByIDInList_IntID(*headPointer, insertTargetID);

    //If node with given id doesn't exist, return
    if (currentPreviousNode == NULL)
    {
        //We have to delete the error message coming from FindByIDInList_IntID() to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        printf("\nError: Node with id %d does not exist, InsertBeforeByIDIntoList_IntID() stopped, returning NULL\n", insertTargetID);
        return;
    }

    Node_IntID *currentNode = currentPreviousNode->next;
    Node_IntID *newNode = CreateNode_IntID(newNodeID, newNodeValue);

    currentPreviousNode->next = newNode;
    newNode->next = currentNode;
}

void InsertAfterByIDIntoList_IntID(Node_IntID* head, int newNodeID, int newNodeValue, int insertTargetID)
{
    Node_IntID* newNode = CreateNode_IntID(newNodeID, newNodeValue);
    Node_IntID* insertTarget = FindByIDInList_IntID(head, insertTargetID);

    //If node with given id doesn't exist, return
    if (insertTarget == NULL)
    {
        //We have to delete the error message coming from FindByIDInList_IntID() to avoid confusion
        printf("\x1b[1F"); //Move to beginning of previous line
        printf("\x1b[2K"); //Clear entire line

        printf("\nError: Node with id %d does not exist, InsertAfterByIDIntoList_IntID() stopped, returning NULL\n", insertTargetID);
        return;
    }

    Node_IntID* temp = insertTarget->next;
    insertTarget->next = newNode;
    newNode->next = temp;
}

int TestLinkedList_IntID()
{
    //TESTS:
    //CREATE NODE
    //ADD TO START
    //APPEND
    //FIND BY ID
    //FIND PREVIOUS BY ID
    //REMOVE FIRST NODE
    //REMOVE LAST NODE
    //REMOVE BY ID
    //INSERT BEFORE BY ID
    //INSERT AFTER BY ID
    //REMOVE EVERY NODE

    //CREATE NODE
    Node_IntID* head = CreateNode_IntID(303, 3);
    printf("Create head (303,3):\n");
    PrintList_IntID(head);
    //CREATE NODE

    //ADD TO START
    AddToStartOfList_IntID(&head, 202, 2);
    printf("\nAdd to start (202,2):\n");
    PrintList_IntID(head);
    //ADD TO START

    //APPEND
    AppendToList_IntID(head, 404, 4);
    AppendToList_IntID(head, 505, 5);
    AppendToList_IntID(head, 606, 6);
    AppendToList_IntID(head, 707, 7);
    printf("\nAppend (404,4) (505,5) (606,6) (707):\n");
    PrintList_IntID(head);
    //APPEND

    //FIND BY ID
    printf("\nValue of the node with id 505: %d\n", FindByIDInList_IntID(head, 505)->value);
    printf("\nTry to find the node with id 808, which doesn't exist"); //Error, invalid id
    FindByIDInList_IntID(head, 808);
    //FIND BY ID

    //FIND PREVIOUS BY ID
    Node_IntID* findByPreviousByID = FindPreviousByIDInList_IntID(head, 505);
    printf("\nId and value of the previous node of the node with id 505: %d,%d\n", findByPreviousByID->id, findByPreviousByID->value);

    printf("\nTry to find the previous node of the node with id 808, which doesn't exist"); //Error, invalid id
    FindPreviousByIDInList_IntID(head, 808);

    printf("\nTry to find the previous node of the node with id 202, which is head"); //Error, head
    FindPreviousByIDInList_IntID(head, 202);
    //FIND PREVIOUS BY ID

    //REMOVE FIRST NODE
    RemoveFirstInList_IntID(&head);
    printf("\nFirst node removed:\n");
    PrintList_IntID(head);
    //REMOVE FIRST NODE

    //REMOVE LAST NODE
    RemoveLastInList_IntID(&head);
    printf("\nLast node removed:\n");
    PrintList_IntID(head);
    //REMOVE LAST NODE

    //REMOVE BY ID
    RemoveByIDInList_IntID(&head, 505);
    printf("\nNode with id 505 removed:\n");
    PrintList_IntID(head);

    RemoveByIDInList_IntID(&head, 303);
    printf("\nNode with id 303, which is the head, removed:\n");
    PrintList_IntID(head);

    printf("\nTry to remove the node with id 808, which doesn't exist:");
    RemoveByIDInList_IntID(&head, 808); //Error, invalid id
    //REMOVE BY ID

    //INSERT BEFORE BY ID
    InsertBeforeByIDIntoList_IntID(&head, 505, 5, 606);
    printf("\nNew node inserted (505,5) before the node with id 606\n");
    PrintList_IntID(head);

    InsertBeforeByIDIntoList_IntID(&head, 303, 3, 404);
    printf("\nNew node inserted (303,3) before the node with id 404, which is the head:\n");
    PrintList_IntID(head);

    printf("\nTry to insert before by the node with id 808, which doesn't exist:");
    InsertBeforeByIDIntoList_IntID(&head, 505, 5, 808); //Error, invalid id
    //INSERT BEFORE BY ID

    //INSERT AFTER BY ID
    InsertAfterByIDIntoList_IntID(head, 707, 7, 606);
    printf("\nNew node inserted (707,7) after the node with id 606:\n");
    PrintList_IntID(head);

    printf("\nTry to insert after by the node with id 808, which doesn't exist:");
    InsertAfterByIDIntoList_IntID(head, 707, 7, 808); //Error, invalid id
    //INSERT AFTER BY ID

    //REMOVE EVERY NODE
    RemoveLastInList_IntID(&head);
    RemoveLastInList_IntID(&head);
    RemoveLastInList_IntID(&head);
    RemoveLastInList_IntID(&head);
    RemoveLastInList_IntID(&head);

    printf("\nEvery node removed:\n");
    PrintList_IntID(head);
    //REMOVE EVERY NODE

    return 0;
}