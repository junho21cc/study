#include "LinkedList.h"

int main(void)
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	/* 노드 5개 추가 */
	for (int i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(10 + i);
		SLL_AppendNode(&List, NewNode);
	}
	/* 리스트 출력 */
	i = 0;
	Current = List;
	while(Current) {
		printf("List [%d] : %d\n", i, Current->Data);
		Current = Current->NextNode;
		i++;
	}
	printf("\n\n");
	/* 리스트의 세 번째 노드 뒤에 새 노드 삽입 */

	Current = SLL_GetNodeAt(List, 3);
	NewNode = SLL_CreateNode(20);

	SLL_InsertAfter(Current, NewNode);
	/* 리스트 출력 */
	i = 0;
	Current = List;
	while (Current) {
		printf("List [%d] : %d\n", i, Current->Data);
		Current = Current->NextNode;
		i++;
	}
	/* 모든 노드를 메모리에서 제거 */
	Current = List;
	while (Current) {
		Node* NextNode = Current->NextNode;

		SLL_RemoveNode(&List, Current);
		SLL_DestroyNode(Current);
		Current = NextNode;
	}
}