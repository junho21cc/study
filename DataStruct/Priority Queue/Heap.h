#pragma once
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct TagHeapNode
{
	int Data
}HeapNode;

typedef struct TagHeap
{
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
}Heap;