#include <stdio.h>
#include "BinaryTree.h"

int main()
{
	BTNode* root = NULL;
	/*
	root = BT_CreateNode(1);
	root->left = BT_CreateNode(2);
	root->right = BT_CreateNode(3);

	root->left->left = BT_CreateNode(4);
	root->left->right = BT_CreateNode(5);

	root->right->left = BT_CreateNode(6);
	root->right->right = BT_CreateNode(7);
	*/

	BT_InsertNode(&root, 6);
	BT_InsertNode(&root, 4);
	BT_InsertNode(&root, 1);
	BT_InsertNode(&root, 5);
	BT_InsertNode(&root, 3);
	BT_InsertNode(&root, 2);
	BT_InsertNode(&root, 10);
	BT_InsertNode(&root, 9);
	BT_InsertNode(&root, 11);

	BT_InOrderSearch(root);

	printf("\n\n");

	BTNode* Node;
	Node = BT_RemoveNode(&root, NULL, 4);
	void BT_DestroyNode(Node);

	BT_InOrderSearch(root);

	return 0;
}