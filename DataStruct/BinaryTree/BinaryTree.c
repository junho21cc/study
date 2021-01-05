#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTNode* BT_CreateNode(int Data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	NewNode->Data = Data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

void BT_InOrderSearch(BTNode* root)
{
	if (root) {
		BT_InOrderSearch(root->left);
		printf("%d ", root->Data);
		BT_InOrderSearch(root->right);
	}
}