#include <stdio.h>
#include <stdlib.h>
#include "LinkedListIntID.h"

NodeIntID* CreateNodeIntID(int id, int value)
{
    NodeIntID* newNode = (NodeIntID*)malloc(sizeof (NodeIntID));

    //Assign given values
    newNode->id = id;
    newNode->value = value;

    //Assign default value
    newNode->next = NULL;

    return newNode;
}

void PrintListIntID(NodeIntID* head)
{
    NodeIntID* currentNode = head;

    while (currentNode != NULL)
    {
        printf("id: %d - value: %d\n", currentNode->id, currentNode->value);
        currentNode = currentNode->next;
    }
}

void AppendToListIntID(NodeIntID* head, int id, int value)
{
    NodeIntID* newNode = CreateNodeIntID(id, value);

    NodeIntID* currentNode = head;
    while (currentNode->next != NULL) currentNode = currentNode->next;

    currentNode->next = newNode;
}

void AddToStartListIntID(NodeIntID** headPointer, int id, int value)
{
    NodeIntID* newNode = CreateNodeIntID(id, value);

    //New node points to the head
    newNode->next = *headPointer;

    //Head pointer points to the newNode. Head is newNode now
    *headPointer = newNode;
}

NodeIntID* FindByIDListIntID(NodeIntID* head, int id)
{
    NodeIntID* currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->id == id) return currentNode;
        else currentNode = currentNode->next;
    }

    //This section only works when no id matches. When id matches, the function returns and does not execute this lines
    printf("Error: Node with given id does not exist, returning NULL");
    return NULL;
}

NodeIntID* FindByIDPreviousListIntID(NodeIntID* head, int id)
{
    NodeIntID* currentNode = head;
    NodeIntID* currentPreviousNode = NULL;

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
        printf("Error: Node with given id does not exist, returning NULL\n");
        return NULL;
    }

    //Error 2
    if (currentPreviousNode == NULL) printf("Error: Node with id %d is head, it has no previous NodeIntID, returning NULL\n", id);

    return currentPreviousNode;
}

void InsertByIDAfterListIntID(NodeIntID* head, int newNodeID, int newNodeValue, int insertTargetID)
{
    NodeIntID* newNode = CreateNodeIntID(newNodeID, newNodeValue);
    NodeIntID* insertTarget = FindByIDListIntID(head, insertTargetID);

    //Insert target must point to the newNode and the newNode must point to the next node after the insert target
    NodeIntID* nextNodeAfterTarget = insertTarget->next;
    insertTarget->next = newNode;
    newNode->next = nextNodeAfterTarget;
}

void InsertByIDBeforeListIntID(NodeIntID** headPointer, int newNodeID, int newNodeValue, int insertTargetID)
{
    NodeIntID* currentPreviousNode = FindByIDPreviousListIntID(*headPointer, insertTargetID);

    //If inserting before first node, just use AddToStartListIntID()
    if (currentPreviousNode == NULL) AddToStartListIntID(headPointer, newNodeID, newNodeValue);

    //If not inserting before headPointer
    else
    {
        NodeIntID *currentNode = currentPreviousNode->next;

        //Create new node to insert
        NodeIntID *newNode = CreateNodeIntID(newNodeID, newNodeValue);

        //Link the node to the list
        //Current previous node must point new node and new node must point current node
        currentPreviousNode->next = newNode;
        newNode->next = currentNode;
    }
}

void RemoveLastListIntID(NodeIntID* head)
{
    //Starting nodes to go
    NodeIntID* currentNode = head;
    NodeIntID* currentPreviousNode = NULL;

    //Find last node by counting from head
    while (currentNode->next != NULL)
    {
        currentPreviousNode = currentNode;
        currentNode = currentNode->next;
    }

    //Unlink the last node
    currentPreviousNode->next = NULL;

    //Remove the last node from the heap
    free(currentNode);
}

void RemoveHeadListIntID(NodeIntID** headPointer)
{
    //Store first node to remove it from the heap
    NodeIntID* firstNode = *headPointer;

    //Make the head second node
    *headPointer = (*headPointer)->next;

    //Remove the head from the heap
    free(firstNode);
}

void RemoveByIDListIntID(NodeIntID** headPointer, int id)
{
    //Starting nodes to go
    NodeIntID* currentPreviousNode = FindByIDPreviousListIntID(*headPointer, id);

    //If removing first node
    if (currentPreviousNode == NULL) RemoveHeadListIntID(headPointer);

    //If not removing first node
    else
    {
        NodeIntID *currentNode = currentPreviousNode->next;

        //Unlinking
        currentPreviousNode->next = currentNode->next;

        //Remove the node from the heap
        free(currentNode);
    }
}

int RunLinkedListIntIDTests()
{
    NodeIntID* head = CreateNodeIntID(404, 4);

    AppendToListIntID(head, 505, 5);
    AppendToListIntID(head, 606, 6);
    AppendToListIntID(head, 707, 7);
    AppendToListIntID(head, 808, 8);

    printf("List:\n");
    PrintListIntID(head);

    printf("\nValue of the node with id 404: %d\n", FindByIDListIntID(head, 404)->value);

    printf("Value of the previous node of the node with id 606: %d\n\n", FindByIDPreviousListIntID(head, 606)->value);

    printf("List without the node with id 505:\n");
    RemoveByIDListIntID(&head, 505);
    PrintListIntID(head);

    printf("\nList without the node with id 404, which is the head:\n");
    RemoveByIDListIntID(&head, 404);
    PrintListIntID(head);

    printf("\nList without the last node:\n");
    RemoveLastListIntID(head);
    PrintListIntID(head);

    printf("\nList without the head, again:\n");
    RemoveHeadListIntID(&head);
    PrintListIntID(head);

    printf("\nList with a new NodeIntID with id 909 and value 9 in the beginning:\n");
    AddToStartListIntID(&head, 909, 9);
    PrintListIntID(head);

    printf("\nList with a new NodeIntID with id 101 and value 1, after the NodeIntID with id 707:\n");
    InsertByIDAfterListIntID(head, 101, 1, 707);
    PrintListIntID(head);

    printf("\nList with a new NodeIntID with id 202 and value 2, before the NodeIntID with id 707:\n");
    InsertByIDBeforeListIntID(&head, 202, 2, 707);
    PrintListIntID(head);

    printf("\nList with a new NodeIntID with id 303 and value 3, before the NodeIntID with id 909, which is the head:\n");
    InsertByIDBeforeListIntID(&head, 303, 3, 909);
    PrintListIntID(head);

    return 0;
}