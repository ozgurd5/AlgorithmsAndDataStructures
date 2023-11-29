#ifndef ALGORITHMSANDDATASTRUCTURES_LINKEDLIST_H
#define ALGORITHMSANDDATASTRUCTURES_LINKEDLIST_H

typedef struct node node;
struct node
{
    int id;
    int value;
    struct node* next;
};

int RunLinkedListTests();
void RemoveFromListByID(node** headPointer, int id);
void RemoveHead(node** headPointer);
void RemoveLastNode(node* head);
void InsertBeforeByID(node** headPointer, int newNodeID, int newNodeValue, int insertTargetID);
void InsertAfterByID(node* head, int newNodeID, int newNodeValue, int insertTargetID);
void AddToStart(node** headPointer, int id, int value);
void AddToLast(node* head, int id, int value);
node* FindByIDPrevious(node* head, int id);
node* FindByID(node* head, int id);
void PrintList(node* head);
struct node* CreateNode(int id, int value);

#endif //ALGORITHMSANDDATASTRUCTURES_LINKEDLIST_H
