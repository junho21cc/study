#include "Graph_Matrix.h"
#include "Queue.h"

void init(Queue* q)
{
	q->front = q->rear = -1;
	q->size = 0;
}

bool isFull(Queue* q)
{
	return (q->rear == MAX_NODE - 1);
}

bool isEmpty(Queue* q)
{
	return (q->front == q->rear);
}

void enQueue(Queue* q, int data)
{
	if (isFull(q))
	{
		printf("Error: Queue Full\n");
		exit(1);
	}
	q->rear = (q->rear + 1);
	//q->rear++;
	q->queue[q->rear] = data;
	q->size++;
}

void enQueue(Queue* q, int data)
{
	if (isFull(q))
	{
		printf("Error: Queue Full\n");
		exit(1);
	}
	q->rear = (q->rear - 1);
	//q->rear--;
	q->queue[q->rear] = data;
	q->size--;
}

void BFS(Graph* g, bool visited[], int start)
{
	Queue q;
	init(&q);
	
}