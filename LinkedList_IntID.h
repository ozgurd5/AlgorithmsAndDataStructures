#ifndef ALGORITHMSANDDATASTRUCTURES_LINKEDLIST_INTID_H
#define ALGORITHMSANDDATASTRUCTURES_LINKEDLIST_INTID_H

typedef struct Node_IntID Node_IntID;
struct Node_IntID
{
    int value;
    int id;
    struct Node_IntID* next;
};

int TestLinkedList_IntID();

///\n Creates a Node_IntID and returns its memory address, without linking
Node_IntID* CreateNode_IntID(int id, int value);
void PrintList_IntID(Node_IntID* head);

///\n New node becomes head so we need the double pointer to change a pointer
void AddToStartOfList_IntID(Node_IntID** headPointer, int id, int value);
void AppendToList_IntID(Node_IntID* head, int id, int value);

Node_IntID* FindByIDInList_IntID(Node_IntID* head, int id);
///\n Finds the node by id, returns the previous node of it
Node_IntID* FindPreviousByIDInList_IntID(Node_IntID* head, int id);

///\n We could remove the head so we need the double pointer the head
void RemoveFirstInList_IntID(Node_IntID** headPointer);
///\n We could remove the head so we need the double pointer the head
void RemoveLastInList_IntID(Node_IntID** headPointer);
///\n We could remove the head so we need the double pointer the head
void RemoveByIDInList_IntID(Node_IntID** headPointer, int id);

///\n Finds the node by id, inserts before it\n\n
///We could insert before head wo se need the double pointer to change the head
void InsertBeforeByIDIntoList_IntID(Node_IntID** headPointer, int newNodeID, int newNodeValue, int insertTargetID);
///\n Finds the node by id, inserts after it
void InsertAfterByIDIntoList_IntID(Node_IntID* head, int newNodeID, int newNodeValue, int insertTargetID);

#endif //ALGORITHMSANDDATASTRUCTURES_LINKEDLIST_INTID_H
