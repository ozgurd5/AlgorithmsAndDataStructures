#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
    int id;
    int value;
    struct node* next;
};

//Creates a node and returns its memory address, without linking
struct node* CreateNode(int id, int value)
{
    //Allocate memory from heap
    node* newNode = (node*)malloc(sizeof (node));

    //Assign given values
    newNode->id = id;
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

void PrintList(node* head)
{
    //Starting node to go
    node* currentNode = head;

    //Go through all the nodes in the list and print
    while (currentNode != NULL)
    {
        printf("id: %d - value: %d\n", currentNode->id, currentNode->value);
        currentNode = currentNode->next;
    }
}

node* FindByID(node* head, int id)
{
    //Starting node to go
    node* currentNode = head;

    //Go through all the nodes in the list until the given id matches
    while (currentNode != NULL)
    {
        if (currentNode->id == id) return currentNode;
        else currentNode = currentNode->next;
    }

    //This section only works when no id matches. When id matches, the function returns and does not execute this lines
    printf("Warning: Node with given id does not exist, returning NULL");
    return NULL;
}

//Find by id, returns the previous node of it
node* FindByIDPrevious(node* head, int id)
{
    //Default values
    node* currentNode = head;
    node* currentPreviousNode = NULL;

    //Error flag
    int isIDMatched = 0;

    //Go through all the nodes in the list until the given id matches
    while (currentNode != NULL)
    {
        if (currentNode->id == id)
        {
            isIDMatched = 1;
            break;
        }

        //Store current nodes
        currentPreviousNode = currentNode;
        currentNode = currentNode->next;
    }

    //Warning 1
    if (!isIDMatched)
    {
        printf("Warning: Node with given id does not exist, returning NULL\n");
        return NULL;
    }

    //Warning 2
    if (currentPreviousNode == NULL) printf("Warning: Node with id %d is head, it has no previous node, returning NULL\n", id);

    return currentPreviousNode;
}

void AddToLast(node* head, int id, int value)
{
    //Create new node to add to the end
    node* newNode = CreateNode(id, value);

    //Find last node by counting from head
    node* currentNode = head;
    while (currentNode->next != NULL) currentNode = currentNode->next;

    //Link the new node
    currentNode->next = newNode;
}

void AddToStart(node** headPointer, int id, int value)
{
    //Create new node to add to the start
    node* newNode = CreateNode(id, value);

    //Link new node to the first node
    newNode->next = *headPointer;

    //Make the new node head/first node
    *headPointer = newNode;
}

void InsertAfterByID(node* head, int newNodeID, int newNodeValue, int insertTargetID)
{
    //Create new node to insert
    node* newNode = CreateNode(newNodeID, newNodeValue);

    //Find node to insert after
    node* insertTarget = FindByID(head, insertTargetID);

    //Link the new node to the list
    //Insert target must point new node and new node point the next node after the insert target
    node* nextNodeAfterTarget = insertTarget->next;
    insertTarget->next = newNode;
    newNode->next = nextNodeAfterTarget;
}

void InsertBeforeByID(node** headPointer, int newNodeID, int newNodeValue, int insertTargetID)
{
    //Starting node to go
    node* currentPreviousNode = FindByIDPrevious(*headPointer, insertTargetID);

    //If inserting before first node, just use AddToStart()
    if (currentPreviousNode == NULL) AddToStart(headPointer, newNodeID, newNodeValue);

    //If not inserting before headPointer
    else
    {
        node *currentNode = currentPreviousNode->next;

        //Create new node to insert
        node *newNode = CreateNode(newNodeID, newNodeValue);

        //Link the node to the list
        //Current previous node must point new node and new node must point current node
        currentPreviousNode->next = newNode;
        newNode->next = currentNode;
    }
}

void RemoveLastNode(node* head)
{
    //Starting nodes to go
    node* currentNode = head;
    node* currentPreviousNode = NULL;

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

void RemoveHead(node** headPointer)
{
    //Store first node to remove it from the heap
    node* firstNode = *headPointer;

    //Make the head second node
    *headPointer = (*headPointer)->next;

    //Remove the head from the heap
    free(firstNode);
}

void RemoveFromListByID(node** headPointer, int id)
{
    //Starting nodes to go
    node* currentPreviousNode = FindByIDPrevious(*headPointer, id);

    //If removing first node
    if (currentPreviousNode == NULL) RemoveHead(headPointer);

    //If not removing first node
    else
    {
        node *currentNode = currentPreviousNode->next;

        //Unlinking
        currentPreviousNode->next = currentNode->next;

        //Remove the node from the heap
        free(currentNode);
    }
}

int main()
{
    //Create a list
    node* head = CreateNode(404, 4);

    //Add new nodes with the ids of 505, 606, 707, 808, values of 5, 6, 7, 8 to the end
    AddToLast(head, 505, 5);
    AddToLast(head, 606, 6);
    AddToLast(head, 707, 7);
    AddToLast(head, 808, 8);

    //Print the list
    printf("List:\n");
    PrintList(head);

    //Find by id and print
    printf("\nValue of the node with id 404: %d\n", FindByID(head, 404)->value);

    //Find by id and print previous
    printf("Value of the previous node of the node with id 606: %d\n\n", FindByIDPrevious(head, 606)->value);

    //Remove from middle
    printf("List without the node with id 505:\n");
    RemoveFromListByID(&head, 505);
    PrintList(head);

    //Remove the head
    printf("\nList without the node with id 404, which is the head:\n");
    RemoveFromListByID(&head, 404);
    PrintList(head);

    //Remove the last
    printf("\nList without the last node:\n");
    RemoveLastNode(head);
    PrintList(head);

    //Remove the head again
    printf("\nList without the head, again:\n");
    RemoveHead(&head);
    PrintList(head);

    //Add new node with id 909 and value 24 in the beginning
    printf("\nList with a new node with id 909 and value 9 in the beginning:\n");
    AddToStart(&head, 909, 9);
    PrintList(head);

    //Add new node with id 101 and value 1 after the node with id 707
    printf("\nList with a new node with id 101 and value 1 after the node with id 707:\n");
    InsertAfterByID(head, 101, 1, 707);
    PrintList(head);

    //Add new node with id 202 and value 2 before the node with id 707
    printf("\nList with a new node with id 202 and value 2 before the node with id 707:\n");
    InsertBeforeByID(&head, 202, 2, 707);
    PrintList(head);

    //Add new node with id 303 and value 3 before the node with id 909, which is the head
    printf("\nList with a new node with id 303 and value 3 before the node with id 909, which is the head:\n");
    InsertBeforeByID(&head, 303, 3, 909);
    PrintList(head);

    return 0;
}