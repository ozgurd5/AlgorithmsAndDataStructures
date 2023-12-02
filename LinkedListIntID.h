#ifndef ALGORITHMSANDDATASTRUCTURES_LINKEDLISTINTID_H
#define ALGORITHMSANDDATASTRUCTURES_LINKEDLISTINTID_H

typedef struct NodeIntID NodeIntID;
struct NodeIntID
{
    int value;
    int id;
    struct NodeIntID* next;
};

int RunLinkedListIntIDTests();

///\n Creates a NodeIntID and returns its memory address, without linking
NodeIntID* CreateNodeIntID(int id, int value);
void PrintListIntID(NodeIntID* head);

///\n New node becomes head so we need the double pointer to change a pointer
void AddToStartListIntID(NodeIntID** headPointer, int id, int value);
void AppendToListIntID(NodeIntID* head, int id, int value);

///\n We could remove the head so we need the double pointer the head
void RemoveByIDListIntID(NodeIntID** headPointer, int id);
///\n We could remove the head so we need the double pointer the head
void RemoveHeadListIntID(NodeIntID** headPointer);
//
void RemoveLastListIntID(NodeIntID* head);

///\n Finds the node by id, inserts before it\n\n
///We could insert before head wo se need the double pointer to change the head
void InsertByIDBeforeListIntID(NodeIntID** headPointer, int newNodeID, int newNodeValue, int insertTargetID);
///\n Finds the node by id, inserts after it
void InsertByIDAfterListIntID(NodeIntID* head, int newNodeID, int newNodeValue, int insertTargetID);

///\n Finds the node by id, returns the previous node of it
NodeIntID* FindByIDPreviousListIntID(NodeIntID* head, int id);
NodeIntID* FindByIDListIntID(NodeIntID* head, int id);

#endif //ALGORITHMSANDDATASTRUCTURES_LINKEDLISTINTID_H
