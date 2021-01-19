#include <stdio.h>
#include <stdlib.h>
#include "Graph_List.h"

void Graph_vizPrint(Graph* g)
{
	char* mode;

	if (g->mode == DIRECTED)
	{
		mode = "->";
	}
	else
	{
		mode = "--";
	}

	for (int v = 0; v < g->nodeSize; v++)
	{
		Node* n = g->list[v].head;
		while (n)
		{
			printf("\t\"%d\" %s \"%d\";\n", v, mode, n->destination);
			n = n->next;
		}
	}
}

void Graph_vizDriver(Graph* g)
{
	if (g->mode == DIRECTED)
	{
		printf("dig");
	}
	printf("graph G {\n");
	Graph_vizPrint(g);
	printf("}\n");
}

Graph* Graph_Create(int nodeSize, GraphType mode)
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->nodeSize = nodeSize;
	g->mode = mode;
	g->list = (Node**)malloc(sizeof(Node*));

	for (int i = 0; i < nodeSize; i++)
	{
		g->list[i].head = NULL;
	}
	return g;
}

void Graph_Destroy(Graph* g)
{
	for (int v = 0; v < g->nodeSize; v++)
	{
		free(g->list[v].head);
	}
	g->nodeSize = 0;
	free(g->list);
	// free(g->list); 만 해줘도 될것같다...?
}

void Graph_InsertEdge(Graph* g, int from, int to)
{
	Node* n = NewNode(to);

	n->next = g->list[from].head;
	g->list[from].head = n;

	if (g->mode == UNDIRECTED)
	{
		n = NewNode(from);
		n->next = g->list[to].head;
		g->list[to].head = n;
	}
}

Node* NewNode(int destination)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->destination = destination;
	n->next = NULL;

	return n;
}

void Greph_DeleteEdge(Graph* g, int from, int to)
{

}

void print(Graph* g)
{
	for (int v = 0; v < g->nodeSize; v++)
	{
		Node* n = g->list[v].head;
		printf("vertex %d: ", v);
		while (n)
		{
			printf("-> %d", n->destination);
			n = n->next;
		}
		printf("\n");
	}
}