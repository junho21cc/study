#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
// ��������
BTNode* BT_CreateNode(int Data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	NewNode->Data = Data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}
// ���ο� ����
void BT_Insert(BTNode** root, int Data)
{
	// �Ѹ��� �ƹ��͵� ������
	BTNode* NewNode = NULL;
	if (!(*root))
	{
		NewNode = (BTNode*)malloc(sizeof(BTNode));
		NewNode->Data = Data;
		NewNode->left = NULL;
		NewNode->right = NULL;
		*root = NewNode;
		return;
		// �����ϰ��� �ϴ� ������ ���� left child�� right child�� ���ؼ� �����Ѵ�.

		if (Data < (*root)->Data) {
			BT_Insert(&(*root)->left, Data);
		}
		else if (Data > (*root)->Data) {
			BT_Insert(&(*root)->right, Data);
		}
	}

}

// ���� Ž�� (����Ž���� ����Ž���� ������ �ٸ��⶧���� �������� �ʾҴ�.)
void BT_InOrderSearch(BTNode* root)
{
	if (root) {
		BT_InOrderSearch(root->left);
		printf("%d ", root->Data);
		BT_InOrderSearch(root->right);
	}
}