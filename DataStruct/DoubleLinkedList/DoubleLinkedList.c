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

}

void DLL_RemoveNode(Node** Head, Node* Remove)
{


}

Node* DLL_GetNodeAt(Node* Head, int Location)
{
	return NULL;
}

int DLL_GetNodeCount(Node* Head)
{
	return 0;
}
