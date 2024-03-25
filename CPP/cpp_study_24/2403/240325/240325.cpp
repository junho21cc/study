#include <iostream>
#include <time.h>

using namespace std;


/*
빙고게임
1~25까지 숫자, 5x5로 출력
플레이어는 1~25사이의 숫자를 입력한다. 0을 입력하면 게임을 종료한다

숫자목록중 입력받은 숫자를 찾아 *로 만든다

종료조건
*가 가로, 세로 대각선으로 총 5줄 이상일 경우 
*/
int main()
{
	srand(unsigned int(time(0)));

	int table[25] = {};
	int bingocount = 0;

	for (int i = 0; i < 25; i++)
		table[i] = i + 1;
	for (int i = 0; i < 25; i++)
	{
		int idx1 = rand() % 25, idx2 = rand() % 25;
		int temp = table[idx1];
		table[idx1] = table[idx2];
		table[idx2] = temp;
	}

	while (1)
	{
		int num;

		system("cls");

		cout << "빙고게임" << endl;
		cout << "현재 " << bingocount << "만큼의 빙고가 있습니다." << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (table[i * 5 + j] == '*')
					cout << char(table[i * 5 + j]) << "\t";
				else
					cout << table[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		int xline = 0, yline = 0, cline1 = 0, cline2 = 0;

		bingocount = 0;
		// x, yline check
		for (int i = 0; i < 5; i++)
		{
			yline = 0;
			xline = 0;
			for (int j = 0; j < 5; j++)
			{
				if (table[i * 5 + j] == '*')
					xline++;
				if (table[j * 5 + i] == '*')
					yline++;
			}
			if (xline == 5)
				bingocount++;
			if (yline == 5)
				bingocount++;
			if (table[i * 5 + i] == '*')
				cline1++;
			if (table[i * 5 + (5 - i)] == '*')
				cline2++;
		}

		if (cline1 == 5)
			bingocount++;
		if (cline2 == 5)
			bingocount++;


		if (bingocount >= 5)
			break;



		cout << "숫자를 입력해주세요";
		cin >> num;
		if (num == 0)
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}

		for (int i = 0; i < 25; i++)
		{
			if (table[i] == num)
				table[i] = '*';
		}

		

		/*
				(x,y) => y*w + x
				(i,i) => i*w + i
				((5-i),i) => i*w + (5-i)

		*/
	}
	return 0;
}