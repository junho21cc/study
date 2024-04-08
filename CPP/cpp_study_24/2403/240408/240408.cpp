#include <iostream>

using namespace std;

/*
동적할당
기본적으로 변수를 선언하는게 정적할당
이런 변수들은 
예를들어 글로벌 변수는 프로그램이 동작될때 할당되고 프로그램이 종료될때 해제된다
지역변수처럼 함수가 호출되고 끝날때 할당되고 해제되는 것들은 정적할당이다

원하는순간에 원하는크기만큼의 메모리를 할당하고 싶다 → 동적할당

일반적인 변수는 스택에 메모리영역에 할당된다
하지만 동적할당은 힙 메모리 영역에 할당된다

중요 : 할당을 해줬으면 해제를 해줘야한다

동적할당 : 메모리 생성을 원하는 시점에 할 수 있는 기능이다
메모리 영역중 힙 영역에 공간이 할당된다. 힙의 특성상 메모리를 해제하기 전까지는 계속 남아있다
동적할등을 하고 메모리를 해제하지 않으면 사용하지 않지만 공간은 계속 잡혀있다
해당 공간은 다른곳에서 사용이 불가능하다
이런 현상을 메모리 릭이라고 한다

동적할당은 new 키워드를 이용해서 할 수 있다
C언어 에서는 malloc()함수를 이용한다

new나 malloc 둘다 마찬가지로 힙영역에 메모리 공간을 할당하고 해당 메모리의 주소를 반환해준다

delete 키워드를 이용해서 동적할당 한 메모리를 해제해준다
delete 뒤에 메모리 주소를 넣어주면 된다


동적배열 할당방법 : new 타입[개수];의 형태로 사용 할 수 있다

*/

/*
링크드 리스트 : 자료구조의 한 종류이다. 자료구조란 데이터를 관리하는 방법을 말한다
링크드리스트는 데이터 목록을 연결시켜서 접근 할 수 있는 구조를 제공한다
데이터를 저장하기 위한 노드라는 것이 존재한다. 각 노드의 특징은 다음 노드를 알 수 있게 된다
다음 노드의 메모리 주소를 저장한다는 의미이다

리스트는 선형구조로 되어있다 그렇기 때문에 배열처럼 특정 요소에 바로 접근이 불가능하다
무조건 앞에서 부터 차례대로 타고 들어가야 한다
노드를 새로 추가할 때는 노드를 생성하고 마지막 노드에 연결만 해주기 때문에 개수의 제한이 없다


// 아래처럼 할당해주면 new뒤에 들어오는 타입인 int의 크기만큼 공간을 할당한다
// 즉 4바이트 공간을 할당했다는 것이다. 그 뒤로 할당한 공간의 메모리 주소를 pNumber에 넣어주었다
int* pNumber = new int;

*pNumber = 100;

delete pNumber;

// 아래처럼 동적배열로 할당하면 메모리 공간에 400바이트만큼 공간을 할당하고 해당 메모리의 시작 주소를 반환한다

int* pArray = new int[100];

pArray[1] = 300;

delete[] pArray;

*/

#define NAME_SIZE 32

enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, *PSTUDENT;

// 리스트 노드를 만든다
typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
}NODE, *PNODE;

// 리스트 구조체를 만들어준다
typedef struct _tagList
{
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, *PLIST;

void InitList(PLIST pList)
{
	// 포인터는 가급적으로 초기화 할때 NULL로 초기화 해두고 쓰는 것이 좋다
	// 왜냐하면 0이 아닌 모든수는 true이기 때문이다
	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

int OutputMenu()
{
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";

	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}

void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

void Insert(PLIST pList)
{
	system("cls");
	cout << "==========학생추가==========" << endl;

	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "학번 : ";
	tStudent.iNumber = InputInt();

	cout << "국어 : ";
	tStudent.iKor = InputInt();

	cout << "영어 : ";
	tStudent.iEng = InputInt();

	cout << "수학 : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	// 추가할 리스트 노드를 생성한다
	PNODE pNode = new NODE;

	// 현재추가하는 노드는 가장 마지막에 추가될 것이기 때문에 다음 노드가 존재하지 않는다
	// 그래서 다음 노드는 NULL로 초기화 하고 정보는 위에서 입력받은 학생정보를 주도록 한다
	pNode->pNext = NULL;
	pNode->tStudent = tStudent;

	if (pList->pBegin == NULL)
		pList->pBegin = pNode;
	else
		pList->pEnd->pNext = pNode;

	pList->pEnd = pNode;
}

void ClearList(PLIST pList)
{
	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

// const 포인터이기 때문에 가리키는 대상의 값을 변경할 수 없다
void OutputStudent(const PSTUDENT pStudent)
{
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl;
}

void Output(PLIST pList)
{
	system("cls");
	cout << "==========학생출력==========" << endl;

	PNODE pNode = pList->pBegin;
	int StudentCount = 1;

	while (pNode != NULL)
	{
		cout << StudentCount++ << ". ";
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;
	}

	cout << "학생 수 : " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList)
{
	system("cls");
	cout << "==========학생탐색==========" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}

	cout << "찾을 학생이 없습니다" << endl;
	system("pause");
}

void Delete(PLIST pList)
{
	system("cls");
	cout << "==========학생탐색==========" << endl;


	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;
	PNODE pPrev = NULL;

	while (pNode != NULL)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			cout << pNode->tStudent.strName << "학생 삭제" << endl;
			// 지울 노드의 다음 노드를 얻어온다
			PNODE pNext = pNode->pNext;

			// 만약 이전 노드가 NULL이라면 제일 첫번째 노드를 지운다
			if (pPrev == NULL)
			{
				delete pNode;
				pList->pBegin = pNext;

				if (pNext == NULL)
					pList->pEnd = NULL;
			}
			// 이전 노드가 있을 경우에는 이전 노드의 다음을 지운 노드의 다음 노드로 연결해준다
			else
			{
				delete pNode;
				pPrev->pNext = pNext;

				if (pNext == NULL)
					pList->pEnd = pPrev;
			}

			cout << strName << "학생 삭제 완료!" << endl;

			pList->iSize--;
			system("pause");
			return;
		}
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	cout << "삭제할 학생이 없습니다" << endl;
	system("pause");
}

int main()
{
	LIST tList;
	InitList(&tList);

	while (1)
	{
		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_INSERT:
			Insert(&tList);
			break;
		case MM_DELETE:
			Delete(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			Output(&tList);
			break;
		}
	}

	ClearList(&tList);

	return 0;
}