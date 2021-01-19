#include <stdio.h>
#include "Graph_List.h"

int main()
{
	Graph* g;
	g = Graph_Create(5, UNDIRECTED);

	Graph_InsertEdge(g, 0, 1);
	Graph_InsertEdge(g, 0, 2);
	Graph_InsertEdge(g, 0, 3);
	Graph_InsertEdge(g, 0, 4);
	Graph_InsertEdge(g, 1, 3);
	Graph_InsertEdge(g, 2, 3);
	Graph_InsertEdge(g, 2, 4);
	Graph_InsertEdge(g, 3, 4);

	print(g);
	Graph_vizDriver(g);
	Graph_Destroy(g);

	Graph_InsertEdge(g, 0, 1);
	Graph_InsertEdge(g, 0, 2);
	Graph_InsertEdge(g, 0, 3);
	Graph_InsertEdge(g, 0, 4);
	Graph_InsertEdge(g, 1, 3);
	Graph_InsertEdge(g, 2, 3);
	Graph_InsertEdge(g, 2, 4);
	Graph_InsertEdge(g, 3, 4);

	print(g);
	Graph_vizDriver(g);
	Graph_Destroy(g);

}