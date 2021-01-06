#pragma once

typedef struct tagBTNode
{
	int Data;
	struct tagBTNode* left;
	struct tagBTNode* right;
}BTNode;

BTNode* BT_CreateNode(int Data);
void BT_Insert(BTNode** root, int Data);
void BT_InOrderSearch(BTNode* root);
