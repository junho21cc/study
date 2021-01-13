#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Key;
	int Value;

	struct tageNode* Next;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
	int TableSize;
	List* Table;
} HashTable;


