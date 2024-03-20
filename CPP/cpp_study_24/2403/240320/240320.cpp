#include <iostream>  

#include <ctime> 

using namespace std;

int main()

{

	int computerBall[3];

	int i, j;

	int userBall[3];

	int count = 1;

	int strike;

	int ball;

	srand(static_cast<unsigned int>(time(NULL)));

	for (i = 0; i < 3; i++)

	{

		computerBall[i] = (rand() % 9) + 1;

		for (j = 0; j < i; j++)

			if (computerBall[i] == computerBall[j] && i != j)

				i--;

	}

	while (true)

	{

		cout << "[" << count << "회차 숫자야구]" << endl;

		while (true)

		{

			cout << "1부터 9까지의 숫자를 입력하세요 : ";

			cin >> userBall[0] >> userBall[1] >> userBall[2];

			if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9)

			{

				cout << "범위 외의 숫자를 입력하시면 안됩니다." << endl;

				continue;

			}

			else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2])

			{

				cout << "중복된 숫자를 입력하시면 안됩니다." << endl;

				continue;

			}

			break;

		}

		strike = 0;

		ball = 0;

		for (i = 0; i < 3; i++)

			for (j = 0; j < 3; j++)

				if (computerBall[i] == userBall[j])

					if (i == j) strike++;

					else ball++;

		if (strike || ball)

			cout << "[결과]스트라이크 : " << strike << ", 볼 : " << ball << endl << endl;

		else

			cout << "[결과] 아웃!!!" << endl << endl;

		if (strike == 3)

		{

			cout << "***** 승리했습니다. *****" << endl << endl;

			break;

		}

		else if (count == 9)

		{

			cout << "***** 패배했습니다.. 정답 : ";

			cout << computerBall[0] << computerBall[1] << computerBall[2] << " *****" << endl << endl;

			break;

		}

		count++;

	}

	return 0;

}