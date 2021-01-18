#pragma once
#include <stdbool.h>

#define MAX_NODE (10)

typedef enum { DIRECTED = 0, UNDIRECTED = 1} GraphType;

typedef struct tagGraph
{
	GraphType node;
	bool adjMatrix[MAX_NODE][MAX_NODE];
}Graph;

void create(Graph* g, GraphType node);
void insertEdge(Graph* g, int from, int to);
void deletEdge(Graph* g, int from, int to);
void print(const Graph* g);