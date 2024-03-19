#include <iostream>

using namespace std;

int main()
{
	/*
	do while 문 : 반복문의 한 종류
	형태 : do {} while(조건식) 의 형태로 구성
	while문은 처음 진입부터 조건문을 체크하지만 do while 문은 한번 무조건 동작 하고 나서
	조건식을 체크해 true 일 경우에만 동작된다
	*/
	int iNumber = 0; 
	
	do
	{
		cout << iNumber << endl;
	} while (iNumber > 0);

	/*
	배열 : 여러개의 변수를 한번에 생성해 줄 수 있는 기능
	형태 : 변수타입 배열명[개수] 의 형태로 선언할 수 있다
	배열의 특징 : 배열은 연속된 메모리블럭에 공간이 할당된다
	배열은 인덱스를 사용해서 원하는 부분에 접근하여 값으 지정할 수 있다
	인덱스는ㄴ 0부터 개수-1개 까지이다.즉 10이라면 0~9까지의 인덱스를 갖게 된다

	배열 뿐만 아니라 일반 변수들도 선언을 하고 값을 초기화 시키지 않은 경우 쓰레기 값이 들어가게 된다
	
	배열 전체를 0으로 초기화 시키고 싶다면
	int iArray[10] = {}이런 형식으로 하면 된다
	

	배열 개수를 2개 지정하면 이차원 배열이되고, 3개 지정하면 3차원 배율이 된다.


	*/

	int iArray[10];
	
	for (int i = 0; i < 10; i++)
	{
		iArray[i] = i;
		cout << iArray[i] << endl;
	}
	
	int iArray2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << iArray2[i][j] << " ";
		}
		cout << endl;
	}

	system("cls");

	srand((unsigned int)time(0));

	// 로또 프로그램
	int Lotto[45] = {};

	for (int i = 0; i < 45; i++)
	{
		Lotto[i] = i + 1;
	}
	// 섞는다
	int Temp, Idx1, Idx2;

	for (int i = 0; i < 100; i++)
	{
		Idx1 = rand() % 45;
		Idx2 = rand() % 45;

		Temp = Lotto[Idx1];
		Lotto[Idx1] = Lotto[Idx2];
		Lotto[Idx2] = Temp;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << Lotto[i] << endl;
	}

	return 0;
}