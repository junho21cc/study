#pragma once

typedef struct tagBTNode
{
	int Data;
	struct tagBTNode* left;
	struct tagBTNode* right;
}BTNode;

BTNode* BT_CreateNode(int Data);
void BT_InsertNode(BTNode** root, int Data);
void BT_InOrderSearch(BTNode* root);
// void BT_InsertNode(BTNode** root, int InsertData);
void BT_SearchNode(BTNode* root, int SearchData);


