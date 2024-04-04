#include <iostream>

using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	cout << "-----------char 포인터-----------" << endl;
	int iNumber = 10;

	// 내부적으로 상수배열을 만든다. 그것의 메모리 주소를 갖고 있는것이 pText다
	const char* pText = "텍스트 문자열";

	cout << pText << endl;
	cout << (int*)pText << endl;

	// 문자를 바꿨다. 그래서 다른 메모리에 할당된다
	pText = "abcd";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// 공통된 문자가 있지만 그래도 다른 메모리에 할당된다
	pText = "abcde";
	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	char str[8] = "abcdefg"; // 배열이 시작되는 점은 배열의 메모리 주소다. 즉 포인터다

	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	cout << "-----------구조체 포인터-----------" << endl;
	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	cout << "국어 : " << tStudent.iKor << endl;

	// 포인터를 쓰는 이유 : 다른 변수의 메모리 주소를 알고있기때문에 값을 제어하기 위해서 사용한다

	_tagStudent* pStudent = &tStudent;

	// 연산자 우선순위때문에 .을 먼저 인식하게된다. 그러므로 괄호를 사용한다
	(*pStudent).iKor = 50;
	cout << "국어 : " << tStudent.iKor << endl;

	// 이런 방식으로도 접근할 수 있다.
	pStudent->iKor = 80;
	cout << "국어 : " << tStudent.iKor << endl;

	cout << "-----------Void 포인터-----------" << endl;
	// void : 텅빈, 공허/ "타입이 없다."
	// void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장이 가능하다
	// 단 역참조가 불가능하고 메모리 주소만 저장 가능하다

	void* pVoid = &iNumber;

	cout << "iNumber Address : " << pVoid << endl;

	// *pVoid = 10;
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	// iNumber의 메모리 주소값을 이용해 값을 제어한다
	cout << iNumber << endl;

	//위의 두줄을 한줄로 요약 할 수 있다
	*((int*)pVoid) = 9999;

	// iNumber의 메모리 주소값을 이용해 값을 제어한다
	cout << iNumber << endl;
	cout << "-----------이중 포인터-----------" << endl;
	// 이중포인터 : 변수타입 **변수이름 = 값;

	int iNumber1 = 1111;
	iNumber = 2222;
	int* pNum = &iNumber;

	// 이중포인터. 일반 포인터 변수가 일반 변수의 메모리 주소를 저장하는 변수라면 이중포인터는 포인터의 포인터이다
	int** ppNum = &pNum;

	*pNum = 3333;

	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "*pNum Value : " << *pNum << endl;		// *pNum의 값 = iNumber의 값
	cout << "pNum Value : " << pNum << endl;	// pNum의 값
	cout << "pNum Address : " << &pNum << endl;	// pNum의 메모리 주소값
	cout << "*ppNum : " << *ppNum << endl;		// *ppNum의 역참조값은 pNum의 값이다
	cout << "**ppNum : " << **ppNum << endl;	// **ppNum의 역참조값은 *pNum의 값이다
	cout << "ppNum Value : " << ppNum << endl;	// ppNum의 값은 pNum의 메모리 주소값이다
	cout << "ppNum Address : " << &ppNum << endl;	// &ppNum의 값은 ppNum의 메모리 주소값이다


	return 0;
}