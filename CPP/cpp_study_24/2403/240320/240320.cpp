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

		cout << "[" << count << "ȸ�� ���ھ߱�]" << endl;

		while (true)

		{

			cout << "1���� 9������ ���ڸ� �Է��ϼ��� : ";

			cin >> userBall[0] >> userBall[1] >> userBall[2];

			if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9)

			{

				cout << "���� ���� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�." << endl;

				continue;

			}

			else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2])

			{

				cout << "�ߺ��� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�." << endl;

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

			cout << "[���]��Ʈ����ũ : " << strike << ", �� : " << ball << endl << endl;

		else

			cout << "[���] �ƿ�!!!" << endl << endl;

		if (strike == 3)

		{

			cout << "***** �¸��߽��ϴ�. *****" << endl << endl;

			break;

		}

		else if (count == 9)

		{

			cout << "***** �й��߽��ϴ�.. ���� : ";

			cout << computerBall[0] << computerBall[1] << computerBall[2] << " *****" << endl << endl;

			break;

		}

		count++;

	}

	return 0;

}