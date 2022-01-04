#include <iostream>


#define BINGO_WIDTH 5
#define BINGO_HEIGHT 5
#define BINGO_SIZE BINGO_WIDTH * BINGO_HEIGHT

using namespace std;

void init_bingo_board(int bingo[BINGO_SIZE])
{
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bingo[i] = i + 1;
	}
}

void move_board(int number[BINGO_SIZE], int index1, int index2)
{
	int temp;

	temp = number[index1];
	number[index1] = number[index2];
	number[index2] = temp;
}

void mix_board(int number[BINGO_SIZE])
{
	for (int i = 0; i < BINGO_HEIGHT * BINGO_WIDTH * 4; i++)
	{
		int index1 = rand() % (BINGO_SIZE - 1);
		int index2 = rand() % (BINGO_SIZE - 1);

		move_board(number, index1, index2);
	}
}

void print_bingo(int bingo[BINGO_SIZE])
{
	for (int i = 0; i < BINGO_HEIGHT; i++)
	{
		for (int j = 0; j < BINGO_WIDTH; j++)
		{
			cout << bingo[j + i * BINGO_WIDTH] << "\t";
		}
		cout << endl;
	}
}

void check_board(int bingo[BINGO_SIZE], int number)
{
	for (int i = 0; i < BINGO_HEIGHT; i++)
	{
		for (int j = 0; j < BINGO_WIDTH; j++)
		{
			if (bingo[j + i * BINGO_WIDTH] == number)
			{
				bingo[j + i * BINGO_WIDTH] = 0;
				return;
			}
		}
	}
}

int count_bingo(int bingo[BINGO_SIZE])
{
	int length_count = 0, width_count = 0, diagonal_count = 0, O_count = 0;

	// width_count
	for (int i = 0; i < BINGO_WIDTH; i++)
	{
		O_count = 0;
		for (int j = 0; j < BINGO_HEIGHT; j++)
		{
			if (bingo[i + j * BINGO_WIDTH] == 0)
			{
				O_count++;
			}
		}
		if (O_count == BINGO_WIDTH)
		{
			length_count++;
		}
	}

	O_count = 0;
	// length_count
	for (int i = 0; i < BINGO_HEIGHT; i++)
	{
		O_count = 0;
		for (int j = 0; j < BINGO_WIDTH; j++)
		{
			if (bingo[j + i * BINGO_WIDTH] == 0)
			{
				O_count++;
			}
		}
		if (O_count == BINGO_HEIGHT)
		{
			width_count++;
		}
	}

	O_count = 0;
	// diagonal_count
	for (int i = 0; i < BINGO_WIDTH; i++)
	{
		if (bingo[i * (BINGO_WIDTH + 1)] == 0)
		{
			O_count++;
		}
	}

	if (O_count == BINGO_WIDTH)
	{
		diagonal_count++;
	}

	O_count = 0;
	for (int i = 0; i < BINGO_WIDTH; i++)
	{
		if (bingo[i * (BINGO_WIDTH - 1) + BINGO_WIDTH - 1] == 0)
		{
			O_count++;
		}
	}

	if (O_count == BINGO_WIDTH)
	{
		diagonal_count++;
	}

	return length_count + width_count + diagonal_count;
}



int main()
{
	int bingo_board[BINGO_SIZE], number, bingo_count;

	init_bingo_board(bingo_board);
	mix_board(bingo_board);

	do
	{
		print_bingo(bingo_board);

		cout << "숫자를 입력하세요: ";
		cin >> number;

		check_board(bingo_board, number);
		bingo_count = count_bingo(bingo_board);

	} while (bingo_count < 3);

	cout << "축하합니다! 빙고가 3개가 되었습니다!";


	return 0;
}