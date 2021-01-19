#include "Graph_Matrix.h"

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

	return 0;
}