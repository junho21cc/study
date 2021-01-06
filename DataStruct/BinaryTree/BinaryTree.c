#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
// 이전버전
BTNode* BT_CreateNode(int Data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	NewNode->Data = Data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}
// 새로운 버전
void BT_Insert(BTNode** root, int Data)
{
	// 뿌리에 아무것도 없을때
	BTNode* NewNode = NULL;
	if (!(*root))
	{
		NewNode = (BTNode*)malloc(sizeof(BTNode));
		NewNode->Data = Data;
		NewNode->left = NULL;
		NewNode->right = NULL;
		*root = NewNode;
		return;
		// 삽입하고자 하는 데이터 값이 left child와 right child를 비교해서 삽입한다.

		if (Data < (*root)->Data) {
			BT_Insert(&(*root)->left, Data);
		}
		else if (Data > (*root)->Data) {
			BT_Insert(&(*root)->right, Data);
		}
	}

}

// 중위 탐색 (전위탐색과 후위탐색은 순서만 다르기때문에 구현하지 않았다.)
void BT_InOrderSearch(BTNode* root)
{
	if (root) {
		BT_InOrderSearch(root->left);
		printf("%d ", root->Data);
		BT_InOrderSearch(root->right);
	}
}