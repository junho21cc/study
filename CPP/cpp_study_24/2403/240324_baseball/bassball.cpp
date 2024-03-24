#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));

	int basenum[3] = {};
	int playnum[3] = {};
	int bcount = 0, scount = 0;

	cout << "숫자야구게임을 시작합니다. 숫자는 서로다른 세개의 숫자입니다." << endl;

	do
	{
		for (int i = 0; i < 3; i++)
			basenum[i] = rand() % 10;

		if (basenum[0] == basenum[1] || basenum[1] == basenum[2] || basenum[0] == basenum[2])
			continue;
		else
			break;

	} while (1);
	
	
	while(1)
	{
		bcount = 0;
		scount = 0;

		cout << "맞추려고하는 숫자를 띄어쓰기로 구분해 입력해주세요." << endl;

		for (int i = 0; i < 3; i++)
			cin >> playnum[i];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (basenum[i] == playnum[j])
				{
					if (i == j)
						scount++;
					else
						bcount++;
				}
			}
		}

		if (scount == 3)
		{
			cout << "끝났습니다" << endl;
			break;
		}
		cout << scount << "s " << bcount << "b " << endl;
	}

	return 0;
}