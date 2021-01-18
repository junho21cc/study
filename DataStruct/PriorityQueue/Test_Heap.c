#include "Heap.h"

int main()
{
	Heap* H = Heap_Create(3);
	HeapNode MinNode;

	int Data[6] = { 12, 87, 111, 34, 16, 75 };

	Heap_Insert(H, Data[0]);
	Heap_Insert(H, Data[1]);
	Heap_Insert(H, Data[2]);
	Heap_Insert(H, Data[3]);
	Heap_Insert(H, Data[4]);
	Heap_Insert(H, Data[5]);



	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	return 0;
}