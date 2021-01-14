#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
	struct tageNode* Next;
} Node;

typedef struct tagHashTable
{
	int TableSize;
	Node** Table;
} HashTable;

HashTable* HT_CreateHashTable(int TableSize);
void HT_DestroyHashTable(HashTable* HT);

Node* HT_CreateNode(int Data);
void HT_DestroyNode(Node* TheNode);
void HT_DestroyList(Node* L);

void HT_Set(HashTable* HT, int Data);
int HT_Get(HashTable* HT, int Data);
int HT_Hash(int Data, int TableSize);
