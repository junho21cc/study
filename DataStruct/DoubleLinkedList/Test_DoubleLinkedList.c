#include "DoubleLinkedList.h"


int main(void)
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	/* 노드에 5개 추가 */
	for (i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// 리스트 출력
	i = 0;
	Current = List;
	while (Current) {
		printf("List[%d] : %d\n", i, Current->Data);
		i++;
		Current = Current->NextNode;
	}
	Count = DLL_GetNodeCount(List);
	printf("현재 리스트의 노드의 개수는 %d개 이다.\n", Count);

	// 리스트의 세 번째 칸 뒤에 노드 삽입
	printf("\nInserting 3000 After [2]...\n\n");

	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// 리스트 출력
	i = 0;
	Current = List;
	while (Current) {
		printf("List[%d] : %d\n", i, Current->Data);
		i++;
		Current = Current->NextNode;
	}
	Count = DLL_GetNodeCount(List);
	printf("현재 리스트의 노드의 개수는 %d개 이다.\n", Count);

	// 모든 노드를 메모리에서 제거
	printf("\nDestroying List...\n");

	Current = List;
	while (Current) {
		Node* NextNode = Current->NextNode;

		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
		Current = NextNode;
	}

	Count = DLL_GetNodeCount(List);
	printf("현재 리스트의 노드의 개수는 %d개 이다.\n", Count);
	//return 0;
}