#include "Graph_Matrix.h"
#include "Queue.h"


void Graph_BFS(Graph* g, bool visited[], int start)
{
	Queue q;
	init(&q);
	
	enQueue(&q, start);
	visited[start] = true;
	printf("%d ", start);

	while (!isEmpty(&q))
	{
		int from = deQueue(&q);

		for (int to = 0; to < MAX_NODE; to++)
		{
			if (g->adjMatrix[from][to] && !visited[to])
			{
				enQueue(&q, to);
				visited[to] = true;
				printf("%d ", to);
			}
		}
	}
}
