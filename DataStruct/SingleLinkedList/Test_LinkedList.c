#include "LinkedList.h"

int main(void)
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	/* ��� 5�� �߰� */
	for (int i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(10 + i);
		SLL_AppendNode(&List, NewNode);
	}
	/* ����Ʈ ��� */
	i = 0;
	Current = List;
	while(Current) {
		printf("List [%d] : %d\n", i, Current->Data);
		Current = Current->NextNode;
		i++;
	}
	printf("\n\n");
	/* ����Ʈ�� �� ��° ��� �ڿ� �� ��� ���� */

	Current = SLL_GetNodeAt(List, 3);
	NewNode = SLL_CreateNode(20);

	SLL_InsertAfter(Current, NewNode);
	/* ����Ʈ ��� */
	i = 0;
	Current = List;
	while (Current) {
		printf("List [%d] : %d\n", i, Current->Data);
		Current = Current->NextNode;
		i++;
	}
	/* ��� ��带 �޸𸮿��� ���� */
	Current = List;
	while (Current) {
		Node* NextNode = Current->NextNode;

		SLL_RemoveNode(&List, Current);
		SLL_DestroyNode(Current);
		Current = NextNode;
	}
}