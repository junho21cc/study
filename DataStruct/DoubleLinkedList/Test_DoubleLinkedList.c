#include "DoubleLinkedList.h"


int main(void)
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	/* ��忡 5�� �߰� */
	for (i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// ����Ʈ ���
	i = 0;
	Current = List;
	while (Current) {
		printf("List[%d] : %d\n", i, Current->Data);
		i++;
		Current = Current->NextNode;
	}
	Count = DLL_GetNodeCount(List);
	printf("���� ����Ʈ�� ����� ������ %d�� �̴�.\n", Count);

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	i = 0;
	Current = List;
	while (Current) {
		printf("List[%d] : %d\n", i, Current->Data);
		i++;
		Current = Current->NextNode;
	}
	Count = DLL_GetNodeCount(List);
	printf("���� ����Ʈ�� ����� ������ %d�� �̴�.\n", Count);

	// ��� ��带 �޸𸮿��� ����
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
	printf("���� ����Ʈ�� ����� ������ %d�� �̴�.\n", Count);
	//return 0;
}