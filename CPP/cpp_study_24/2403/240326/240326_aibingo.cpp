#include <iostream>
#include <time.h>

using namespace std;


int table[25] = {}, Aitable[25] = {};
int bingocount = 0, Aibingocount = 0;
int Aibingocheckarray[26] = {};
int num, Ainum;

void init_table()
{
	srand(unsigned int(time(0)));

	// player table 초기화
	for (int i = 0; i < 25; i++)
		table[i] = i + 1;
	for (int i = 0; i < 25; i++)
	{
		int idx1 = rand() % 25, idx2 = rand() % 25;
		int temp = table[idx1];
		table[idx1] = table[idx2];
		table[idx2] = temp;
	}
	// AI table 초기화
	for (int i = 0; i < 25; i++)
		Aitable[i] = i + 1;
	for (int i = 0; i < 25; i++)
	{
		int idx1 = rand() % 25, idx2 = rand() % 25;
		int temp = Aitable[idx1];
		Aitable[idx1] = Aitable[idx2];
		Aitable[idx2] = temp;
	}
}

void show_bingotable()
{
	cout << "빙고게임" << endl;
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
	cout << "현재 " << bingocount << "만큼의 빙고가 있습니다." << endl;
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
	cout << "현재 " << Aibingocount << "만큼의 빙고가 있습니다." << endl;
}

void check_bingo()
{
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
		cout << "동시에 맞췄습니다! 무승부!" << endl;
	}
	else if (bingocount >= 5) {
		cout << "플레이어가 이겼습니다! 플레이어 승!" << endl;
	}
	else if (Aibingocount >= 5) {
		cout << "Ai가 이겼습니다! Ai 승!" << endl;
	}
}

void update_bingo()
{
	if (num == 0)
	{
		cout << "게임을 종료합니다." << endl;
	}
	for (int i = 0; i < 25; i++) {
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
}

void calc_easy()
{
	while (1) {
		Ainum = rand() % 25 + 1;
		if (Aibingocheckarray[Ainum] = 1) {
			Aibingocheckarray[num] = 0;
			break;
		}
	}
}

void calc_hard()
{
	int count_xline[5] = {}, count_yline[5] = {}, count_cline[2] = {};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Aitable[i * 5 + j] == '*')
				count_xline[j]++;
			if (Aitable[j * 5 + i] == '*')
				count_yline[i]++;
		}
		if (table[i * 5 + i] == '*')
			count_cline[0]++;
		if (table[i * 5 + (5 - i)] == '*')
			count_cline[1]++;
	}
}

void input_Ai_num(int a)
{
	// Ai input number
	// easy모드는 *를 제외한 값들을 찾아낸다
	if (a == 1) {
		calc_easy();
	}
	else if (a == 2) // hard모드는 빙고를 최소 입력으로 맞출수 있는 값을 찾아낸다
	{
		calc_hard();
	}

	cout << "Ai가 입력한 숫자는 " << Ainum << "입니다" << endl;
	
}

int main()
{
	int diff = 0;
	init_table();


	cout << "난이도를 입력하세요" << endl << "1.easy" << endl << "2.hard" << endl;
	cin >> diff;
	system("cls");
	while (1)
	{
		show_bingotable();
		input_Ai_num(diff);
		cout << "숫자를 입력해주세요";
		cin >> num;
		check_bingo();
		update_bingo();

		system("cls");
	}
	return 0;
}