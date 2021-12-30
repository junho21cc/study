#include <iostream>
#include <time.h>

#define LOTTO_BALL_COUNT 45
#define PICK_BALL_COUNT 6

using namespace std;


int main()
{
	srand((unsigned int)time(0));

	int num[LOTTO_BALL_COUNT + 1] = { 0, };
	int count = 0;

	do
	{
		int check = rand() % LOTTO_BALL_COUNT + 1;

		for (int i = 1; i <= LOTTO_BALL_COUNT; i++)
		{
			if (i == check)
			{
				if (num[i] > 0)
					continue;
				num[i]++;
				count++;

				cout << check << endl;
				break;
			}
		}
	} while (count < PICK_BALL_COUNT);

	return 0;
}

