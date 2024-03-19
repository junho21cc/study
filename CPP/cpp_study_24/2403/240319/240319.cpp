#include <iostream>
#include <time.h> // 시간에 관련된 함수가 포함되어있다

using namespace std;

/*
열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능이다
enum 열거체 명{}의 형태로 구성된다
열거체명을 이용하여 열거체 타입의 변수를 선언도 가능하다
즉, 열거체 자체가 사용자 정의 변수 타입이 될 수 도 있다.
열거체는 숫자에 이름을 붙여주는 기능이다.
*/

enum NUM
{
	NUM_0, // 아무것도 부여하지 않을경우 0부터 1씩 차례대로 값이 부여된다
	NUM_1,
	NUM_2,
	NUM_3,
};

#define NUM_4 4

int main()
{
	
	// if문을 사용하여 난수를 어떻게 발생시키느냐
	// 컴퓨터에서 항상 변하는것은 시간밖에 없다 → 시간을 이용한다
	// signed 양수음수 둘다 사용가능, unsigned 양수만 사용 가능
	srand((unsigned int)time(0)); // 형 변환, type casting을 한다 왜하냐? 관련 경고가 발생하기 때문에
	
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	// 0~99까지의 값만을 보이게 하고 싶다.
	cout << (rand() % 100) << endl;

	// 100~199까지의 값만을 보이게 하고 싶다.
	cout << (rand() % 100 + 100) << endl;

	// 0~99.99까지의 값만을 보이게 하고 싶다.
	cout << (rand() % 10000 / 100.f) << endl;

	int iUpgrade = 0;
	cout << "upgrade 기본 수치를 입력하시오 : ";
	cin >> iUpgrade;

	float fPercent = rand() % 10000 / 100.f;

	cout << "upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	// 강화 확률 : 0~3 : 100%, 4~6% : 20%, 7~9 : 10%, 10~13 : 1%, 14~15 : 0.01%
	if (iUpgrade <= 3)
		cout << "강화 성공" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	
	/* switch
	분기문의 한 종류이다. if문이 조건을 체크하는 분기문이라면
	switch문은 값이 뭔지를 체크하는 분기문이다.
	형태 : switch(변수) {}의 현태로 구성된다
	코드블럭안에는 case, break 구분이 들어가게 된다
	case 상수 : 의 형태로 처리가 되고 변수값이 무엇인지에 따라서 case뒤에 오는 상수를 비교하게 된다
	*/
	
	int iNumber;
	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	switch (iNumber)
	{
	case NUM_1: 
		cout << "입력한 숫자는 1입니다." << endl;
		break; // 여기에 break가 없을경우 아래에있는 case 구문도 강제로 실행이 되게 한다
	case NUM_2:
		cout << "입력한 숫자는 2입니다." << endl;
		break;
	case NUM_3:
		cout << "입력한 숫자는 3입니다." << endl;
		break;
	case NUM_4:
		cout << "입력한 숫자는 4입니다." << endl;
		break;
	default: // if 문의 else와 비슷한 역할을 한다
		cout << "그 외의 숫자입니다." << endl;
	}
	
	// 열거체 타입의 변수를 선언했다. 열거체 타입 변수는 무조건 4byte를 차지하게 된다
	// 열거체를 이용해서 선언한 변수의 값의 표현 범위가
	// 열거체에 나열된 값들 안에서 선택해서 사용한다
	NUM eNum;

	// sizeof(타입 or 변수)를 사용하게 되면 해당 타입 혹은 병수의 메모리 크기를 구해준다
	cout << sizeof(NUM) << endl;
	// typeid(타입 or 변수).name()를 사용하게 되면 typeid 안에 들어간 타입 혹은
	// 변수의 타입을 문자열로 반환해준다
	cout << typeid(eNum).name() << endl;


	/*
	반복문 : 특정 작업을 반복해서 수행하는 기능이다
	종류 : for, while, do while 3종류가 존재한다.
	while(조건식){}의 형태로 구성된다.
	조건식을 체크해서 ture일 경우 코드가 동작되고 다시 조건식을 체크한다 언제까지? false가 될때까지
	하지만 반복문 안에서 break를 할 경우 해당 반복문을 빠져나온다
	*/
	
	iNumber = 0;
	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
			break;
	}
	// 화면을 깨끗이 지워준다
	system("cls");

	srand((unsigned int)time(0));

	int iPlayer, iAI;
	while (true)
	{
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;

		if (iPlayer < 1 || iPlayer > 4)
		{
			cout << "잘못된 값을 입력하였습니다." << endl;
			//  일시정지
			system("pause");
			// countinue : 반복문의 시작점으로 이동시킨다
			continue;
		}
		else if (iPlayer == 4)
			break;

		iAI = rand() % 3 + 1;

		switch (iAI)
		{
		case 1:
			cout << " AI : 가위" << endl;
			break;
		case 2:
			cout << " AI : 바위" << endl;
			break;
		case 3:
			cout << " AI : 보" << endl;
			break;
		}

		int iWin = iPlayer = iAI;

		if (iWin == 1 || iWin == -2)
			cout << "Player의 승리" << endl;
		else if (iWin == 0)
			cout << "비김" << endl;
		else
			cout << "AI 승리" << endl;
	}

	system("cls");

	// 위가 뾰족한 직각삼각형
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	// 아래가 뾰족한 직각삼각형
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	// 삼각형
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << " ";
		}
		for (int j = 0; j < i * 2 + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	
	system("cls");
	// 구구단을 2단부터 9단까지 출력한다
	for (int i = 2; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << "*" << j << " = " << i * j << endl;
		}
	}
	// 구구단을 출력하지만 
	// 2 3 4
	// 5 6 7
	// 8 9 10 형식으로 출력하고 싶다
	
	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << "*" << j << " = " << i * j << "\t";
			cout << i + 1 << "*" << j << " = " << (i + 1) * j << "\t";
			cout << i + 2 << "*" << j << " = " << (i + 2) * j << endl;
		}
		cout << endl;
	}
	

	return 0;
}