#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14
#define STUDENT_MAX 10

struct _tagStudent
{
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNum[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};

	int iStudentCount = 0;
	int iStdNumber = 1;

	while (1)
	{
		system("cls");
		// 메뉴를 출력한다
		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";

		int iMenu;
		cin >> iMenu;
		/*
		cin << int 변수;라면 변수에는 정수를 입력해야 한다. 
		오른쪽에 오는 변수타입에 맞춰서 값을 입력해야 하는데 실수로 정수가 아닌
		문자를 입력할 경우 에러가 발생한다. 그렇기 때문에 예외처리로 애러가 발생했는지를 
		여기에서 체크하여 에러가 발생하면 cin 내부의 애러버퍼를 비워주고 cin 내부에 (입력버퍼가
		있는데 입력벼퍼는 입력한 값을 저장해놓고 그 값을 변수에 넣어주는 역할을 한다.)
		입력버퍼에 \n이 남아있으므로 버퍼를 순회하여 \n을 지워준다

		버퍼 : 임시저장공간
		먼저 애러를 체크한다.
		cin.fail()을 했을때 입력애러가 발생했을경우 true를 반환한다
		*/

		if (cin.fail())
		{
			// 에러버퍼를 지워준다
			cin.clear();

			//입력버퍼에 \n이 남아있으므로 입력버퍼를 검색해 지워준다
			// cin.ignore의 두 파라미터값은 검색하고자 하는 (버퍼크기, 찾고자하는 문자)이다
			// 그래서 처음부터 \n이 있는곳 까지 찾아서 그 부분을 지워 다시 입력받을 수 있도록 해준다

			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "================= 학생추가 =================" << endl;

			//등록하려는 학생이 등록할 수 있는 최대치일경우 더이상 등록이 안되게 막는다
			if (iStudentCount == STUDENT_MAX)
				break;

			//학생정보를 추가한다 학생정보는 학번, 이름, 주소, 전화번호, 과목별 점수는 입력받는다
			// 나머지 점수는 계산해 따로입력받지는 않는다
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;

			// cin은 ' '도 또한 '\n'와 같은 뜻으로 판단한다.
			cin.ignore(1024, '\n');
			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNum, PHONE_SIZE);

			cout << "국어점수 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어점수 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학점수 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal = 
				tStudentArr[iStudentCount].iKor + 
				tStudentArr[iStudentCount].iEng + 
				tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3;

			// 학번 추가해주기
			tStudentArr[iStudentCount].iNumber = iStdNumber;
			iStdNumber++;
			iStudentCount++;

			cout << "학생추가 완료" << endl;
			break;
		case MENU_DELETE:
			system("cls");

			cout << "================= 학생제거 =================" << endl;


			char strName[NAME_SIZE] = {};
			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);


			char strName[NAME_SIZE] = {};
			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i; j < iStudentCount - 1; j++)
					{
						tStudentArr[i] = tStudentArr[i + 1];
					}
					iStudentCount--;
				}
			}

			break;
		case MENU_SEARCH:
			system("cls");

			cout << "================= 학생탐색 =================" << endl;

			char strName[NAME_SIZE] = {};

			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNum << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어점수 : " << tStudentArr[i].iKor << endl;
					cout << "영어점수 : " << tStudentArr[i].iEng << endl;
					cout << "수학점수 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");

			cout << "================= 학생출력 =================" << endl;
			// 등록된 학생 수 만큼 반복하여 출력한다

			for (int i = 0; i < iStdNumber; i++)
			{
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNum << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "국어점수 : " << tStudentArr[i].iKor << endl;
				cout << "영어점수 : " << tStudentArr[i].iEng << endl;
				cout << "수학점수 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl;
			}
			
			break;
		default:
			cout << "메뉴를 잘못 선택했습니다 " << endl;
			break;
		}

		system("pause");
	}


	return 0;
}