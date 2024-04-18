#include <iostream>
#include "240418_Queue.h"

using namespace std;

int main()
{
	CQueue<int> queueInt;

	for (int i = 0; i < 100; i++)
	{
		queueInt.push(i + 1);
	}

	while (!queueInt.empty())
	{
		cout << queueInt.pop() << endl;
	}


	CCircleQueue<int, 10> queue;
	
	for (int i = 0; i < 10; i++)
	{
		queue.push(i + 1);
	}

	cout << "3개 pop" << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << queue.pop() << endl;
	}

	cout << "4개 push" << endl;
	for (int i = 0; i < 4; i++)
	{
		queue.push(i + 1);
	}

	cout << "전부 pop" << endl;
	while (!queue.empty())
	{
		cout << queue.pop() << endl;
	}

	return 0;
}