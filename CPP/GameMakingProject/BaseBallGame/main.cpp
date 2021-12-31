#include <iostream>
#include <time.h>

#define BALL_COUNT 3

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int answer[3] = { rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1 };

	int question[3];


	for (int i = 0; i < BALL_COUNT; i++)
	{
		cout << answer[i] << "     ";
	}
	cout << endl;



	while(1)
	{
		int strike = 0, ball = 0;
		bool is_wrong = false;

		cout << "1~9사이의 숫자 중에 숫자 3개를 입력하세요.(종료: 0)";
		cin >> question[0] >> question[1] >> question[2];

		if (question[0] == 0|| question[1] == 0|| question[2] == 0)
			break;

		for (int i = 0; i < BALL_COUNT; i++)
		{
			if ((question[i] < 1) || (question[i] > 9))
			{
				cout << "잘못된 숫자를 입력하셨습니다." << endl;
				is_wrong = true;
			}
		}

		if (is_wrong)
		{
			continue;
		}

		for (int i = 0; i < BALL_COUNT; i++)
		{
			for (int j = 0; j < BALL_COUNT; j++)
			{
				if (answer[i] == question[j])
				{
					if (i == j)
					{
						strike++;
					}
					else 
					{
						ball++;

					}

					//
				}
			}
		}

		if (strike == 0 && ball == 0)
		{
			cout << "OUT!" << endl;
		}
		else if(strike == 3)
		{
			cout << "3개 다 맞췄습니다!";
			break;
		}
		else
		{
			cout << "strike: " << strike << endl << "ball: " << ball << endl;
		}
	};
	return 0;
}



do
{
	int condition = input_number();
	switch (condition) {
	case COND_END:
		//
		is_end = true;
		break;
	case COND_VALID:
		//
		break;
	default:
	case COND_INVALID:
		//
		break;
	}
} while(!is_end)