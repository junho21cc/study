#include <iostream>
#include <time.h>
#include <conio.h>

#define PUZZLE_WIDTH_SIZE 3
#define PUZZLE_HEIGHT_SIZE 3

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int PUZZLE_SIZE = PUZZLE_WIDTH_SIZE * PUZZLE_HEIGHT_SIZE;

	int Now_Position  = PUZZLE_SIZE - 1;

	int Before_Position  = Now_Position ;

	int is_wrong_count = 0;
	
	int number[PUZZLE_WIDTH_SIZE * PUZZLE_HEIGHT_SIZE];


	for (int i = 0; i < PUZZLE_SIZE - 1; i++)
	{
		number[i] = i + 1;
	}

	number[PUZZLE_WIDTH_SIZE * PUZZLE_HEIGHT_SIZE - 1] = 9999;
	
	for (int i = 0; i < PUZZLE_SIZE * 4; i++)
	{
		int index1 = rand() % (PUZZLE_SIZE - 1);
		int index2 = rand() % (PUZZLE_SIZE - 1);
		int temp;

		temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}
	

	// 화살표 입력받는거
	do
	{
		char c;

		if (_kbhit()) 
		{       
			c = _getch();    
			if (c == -32) 
			{  
				c = _getch();

				Before_Position = Now_Position;

				switch (c) 
				{
				case LEFT:
					if (Now_Position % PUZZLE_WIDTH_SIZE == 0)
						break;
					Now_Position --;
					break;
				case RIGHT:
					if ((Now_Position + 1) % PUZZLE_WIDTH_SIZE == 0)
						break;
					Now_Position ++;
					break;
				case UP:
					if (Now_Position - PUZZLE_WIDTH_SIZE < 0)
						break;
					Now_Position -= PUZZLE_WIDTH_SIZE;
					break;
				case DOWN:
					if (Now_Position + PUZZLE_WIDTH_SIZE > PUZZLE_SIZE - 1)
						break;
					Now_Position += PUZZLE_WIDTH_SIZE;
					break;
				}

				int temp = number[Before_Position];
				number[Before_Position] = number[Now_Position];
				number[Now_Position] = temp;
			}
		}

		system("cls");
		// 그림 그리는 거
		for (int i = 0; i < PUZZLE_HEIGHT_SIZE; i++)
		{
			for (int j = 0; j < PUZZLE_WIDTH_SIZE; j++)
			{
				if (number[j + i * PUZZLE_HEIGHT_SIZE] == 9999)
				{
					cout << "*\t";
				}
				else
				{
					cout << number[j + i * PUZZLE_HEIGHT_SIZE] << "\t";
				}
			}
			cout << endl;
		}

		is_wrong_count = 0;
		for (int i = 0; i < PUZZLE_HEIGHT_SIZE; i++)
		{
			for (int j = 0; j < PUZZLE_WIDTH_SIZE; j++)
			{
				if (number[j + i * PUZZLE_HEIGHT_SIZE] != j + i * PUZZLE_HEIGHT_SIZE + 1)
				{
					is_wrong_count++;
				}
			}
			cout << endl;
		}
		

	} while (is_wrong_count - 1);
	cout << "정답입니다!" << endl;

	return 0;
}