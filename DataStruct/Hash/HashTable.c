#include "HashTable.h"

HashTable* HT_CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (Node**)malloc(sizeof(Node*) * TableSize);

	memset(HT->Table, 0, sizeof(Node*) * TableSize);

	HT->TableSize = TableSize;

	return HT;
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

void HT_Set(HashTable* HT, int Key, int Value)
{
	int Address = HT_Hash(Key, strlen(Key), HT->TableSize);
	Node* NewNode = HT_CreateNode(Key, Value);

	if (HT->Table[Address] == NULL)
	{
		HT->Table[Address] = NewNode;
	}
	else
	{
		Node** L = HT->Table[Address];
		NewNode->Next = L;
		HT->Table[Address] = NewNode;

		printf("Collision occured : Key(%s), Address(%d)\n", Key, Address);
	}
}

int HT_Get(HashTable* HT, int Key)
{
	int Address = HT_Hash(Key, strlen(Key), HT->TableSize);

	List TheList = HT->Table[Address];
	List Target = NULL;

	if (TheList == NULL)
	{
		return NULL;
	}

	while (1)
	{
		if (strcmp(TheList->Key, Key) == 0)
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

		return Target->Value;
	}
}

void HT_DestroyList(List L)
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

void HT_DestroyHashTable(HashTable* HT)
{
	for (int i = 0; i < HT->TableSize; i++)
	{
		List L = HT->Table[i];

		HT_DestroyList(L);
	}

	free(HT->Table);
	free(HT);
}

int HT_Hash(int Key, int KeyLength, int TableSize)
{
	int HashValue = 0;

	for (int i = 0; i < KeyLength; i++)
	{
		HashValue = (HashValue << 3) + Key[i];
	}

	HashValue = HashValue % TableSize;

	return HashValue;
}
