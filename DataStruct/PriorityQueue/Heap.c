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

void Heap_DeleteMin(Heap* H, HeapNode* Root)
{
	int ParentIndex = 0;
	int LeftIndex = 0;
	int RightIndex = 0;

	memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
	memset(&H->Nodes[0], 0, sizeof(HeapNode));

	H->UsedSize--;
	Heap_SwapNodes(H, 0, H->UsedSize);

	LeftIndex = Heap_GetLeftChild(0);
	RightIndex = LeftIndex + 1;

	while (1)
	{
		int SelectedChild = 0;

		if (LeftIndex >= H->UsedSize)
		{
			break;
		}

		if (RightIndex >= H->UsedSize)
		{
			SelectedChild = LeftIndex;
		}
		else
		{
			if (H->Nodes[LeftIndex].Data > H->Nodes[RightIndex].Data)
			{
				SelectedChild = RightIndex;
			}
			else
			{
				SelectedChild = LeftIndex;
			}
		}

		if (H->Nodes[SelectedChild].Data < H->Nodes[ParentIndex].Data)
		{
			Heap_SwapNodes(H, ParentIndex, SelectedChild);
			ParentIndex = SelectedChild;
		}
		else
		{
			break;
		}

		LeftIndex = Heap_GetLeftChild(ParentIndex);
		RightIndex = LeftIndex + 1;
	}

	if (H->UsedSize < (H->Capacity / 2))
	{
		H->Capacity /= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
}

int Heap_GetParent(int Index)
{
	return (int)((Index - 1) / 2);
}

int Heap_GetLeftChild(int Index)
{
	return (2 * Index) + 1;
}

void Heap_PrintNodes(Heap* H)
{
	for (int i = 0; i < H->UsedSize; i++)
	{
		printf("%d  ", H->Nodes[i].Data);
	}
	printf("\n");
}

