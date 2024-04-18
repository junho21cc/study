#include <iostream>
#include "240418_stack.h"

using namespace std;

int main()
{
	CStack<int> stackInt;

	for (int i = 0; i < 100; i++)
	{
		stackInt.push(i + 1);
	}

	while (!stackInt.empty())
	{
		cout << stackInt.pop() << endl;
	}
	return 0;
}