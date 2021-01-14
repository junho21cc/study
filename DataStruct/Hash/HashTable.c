#include "HashTable.h"

HashTable* HT_CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (Node*)malloc(sizeof(Node*) * TableSize);

	memset(HT->Table, 0, sizeof(Node*) * TableSize);

	HT->TableSize = TableSize;

	return HT;
}

void HT_DestroyHashTable(HashTable* HT)
{
	for (int i = 0; i < HT->TableSize; i++)
	{
		Node* L = HT->Table[i];

		HT_DestroyList(L);
	}

	free(HT->Table);
	free(HT);
}

Node* HT_CreateNode(int Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = Data;
	NewNode->Next = NULL;

	return NewNode;
}

void HT_DestroyNode(Node* TheNode)
{
	free(TheNode);
}

void HT_Set(HashTable* HT, int Data)
{
	int Address = HT_Hash(Data, HT->TableSize);
	Node* NewNode = HT_CreateNode(Data);

	if (HT->Table[Address] == NULL)
	{
		HT->Table[Address] = NewNode;
	}
	else
	{
		Node* L = HT->Table[Address];
		NewNode->Next = L;
		HT->Table[Address] = NewNode;

		printf("Collision occured : Data(%d), Address(%d)\n", Data, Address);
	}
}

int HT_Get(HashTable* HT, int Data)
{
	int Address = HT_Hash(Data, HT->TableSize);

	Node* TheList = HT->Table[Address];
	Node* Target = NULL;

	if (TheList == NULL)
	{
		return NULL;
	}

	while (1)
	{
		if (TheList->Data == Data)
		{
			Target = TheList;
			break;
		}

		if (TheList->Next == NULL) 
		{
			return NULL;
		}
		else
		{
			TheList = TheList->Next;
		}
	}
	return Target->Data;
}

void HT_DestroyList(Node* L)
{
	if (L == NULL)
	{
		return;
	}

	if (L->Next != NULL)
	{
		HT_DestroyList(L->Next);
	}

	HT_DestroyNode(L);
}



int HT_Hash(int Data, int TableSize)
{
	int Hash_Index = Data % TableSize;

	return Hash_Index;
}
