#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(unsigned int(time(0)));

	int table[25] = {}, Aitable[25] = {};
	int bingocount = 0, Aibingocount = 0;
	int Aibingocheckarray[25] = {};

	// player table �ʱ�ȭ
	for (int i = 0; i < 25; i++)
		table[i] = i + 1;
	for (int i = 0; i < 25; i++)
	{
		int idx1 = rand() % 25, idx2 = rand() % 25;
		int temp = table[idx1];
		table[idx1] = table[idx2];
		table[idx2] = temp;
	}
	// AI table �ʱ�ȭ
	for (int i = 0; i < 25; i++)
		Aitable[i] = i + 1;
	for (int i = 0; i < 25; i++)
	{
		int idx1 = rand() % 25, idx2 = rand() % 25;
		int temp = Aitable[idx1];
		Aitable[idx1] = Aitable[idx2];
		Aitable[idx2] = temp;
	}

	for (int i = 0; i < 25; i++)
		Aibingocheckarray[i] = 1;

	while (1)
	{
		int num, Ainum;
		cout << "�������" << endl;
		cout << "-----------Player table-----------" << endl;
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
		cout << "���� " << bingocount << "��ŭ�� ���� �ֽ��ϴ�." << endl;
		cout << "-----------AI table-----------" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (Aitable[i * 5 + j] == '*')
					cout << char(Aitable[i * 5 + j]) << "\t";
				else
					cout << Aitable[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		cout << "���� " << Aibingocount << "��ŭ�� ���� �ֽ��ϴ�." << endl;
		int xline = 0, yline = 0, cline1 = 0, cline2 = 0;
		int Aixline = 0, Aiyline = 0, Aicline1 = 0, Aicline2 = 0;

		bingocount = 0;
		Aibingocount = 0;
		// x, yline check
		for (int i = 0; i < 5; i++)
		{
			yline = 0;
			xline = 0;
			Aiyline = 0;
			Aixline = 0;
			for (int j = 0; j < 5; j++)
			{
				// player x, y line bingo check
				if (table[i * 5 + j] == '*')
					xline++;
				if (table[j * 5 + i] == '*')
					yline++;
				// Ai x, y line bingo check
				if (Aitable[i * 5 + j] == '*')
					Aixline++;
				if (Aitable[j * 5 + i] == '*')
					Aiyline++;
			}
			// player bingo check
			if (xline == 5)
				bingocount++;
			if (yline == 5)
				bingocount++;
			if (table[i * 5 + i] == '*')
				cline1++;
			if (table[i * 5 + (5 - i)] == '*')
				cline2++;
			// Ai bingo check
			if (Aixline == 5)
				Aibingocount++;
			if (Aiyline == 5)
				Aibingocount++;
			if (Aitable[i * 5 + i] == '*')
				Aicline1++;
			if (table[i * 5 + (5 - i)] == '*')
				Aicline2++;
		}
		if (cline1 == 5)
			bingocount++;
		if (cline2 == 5)
			bingocount++;
		
		if (Aicline1 == 5)
			Aibingocount++;
		if (Aicline2 == 5)
			Aibingocount++;

		if (bingocount >= 5 && Aibingocount >= 5) {
			cout << "���ÿ� ������ϴ�! ���º�!" << endl;
			break;
		}
		else if (bingocount >= 5) {
			cout << "�÷��̾ �̰���ϴ�! �÷��̾� ��!" << endl;
			break;
		}
		else if(Aibingocount >= 5){
			cout << "Ai�� �̰���ϴ�! Ai ��!" << endl;
			break;
		}
		// Ai input number
		while (1)
		{
			Ainum = rand() % 25;
			if (Aibingocheckarray[Ainum + 1] = 1) {
				break;
			}
				
		}
		cout << "Ai�� �Է��� ���ڴ�" << Ainum + 1 << "�Դϴ�" << endl;

		cout << "���ڸ� �Է����ּ���";
		while (1)
		{
			cin >> num;
			if (num != Ainum + 1)
			{
				break;
			}
			else
			{
				cout << "�ٸ� ���ڸ� �Է����ּ���" << endl;
			}
		}
		Aibingocheckarray[num] = 0;
		if (num == 0)
		{
			cout << "������ �����մϴ�." << endl;
			break;
		}
		for (int i = 0; i < 25; i++){
			if (table[i] == num)
				table[i] = '*';
			if (Aitable[i] == num)
				Aitable[i] = '*';
		}
		for (int i = 0; i < 25; i++) {
			if (table[i] == Ainum + 1)
				table[i] = '*';
			if (Aitable[i] == Ainum + 1)
				Aitable[i] = '*';
		}
		system("cls");
	}
	return 0;
}