#include <stdio.h>
#include "Graph_Matrix.h"


void create(Graph* g, GraphType mode)
{
	g->mode = mode;

	for (int r = 0; r < MAX_NODE; r++)
	{
		for (int c = 0; c < MAX_NODE; c++)
		{
			g->adjMatrix[r][c] = false;
		}
	}
}

void insertEdge(Graph* g, int from, int to)
{
	g->adjMatrix[from][to] = true;

	if (g->mode == UNDIRECTED)
	{
		g->adjMatrix[to][from] = true;
	}
}

void deletEdge(Graph* g, int from, int to)
{
	g->adjMatrix[from][to] = false;

	if (g->mode == UNDIRECTED)
	{
		g->adjMatrix[from][to] = false;
	}
}

void print(const Graph* g)
{
	for (int r = 0; r < MAX_NODE; r++)
	{
		for (int c = 0; c < MAX_NODE; c++)
		{
			printf("%d ", g->adjMatrix[r][c]);
		}
		printf("\n");
	}
}

void graphvizDriver(const Graph* g)
{
	if (g->mode == DIRECTED)
	{
		printf("di");
	}
	printf("graph G {\n");
	for (int r = 0; r < MAX_NODE; r++)
	{
		for (int c = 0; c < MAX_NODE; c++)
		{
			if (g->adjMatrix[r][c] == true)
			{
				printf("	\"%d\" -", r);
				if (g->mode == DIRECTED)
				{
					printf("> \"%d\"\n", c);
				}
				else
				{
					printf("- \"%d\"\n", c);
				}
			}
		}
	}
	printf("}\n");
}

