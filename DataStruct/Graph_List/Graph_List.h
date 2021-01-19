#pragma once

typedef enum { UNDIRECTED = 0, DIRECTED = 1 } GraphType;

typedef struct tagNode
{
	int destination;
	struct tagNode* next;
} Node;

typedef struct tagHeadNode 
{
	Node* head;
} HeadNode;

typedef struct tagGraph
{
	int nodeSize;
	GraphType mode;
	HeadNode* list;
} Graph;

void Graph_vizDriver(Graph* g);
void Graph_vizPrint(Graph* g);

Graph* Graph_Create(int node, GraphType mode);
void Graph_Destroy(Graph* g);

void Graph_InsertEdge(Graph* g, int from, int to);
void Graph_DeleteEdge(Graph* g, int from, int to);

Node* NewNode(int destination);

void print(Graph* g);
