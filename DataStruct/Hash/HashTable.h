#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* Data;
	struct tageNode* Next;
} Node;

typedef struct tagHashTable
{
	int TableSize;
	Node** Table;
} HashTable;

HashTable* HT_CreateHashTable(int TableSize);
void HT_DestroyHashTable(HashTable* HT);

Node* HT_CreateNode(char* Data);
void HT_DestroyNode(Node* TheNode);
void HT_DestroyList(Node* L);

void HT_Set(HashTable* HT, char* Data);
char* HT_Get(HashTable* HT, char* Data);
int HT_Hash(char* Data, int TableSize);
