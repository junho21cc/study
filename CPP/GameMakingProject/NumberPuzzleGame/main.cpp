#include <iostream>
#include <time.h>
#include <conio.h>

#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3

#define BOARD_SIZE BOARD_WIDTH * BOARD_HEIGHT

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

using namespace std;

void init_board(int number[BOARD_SIZE])
{
	for (int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH - 1; i++)
	{
		number[i] = i + 1;
	}

	number[BOARD_SIZE - 1] = 9999;
}

void move_board(int number[BOARD_SIZE], int index1, int index2)
{
	int temp;

	temp = number[index1];
	number[index1] = number[index2];
	number[index2] = temp;
}

void mix_board(int number[BOARD_SIZE])
{
	for (int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH * 4; i++)
	{
		int index1 = rand() % (BOARD_SIZE - 1);
		int index2 = rand() % (BOARD_SIZE - 1);

		move_board(number, index1, index2);
	}
}

void print_board(int number[BOARD_SIZE])
{
	system("cls");
	// 그림 그리는 거
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			if (number[j + i * BOARD_HEIGHT] == 9999)
			{
				cout << "*\t";
			}
			else
			{
				cout << number[j + i * BOARD_HEIGHT] << "\t";
			}
		}
		cout << endl;
	}
}

int get_key_input()
{
	int ip = _getch();
	return ip;
}

int check_worong_count(int number[])
{
	int is_wrong_count = 0;
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			if (number[j + i * BOARD_HEIGHT] != j + i * BOARD_HEIGHT + 1)
			{
				is_wrong_count++;
			}
		}
		cout << endl;
	}
	return is_wrong_count;
}

int wayout(char c, int position)
{
	switch (c)
	{
	case LEFT:
		if (position % BOARD_WIDTH == 0)
			break;
		position--;
		break;
	case RIGHT:
		if ((position + 1) % BOARD_WIDTH == 0)
			break;
		position++;
		break;
	case UP:
		if (position - BOARD_WIDTH < 0)
			break;
		position -= BOARD_WIDTH;
		break;
	case DOWN:
		if (position + BOARD_WIDTH > BOARD_SIZE - 1)
			break;
		position += BOARD_WIDTH;
		break;
	}
	
	return position;
}

int main()
{
	// Initialization
	srand((unsigned int)time(0));
	int Now_Position  = BOARD_SIZE - 1;
	int Before_Position  = Now_Position ;
	int is_wrong_count = 0;
	int number[BOARD_SIZE];

	init_board(number);
	mix_board(number);

	// 화살표 입력받는거
	do
	{
		print_board(number);

		if (_kbhit()) 
		{       
			int c = get_key_input();

			Before_Position = Now_Position;

			Now_Position = wayout(c, Now_Position);

			move_board(number, Before_Position, Now_Position);
		}

		is_wrong_count = check_worong_count(number);		

	} while (is_wrong_count - 1);

	cout << "정답입니다!" << endl;

	return 0;
}