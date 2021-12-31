#include <iostream>
#include <time.h>

#define PUZZLE_WIDTH_SIZE 5
#define PUZZLE_HEIGHT_SIZE 5


using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int PUZZLE_SIZE = PUZZLE_HEIGHT_SIZE * PUZZLE_WIDTH_SIZE;

	int number[PUZZLE_HEIGHT_SIZE * PUZZLE_WIDTH_SIZE];
	for (int i = 0; i < PUZZLE_SIZE - 1; i++)
	{
		number[i] = i + 1;
	}

	number[PUZZLE_SIZE - 1] = 9999;

	for (int i = 0; i < PUZZLE_SIZE * 4; i++)
	{
		int index1 = rand() % 24;
		int index2 = rand() % 24;
		int temp;

		temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}

	for (int i = 0; i < PUZZLE_HEIGHT_SIZE; i++)
	{
		for(int j = 0; j < PUZZLE_WIDTH_SIZE; i++)
			cout << number[j + i * PUZZLE_WIDTH_SIZE] << endl;
	}

	return 0;
}