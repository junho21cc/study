#include <iostream>
#include "240418_vector.h"

using namespace std;

int main()
{
	CVector<int> vecInt;

	vecInt.reserve(100);

	for (int i = 0; i < 100; i++)
	{
		vecInt.push_back(i + 1);
	}

	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt[i] << endl;
	}


	return 0;
}