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


void SetNumber(int* pArray)
{
	for (int i = 0; i < 25; i++)
		pArray[i] = i + 1;
}

void SuffleNumber(int* pArray)
{
	srand(unsigned int(time(0)));
	for (int i = 0; i < 25; i++)
	{
		int idx1 = rand() % 25, idx2 = rand() % 25;
		int temp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = temp;
	}
}

void Printtable(int* pArray)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (pArray[i * 5 + j] == '*')
				cout << char(pArray[i * 5 + j]) << "\t";
			else
				cout << pArray[i * 5 + j] << "\t";
		}
		cout << endl;
	}
}

int CheckL(int* table)
{
	int num;
	for (int i = 0; i < 5; i++)
	{
		int line = 0;
		for (int j = 0; j < 5; j++)
		{
			if (table[i * 5 + j] == '*')
				line++;
		}
		if (line == 5)
			num++;
	}
	return num;
}

int CheckH(int* table)
{
	int num;
	for (int i = 0; i < 5; i++)
	{
		int line = 0;
		for (int j = 0; j < 5; j++)
		{
			if (table[j * 5 + i] == '*')
				line++;
		}
		if (line == 5)
			num++;
	}
	return num;
}

int CheckC1(int* table)
{
	int num, line = 0;
	for (int i = 0; i < 5; i++)
	{
		if (table[i * 5 + i] == '*')
			line++;
	}
	if (line == 5)
		num++;
	return num;
}

int CheckC2(int* table)
{
	int num, line = 0;
	for (int i = 0; i < 5; i++)
	{
		if (table[i * 5 + (5 - i)] == '*')
			line++;
	}
	if (line == 5)
		num++;
	return num;
}

void Checktable(int* table, int* bc)
{
	bc += CheckL(table);
	bc += CheckH(table);
	bc += CheckC1(table);
	bc += CheckC2(table);
}



int main()
{
	int table[25] = {};
	int bingocount = 0;

	SetNumber(table);
	SuffleNumber(table);

	while (1)
	{
		int num;

		system("cls");

		cout << "빙고게임" << endl;
		cout << "현재 " << bingocount << "만큼의 빙고가 있습니다." << endl;

		Printtable(table);

		bingocount = 0;
		Checktable(table, &bingocount);

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
}