#include <iostream>

using namespace std;

#define NAME_SIZE 32

/*
구조체 : 열거체와 큰 맥락에서 봤을때 비슷하다.
관련있는 여려개의 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능
사용자 정의 변수 타입이다.
형태 : struct 구조체명 {}; 의 형태로 구성된다
배열과 구조체의 공통점 : 
1. 데이터의 집합이다.
2. 연속된 메모리 블럭에 할당된다. 구조체 멤버들은 연속된 메모리 블럭으로 잡히게 된다.
*/

struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float iAvg;
};


/*
문자열 함수
1. strcpy_s
2. strcat_s
3. strcmp
*/


int main()
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};
	// 구조체 멤버에 접근할 때는 .을 이용해 접근한다
	tStudent.iKor = 100;

	// 문자열을 배열에 넣어줄 때는 단순 대입으로 불가능하다
	// strcpy_s라는 함수를 이용해서 문자열을 복사해야한다
	// 문자열의 끝은 항상 NULL값으로 끝나야한다
	// 배열은 NULL값을 인식하면 배열의 끝으로 인식하게된다
	// strcpy_s함수는 복사이후 NULL값을 넣어주기 때문에 안전하다
	strcpy_s(tStudent.strName, "asdasdfasdf");
	cout << "이름 : " << tStudent.strName << endl;

	// strcat_s는 오른쪽에 있는 문자열을 왼쪽에 붙여준다
	strcat_s(tStudent.strName, "가나다라");

	// strcmp 함수는 두 문자열을 비교해 같으면 0, 다르면 0이 아닌 다른 값을 반환한다
	char strName[NAME_SIZE] = {};
	cout << "비교할 이름을 입력하세요 : ";
	cin >> strName;
	if (strcmp(tStudent.strName, strName) == 0)
		cout << "학생을 찾았습니다" << endl;
	else
		cout << "찾는 학생이 없습니다" << endl;

	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng<< endl;
	cout << "수학 : " << tStudent.iMath << endl;

	return 0;
}