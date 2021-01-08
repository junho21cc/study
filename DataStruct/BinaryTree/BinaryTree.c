#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 2021.01.05 버전
BTNode* BT_CreateNode(int Data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	NewNode->Data = Data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}


// 2021.01.06 버전
void BT_InsertNode(BTNode** root, int Data)
{
	// 뿌리에 아무것도 없을때
	if ((*root))
	{
		// 삽입하고자 하는 데이터 값이 left child와 right child를 비교해서 삽입한다.
		if (Data < (*root)->Data) {
			BT_InsertNode(&(*root)->left, Data);
		}
		else if (Data > (*root)->Data) {
			BT_InsertNode(&(*root)->right, Data);
		}
		else
		{
			printf("No duplicate data\n");
		}
	}
	else
	{
		*root = BT_CreateNode(Data);
	}
}
	


// 2021.01.07 (알고리즘책 참고)
// 왜 이름에 탐색이 들어가는 자료구조인가?-> 탐색하기에 효율적인 조건이 있기때문에?
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


// 중위 탐색 (전위탐색과 후위탐색은 순서만 다르기때문에 구현하지 않았다.)
void BT_InOrderSearch(BTNode* root)
{
	if (root) {
		BT_InOrderSearch(root->left);
		printf("%d ", root->Data);
		BT_InOrderSearch(root->right);
	}
}

// 특정값 찾는 함수 (k-mooc 강의 참조)
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
/*
// 추가 2021.01.07 (k-mooc 강의 참조)
// 질문_1: 시간 복잡도는 프로그래밍의 효율적인 문제이기때문에 사용하는건가?
// 질문_2: 메모리를 새로 할당받아서 연결하는 과정은 root를 변경하는 과정이기때문에 파라미터를 BTNode** root라고 해야되는것이 아닌가?
// 질문_3: C++에서 root->left->insert(root, InsertData)는 어떤 의미를 갖는가
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
				Current = Current->left;
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
				Current = Current->right;
			}
		}
	}
}
*/

// 삭제
// 노드가 child를 갖고있는지를 판단하고 삭제한다.
// child가 없다면 그냥 삭제
// child가 1개 있다면 child의 subtree를 올려준다.
// child가 2개 있다면 left child의 최대값 (또는 right child의 최솟값) 을 올려준다. 

// 2021.01.08
BTNode* BT_SearchMaxNode(BTNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->right == NULL)
	{
		return root;
	}
	else
	{
		return BT_SearchMaxNode(root->right);
	}
}

BTNode* BT_RemoveNode(BTNode** root, BTNode* TagetNodeParent, int TagetData)
{
	BTNode* Taget = (*root);
	BTNode* Removed;

	if ((*root) == NULL)
	{
		return NULL;
	}

	if (Taget->Data > TagetData)
	{
		Removed = BT_RemoveNode(&(Taget->left), Taget, TagetData);
	}
	else if (Taget->Data < TagetData)
	{
		Removed = BT_RemoveNode(&(Taget->right), Taget, TagetData);
	}
	else
	{
		// 잎인경우
		if (Taget->left == NULL && Taget->right == NULL)
		{
			if (TagetNodeParent->left == Taget)
			{
				TagetNodeParent->left = NULL;
			}
			else
			{
				TagetNodeParent->right = NULL;
			}
		}
		// child가 하나인 경우
		else if (Taget->left == NULL || Taget->right == NULL)
		{

		}
		// child가 두개인 경우
		else
		{
			BTNode* LeftMaxNode = BT_SearchMaxNode(Taget->left);
			Removed = BT_RemoveNode((*root), NULL, LeftMaxNode->Data);
		}
	}

	return Removed;
}