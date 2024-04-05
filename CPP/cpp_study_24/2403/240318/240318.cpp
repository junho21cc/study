#include <iostream>

using namespace std;

int main()
{
	/*
	비트 연산자, 논리 연산자

	비트를 알기 위해서는진수라는 개념을 알아한다.

	진수 : 2진수, 8진수, 10진수, 16진수

	진수는 서로 다른 진수로 변환이 가능하다

	87을 2진수, 16진수로 변환해보자

	먼저 2진수로 변환한다.

	87 / 2 = 43 -- 1
	43 / 2 = 21 -- 1
	21 / 2 = 10 -- 1
	10 / 2 = 5 --- 0
	5 / 2 = 2 ---- 1
	2 / 2 = 1 ---- 0
	1010111

	2진수를 16진수로 변환 → 오른쪽으로부터 4자리씩 끊어서 계산
	0101 0111
	8421 8421

	2진수가 1인 부분의 값을 더한다.
	5 7

	비트 연산자

	2진수 단위의 연산을 한다. 값대 값으로 연산하여 값으로 나온다.

	종류 : AND(&), OR(|), NOT(-), XOR(^)

	ex)
	A	B	XOR
	0	0	0
	1	0	1
	0	1	1
	1	1	0

	87 & 53
	53 → 110101
	87 → 1010111

	먼저 위처럼 2진수로 바꾼뒤에 2진수 각 자리별로 논리연산을 실행한다

	1010111
	0110101

	→ 0010101
	→ 21(10진수)

	*/
	cout << (87 & 53) << endl;

	// 상수 : 변하지 않는 수, 값을 한번 지정해놓으면 바꿀 수 없다

	const int iAttack = 0x00000001;
	const int iArmor = 0x00000002;
	const int iHP = 0x00000004;
	const int iMP = 0x00000008;
	const int iCritical = 0x00000010;

	// 1 | 100 = 101 | 10000 | 101 = 10101
	// 버프를 추가하기 위해서는 or로 계산하면 된다.
	int iBuf = iAttack | iHP | iCritical;

	// 10101 & 00001 = 00001
	cout << "Attack : " << (iBuf & iAttack) << endl;

	cout << "Armor : " << (iBuf & iArmor) << endl;

	cout << "HP : " << (iBuf & iHP) << endl;

	cout << "MP : " << (iBuf & iMP) << endl;

	cout << "Critical : " << (iBuf & iCritical) << endl;

	// 컴퓨터는 일반적으로 2진수를 사용하기 때문에 진수 연산자를 배운다.

	iBuf ^= iHP;
	// 10101 ^ 00100 = 10001

	/*
	쉬프트 연산자 : <<, >>
	cout, cin에서 사용하긴 하지만 이것은 쉬프트 연산자가 아니다
	이 연산자 또한 이진수 단위의 연산을 한다

	20 << 2 =
	→ 1010000
	→ 80
	20 << 3 =
	→ 10100000
	→ 160

	N << M = N * 2^M

	20 >> 2 =
	→ 101
	→ 5

	20 >> 3 =
	→ 10
	→ 1

	*/

	// 상위 16비트, 하위 16비트 → 총 32비트

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;


	// iNumber에는 187이 들어가 있다. 이 값을 <- 방향으로 16비트 이동시키면
	// 상위 16비트에 값이 들어가게 된다

	iNumber <<= 16;

	// 하위 16비트를 채운다
	iNumber |= iLow;

	// Hight 값을 출력한다
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;


	// 증감 연산자 : ++, --가 있다. 1증가, 1감소
	// 전치와 후치의 차이점
	iNumber = 10;

	// 전치
	++iNumber;

	// 후치
	iNumber++;

	cout << ++iNumber << endl; // 전치를 사용했기때문에 +1되고 출력된다
	cout << iNumber++ << endl; // 후치를 사용했기때문에 출력되고 +1된다
	cout << iNumber << endl;

	// 분기문 : if, switch
	/*
	if : 조건을 체크해주는 기능이다
	형태 : if(조건식)
			{코드블럭}
	if문은 조건식이 true가 될 경우 코드블력 안의 코드가 동작한다
	false인 경우에는 동직하지 않는다.
	*/

	if (true)
	{
		cout << "if문의 조건식은 true입니다." << endl;
	}

	// 버프가 있는지 확인한다.
	if ((iBuf & iAttack) != 0)
		cout << "Attack 버프가 있습니다." << endl;
	if ((iBuf & iHP) != 0)
		cout << "HP 버프가 있습니다." << endl;
	if ((iBuf & iMP) != 0)
		cout << "MP 버프가 있습니다." << endl;
	if ((iBuf & iCritical) != 0)
		cout << "Critical 버프가 있습니다." << endl;

	/*
	else : if문과 반드시 같이 사용해야한다.
	if문 조건이 false일 경우 else가 있다면 else 구문안의 코드가 동작된다

	else if : if문과 반드시 같이 사용되야한다
	if문 아래, else 위에 있어야 한다
	else if는 몇개든 사용 가능하다.
	*/

	if (false)
		cout << "if문 조건이 ture입니다" << endl;
	else
		cout << "if문 조건이 false 입니다" << endl;

	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;
	if (10 <= iNumber && iNumber <= 20)
		cout << "10과 20사이의 숫자입니다." << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "20과 30사이의 숫자입니다." << endl;
	else if (31 <= iNumber && iNumber <= 40)
		cout << "30과 40사이의 숫자입니다." << endl;
	else
		cout << "그 외의 숫자입니다." << endl;

	return 0;
}