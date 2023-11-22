#include <stdio.h>
#include <stdlib.h>

//The reason we have **headPointer as the parameter in some function:

//If we want to change the first node (remove, insert before etc.), we need to change the first node, not the head pointer itself, which is our..
// ..only access point to the list. Head pointer must point another node and it must continue to exist.

//With *head in the parameter, we can not change which node is the head is pointing. We can read the address inside the given pointer, reach..
//..that address and modify the values of it. So with *head in the parameter we can read address of a node, go to that node and modify that node.

//With **head in the parameter, we can change which node is the head is pointing. We can read the address of an address, go to that address and..
//..change that address.

//Tips with while loops:

//Using "while (currentNode->next != NULL) currentNode = currentNode->next;" makes us go through every node except the last one and currentNode..
//..gives us the last node after the loop

//Using "while (currentNode != NULL) currentNode = currentNode->next;" makes us go through every node and currentNode gives us NULL after the loop

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
    printf("Error: Node with given id does not exist");
    return NULL;
}

//TODO: FIND BY ID WITH PREVIOUS

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

    //Link new node
    newNode->next = *headPointer;

    //Make the new node head
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

void InsertBeforeByID(node* head, int newNodeID, int newNodeValue, int insertTargetID)
{
    //Create new node to insert
    node* newNode = CreateNode(newNodeID, newNodeValue);

    //TODO: new function
    //Starting nodes to go. We can't use the FindByID() function in here because we need to store both current and previous nodes when we go..
    //..through the list. We need previous node because we will link it to our new node.
    node* currentNode = head;
    node* currentPreviousNode;

    //Error flag
    int isIDMatched = 0;

    //Go through all the nodes in the list until the given id matches
    while (currentNode != NULL)
    {
        if (currentNode->id == insertTargetID)
        {
            isIDMatched = 1;
            break;
        }

        //Store current nodes
        currentPreviousNode = currentNode;
        currentNode = currentNode->next;
    }

    //Error
    if (!isIDMatched)
    {
        printf("Error: Node with given id does not exist");
        return;
    }

    //Link the node to the list
    //Current previous node must point new node and new node must point current node
    currentPreviousNode->next = newNode;
    newNode->next = currentNode;
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

    //Make the head next node of the first node
    *headPointer = (*headPointer)->next;

    //Remove the head from the heap
    free(firstNode);
}

void RemoveFromListByID(node** headPointer, int id)
{
    //TODO: new function
    //Starting nodes to go. We can't use the FindByID() function in here because we need to store both current and previous nodes when we go..
    //..through the list. We need previous node because before removing the current node we need to link previous to the next.
    node* currentPreviousNode = NULL;
    node* currentNode = *headPointer;

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

    //Error
    if (!isIDMatched)
    {
        printf("Error: Node with given id does not exist");
        return;
    }

    //To unlink the first node, we need to change what head is pointing. It must point the next node of course.
    if (currentPreviousNode == NULL) *headPointer = currentNode->next;

    //Unlinking
    else currentPreviousNode->next = currentNode->next;

    //Remove the node from the heap
    free(currentNode);
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

    //Find with index and print
    printf("\nValue of the node with id 404: %d\n\n", FindByID(head, 404)->value);

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
    InsertBeforeByID(head, 202, 2, 707);
    PrintList(head);

    return 0;
}