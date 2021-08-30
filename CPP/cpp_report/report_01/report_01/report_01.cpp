#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int data[100], i = 0;

	while (1)
	{
		cin >> data[i];
		if (data[i] == -1)
		{
			break;
		}
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (data[j] > data[k])
			{
				swap(data[j], data[k]);
			}
		}
	}

	for (int j = 0; j < i; j++)
	{
		cout << data[j] << " ";
	}

	return 0;
}