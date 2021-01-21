#include <stdio.h>
#include "Graph_Matrix_DFS.h"
#include "Graph_Matrix_BFS.h"

int main()
{
	Graph g;
	create(&g, DIRECTED);

	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 0, 3);
	insertEdge(&g, 0, 4);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);

	print(&g);

	printf("sizeof(bool): %d\n", sizeof(bool));
	printf("sizeof(Graph): %d\n", sizeof(Graph));

	graphvizDriver(&g);

	create(&g, UNDIRECTED);

	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);

	print(&g);
	graphvizDriver(&g);

	bool visited_DFS[MAX_NODE];
	for (int v = 0; v < MAX_NODE; v++)
	{
		visited_DFS[v] = false;
	}
	printf("\n\nnrecusive DFS: ");
	Graph_DFS(&g, visited_DFS, 0);


	bool visited_BFS[MAX_NODE];
	for (int v = 0; v < MAX_NODE; v++)
	{
		visited_BFS[v] = false;
	}
	printf("\n\nBFS: ");
	Graph_BFS(&g, visited_BFS, 0);

	return 0;
}
