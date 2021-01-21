#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Graph_Matrix.h"

typedef struct tagQueue
{
	int queue[MAX_NODE];
	int front, rear, size;
} Queue;

void init(Queue* q);
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enQueue(Queue* q, int data);
int deQueue(Queue* q);
