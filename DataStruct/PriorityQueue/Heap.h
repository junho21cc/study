#pragma once
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct TagHeapNode
{
	int Data;
}HeapNode;

typedef struct TagHeap
{
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
}Heap;

Heap* Heap_Create(int IntitialSize);
void Heap_Destroy(Heap* Heap);
void Heap_Insert(Heap* H, int NewData);
void Heap_SwapNodes(Heap* H, int Index1, int Index2);
void Heap_DeleteMin(Heap* H, HeapNode* Root);
int Heap_GetParent(int Index);
int Heap_GetLeftChild(int Index);
void Heap_PrintNodes(Heap* H);