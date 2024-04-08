#include <iostream>
#include <conio.h>

using namespace std;


/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 폭탄 이펙트
*/

struct _tagPoint
{
	int x;
	int y;
};

typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;


void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;

	strcpy_s(Maze[0],	 "21100000000000000000");
	strcpy_s(Maze[1],	 "00100000011111111000");
	strcpy_s(Maze[2],	 "00111111110000000100");
	strcpy_s(Maze[3],	 "00100000000000000100");
	strcpy_s(Maze[4],	 "00100000000011111100");
	strcpy_s(Maze[5],	 "00100000000010000100");
	strcpy_s(Maze[6],	 "00100011111010000100");
	strcpy_s(Maze[7],	 "00100000000011110000");
	strcpy_s(Maze[8],	 "00111110000010000000");
	strcpy_s(Maze[9],	 "00000010000000000000");
	strcpy_s(Maze[10],	 "00011111111000000000");
	strcpy_s(Maze[11],	 "00000000001000000000");
	strcpy_s(Maze[12],	 "00011111111000000000");
	strcpy_s(Maze[13],	 "00010000001000000000");
	strcpy_s(Maze[14],	 "00010000001000000000");
	strcpy_s(Maze[15],	 "00010000001111111100");
	strcpy_s(Maze[16],	 "00010001000000100100");
	strcpy_s(Maze[17],	 "00010001000000100100");
	strcpy_s(Maze[18],	 "00011111000000000100");
	strcpy_s(Maze[19],	 "00000100011111111113");
}

void Output(char Maze[21][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (Maze[i][j] == '4')
				cout << "♡";
			else if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "@";
			else if (Maze[i][j] == '0')
				cout << "■";
			else if (Maze[i][j] == '1')
				cout << "□";
			else if (Maze[i][j] == '2')
				cout << "★";
			else if (Maze[i][j] == '3')
				cout << "◎";
		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0'
			&& Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
		{
			pPlayerPos->y--;
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 20)
	{
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0'
			&& Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
		{
			pPlayerPos->y++;
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 >= 0)
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0'
			&& Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
		{
			pPlayerPos->x--;
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20)
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0'
			&& Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
		{
			pPlayerPos->x++;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlyaerPos, char cInput)
{
	switch (cInput)
	{
	case'w':
	case'W':
		MoveUp(Maze, pPlyaerPos);
		break;
	case's':
	case'S':
		MoveDown(Maze, pPlyaerPos);
		break;
	case'a':
	case'A':
		MoveLeft(Maze, pPlyaerPos);
		break;
	case'd':
	case'D':
		MoveRight(Maze, pPlyaerPos);
		break;
	}
}

// 포인터 번수를 const로 생성하면 가르키는 대상의 값을 변경할 수 없다
void CreateBomb(char Maze[21][21], const PPOINT pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	for (int i = 0; i < *pBombCount; i++)
	{
		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = *pPlayer;
	(*pBombCount)++;

	Maze[pPlayer->y][pPlayer->x] = '4';
}

void Fire(char Maze[21][21], PPOINT pPlayer, PPOINT pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; i++)
	{
		if (pBombArr[i].y - 1 >= 0)
		{
			if (Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';
		}
		if (pBombArr[i].y + 1 >= 0)
		{
			if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';
		}
		if (pBombArr[i].x - 1 >= 0)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';
		}
		if (pBombArr[i].x + 1 >= 0)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';
		}
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
	}
	*pBombCount = 0;
}

int main()
{
	// 20 20 미로를 만든다
	char strMaze[21][21] = {};

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	int iBombCount = 0;

	POINT tBombPos[5];

	// 미로를 설정한다
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (1)
	{
		system("cls");
		// 미로를 출력한다
		Output(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << "도착했습니다" << endl;
			break;
		}

		cout << "t : 폭탄설치, u : 폭탄 터트리기" << endl;
		cout << "w : 위, s : 아래, a : 왼쪽, d : 오른쪽, q : 종료";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;
		else if (cInput == 't' || cInput == 'T')
		{
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
			
		}
		else if (cInput == 'u' || cInput == 'U')
		{
			Fire(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}
		else
			MovePlayer(strMaze, &tPlayerPos, cInput);

	}

	return 0;
}