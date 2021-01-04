#include "DoubleLinkedList.h"



Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		(*Head) = NewNode;
		NewNode->PrevNode = NULL;
		NewNode->NextNode = NULL;

	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
		NewNode->NextNode = NULL;
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;
	Current->NextNode = NewNode;
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		if (Remove) {
			(*Head) = Remove->NextNode;
			if (Remove->NextNode) {
				Remove->NextNode->PrevNode = NULL;
			}
		}
	}
	else
	{
		if (Remove) {
			if (Remove->PrevNode) {
				Remove->PrevNode->NextNode = Remove->NextNode;
			}
			if (Remove->NextNode) {
				Remove->NextNode->PrevNode = Remove->PrevNode;
			}
		}
	}

}

Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != NULL && Location > 0)
	{
		Current = Current->NextNode;
		Location--;
	}
	return Current;
}

int DLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	while (Head)
	{
		Head = Head->NextNode;
		Count++;
	}
	return Count;
}
