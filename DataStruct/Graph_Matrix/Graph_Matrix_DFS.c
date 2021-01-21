#include <stdio.h>
#include "Graph_Matrix.h"

void Graph_DFS(const Graph* g, bool visited[], int start)
{
	visited[start] = true;
	printf("%d ", start);
	for (int v = 0; v < MAX_NODE; v++)
	{
		if (g->adjMatrix[start][v] && !visited[v])
		{
			Graph_DFS(g, visited, v);
		}
	}
}
