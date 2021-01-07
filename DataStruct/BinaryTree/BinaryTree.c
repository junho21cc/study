#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 2021.01.05 ����
BTNode* BT_CreateNode(int Data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	NewNode->Data = Data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

/*
// 2021.01.06 ����
void BT_Insert(BTNode** root, int Data)
{
	// �Ѹ��� �ƹ��͵� ������
	BTNode* NewNode = NULL;
	if ((*root))
	{
		NewNode = (BTNode*)malloc(sizeof(BTNode));
		NewNode->Data = Data;
		NewNode->left = NULL;
		NewNode->right = NULL;
		*root = NewNode;
		return;

		}

		// �����ϰ��� �ϴ� ������ ���� left child�� right child�� ���ؼ� �����Ѵ�.

		if (Data < (*root)->Data) {
			BT_Insert(&(*root)->left, Data);
		}
		else if (Data > (*root)->Data) {
			BT_Insert(&(*root)->right, Data);
	}
}
*/

// 2021.01.07 (�˰���å ����)
// �� �̸��� Ž���� ���� �ڷᱸ���ΰ�?-> Ž���ϱ⿡ ȿ������ ������ �ֱ⶧����?
void BT_AddChildNode(BTNode* Parent, BTNode* Child)
{
	if (Parent->left == NULL)
	{
		Parent->left = Child;
	}
	else
	{
		BTNode* CurrentNode = Parent->left;
		while (CurrentNode->right != NULL)
		{
			CurrentNode = CurrentNode->right;
		}
		CurrentNode->right = Child;
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

// Ư���� ã�� �Լ� (k-mooc ���� ����)
void BT_SearchNode(BTNode* root, int SearchData) 
{
	if (SearchData == root->Data)
	{
		printf("Bingo\n");
	}
	else if (SearchData > root->Data)
	{
		if (root->left != NULL) {
			root = root->right;
			BT_SearchNode(root, SearchData);
		}
		else {
			printf("Not found\n");
		}
	}
	else if (SearchData < root->Data)
	{
		if (root->right != NULL) {
			root = root->left;
			BT_SearchNode(root, SearchData);
		}
		else {
			printf("Not found\n");
		}
	}
}

// �߰� 2021.01.07 (k-mooc ���� ����)
// ����_1: �ð� ���⵵�� ���α׷����� ȿ������ �����̱⶧���� ����ϴ°ǰ�?
// ����_2: �޸𸮸� ���� �Ҵ�޾Ƽ� �����ϴ� ������ root�� �����ϴ� �����̱⶧���� �Ķ���͸� BTNode** root��� �ؾߵǴ°��� �ƴѰ�?
// ����_3: C++���� root->left->insert(root, InsertData)�� � �ǹ̸� ���°�
void BT_InsertNode(BTNode** root, int InsertData) 
{
	if ((*root))
	{
		BTNode* Current = (*root);


		if (InsertData == Current->Data)
		{
			printf("No duplicate data\n");
		}
		else if (InsertData < Current->Data)
		{
			if (Current->right != NULL) {
				BT_InsertNode(&Current, InsertData);
			}
			else {
				Current->left = (BTNode*)malloc(sizeof(BTNode));
				Current->left->Data = InsertData;
				Current->left->left = NULL;
				Current->left->right = NULL;
			}
		}
		else if (InsertData > Current->Data)
		{
			if (Current->left != NULL) {
				BT_InsertNode(&Current, InsertData);
			}
			else {
				Current->right = (BTNode*)malloc(sizeof(BTNode));
				Current->right->Data = InsertData;
				Current->right->left = NULL;
				Current->right->right = NULL;
			}
		}
	}
}


// ����
// ��尡 child�� �����ִ����� �Ǵ��ϰ� �����Ѵ�.
// child�� ���ٸ� �׳� ����
// child�� 1�� �ִٸ� child�� subtree�� �÷��ش�.
// child�� 2�� �ִٸ� left child�� �ִ밪 �Ǵ� right child�� �ּڰ��� �÷��ش�. 
