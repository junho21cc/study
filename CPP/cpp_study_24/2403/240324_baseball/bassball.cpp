#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));

	int basenum[3] = {};
	int playnum[3] = {};
	int bcount = 0, scount = 0;

	cout << "���ھ߱������� �����մϴ�. ���ڴ� ���δٸ� ������ �����Դϴ�." << endl;

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

		cout << "���߷����ϴ� ���ڸ� ����� ������ �Է����ּ���." << endl;

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
			cout << "�������ϴ�" << endl;
			break;
		}
		cout << scount << "s " << bcount << "b " << endl;
	}

	return 0;
}