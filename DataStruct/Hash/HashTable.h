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

Node* HT_CreateNode(int Key, int Value);
void HT_DestroyNode(Node* TheNode);

void HT_Set(HashTable* HT, int Key, int Value);
int HT_Get(HashTable* HT, int Key);
int HT_Hash(int Key, int KeyLength, int TableSize);
