#include "Heap.h"

Heap* Heap_Create(int IntitialSize)
{
	Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
	NewHeap->Capacity = IntitialSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);

	printf("size: %d\n", sizeof(HeapNode));

	return NewHeap;
}

void Heap_Destroy(Heap* Heap)
{
	free(Heap->Nodes);
	free(Heap);
}

void Heap_Insert(Heap* H, int NewData)
{
	int CurrentNode = H->UsedSize;
	int ParentNode = Heap_GetParent(CurrentNode);

	if (H->UsedSize == H->Capacity)
	{
		H->Capacity *= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}

	H->Nodes[CurrentNode].Data = NewData;

	while (CurrentNode > 0 && H->Nodes[CurrentNode].Data < H->Nodes[ParentNode].Data)
	{
		Heap_SwapNodes(H, CurrentNode, ParentNode);

		CurrentNode = ParentNode;
		ParentNode = Heap_GetParent(CurrentNode);
	}

	H->UsedSize++;
}

void Heap_SwapNodes(Heap* H, int Index1, int Index2)
{
	int CopySize = sizeof(HeapNode);
	HeapNode* Temp = (HeapNode*)malloc(CopySize);

	memcpy(Temp, &H->Nodes[Index1], CopySize);
	memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
	memcpy(&H->Nodes[Index2], Temp, CopySize);
	
	free(Temp);
}