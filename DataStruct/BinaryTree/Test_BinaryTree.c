#include "BinaryTree.h"

int main(void)
{
	BTNode* root;

	root = BT_CreateNode(1);

	root->left = BT_CreateNode(2);
	root->right = BT_CreateNode(3);

	root->left->left = BT_CreateNode(4);
	root->left->right = BT_CreateNode(5);

	root->right->left = BT_CreateNode(6);
	root->right->right = BT_CreateNode(7);

	BT_InOrderSearch(root);
}