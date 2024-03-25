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

		cout << "�������" << endl;
		cout << "���� " << bingocount << "��ŭ�� ���� �ֽ��ϴ�." << endl;

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

		

		/*
				(x,y) => y*w + x
				(i,i) => i*w + i
				((5-i),i) => i*w + (5-i)

		*/
	}
	return 0;
}