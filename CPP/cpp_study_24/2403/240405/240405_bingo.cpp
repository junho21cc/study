#include <iostream>
#include <time.h>

using namespace std;

/*
�������
1~25���� ����, 5x5�� ���
�÷��̾�� 1~25������ ���ڸ� �Է��Ѵ�. 0�� �Է��ϸ� ������ �����Ѵ�

���ڸ���� �Է¹��� ���ڸ� ã�� *�� �����

��������
*�� ����, ���� �밢������ �� 5�� �̻��� ���
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

		cout << "�������" << endl;
		cout << "���� " << bingocount << "��ŭ�� ���� �ֽ��ϴ�." << endl;

		Printtable(table);

		bingocount = 0;
		Checktable(table, &bingocount);

		if (bingocount >= 5)
			break;

		cout << "���ڸ� �Է����ּ���";
		cin >> num;
		if (num == 0)
		{
			cout << "������ �����մϴ�." << endl;
			break;
		}

		for (int i = 0; i < 25; i++)
		{
			if (table[i] == num)
				table[i] = '*';
		}
}