#include <iostream>

using namespace std;

#define NAME_SIZE 32

/*
����ü : ����ü�� ū �ƶ����� ������ ����ϴ�.
�����ִ� �������� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ���
����� ���� ���� Ÿ���̴�.
���� : struct ����ü�� {}; �� ���·� �����ȴ�
�迭�� ����ü�� ������ : 
1. �������� �����̴�.
2. ���ӵ� �޸� ���� �Ҵ�ȴ�. ����ü ������� ���ӵ� �޸� ������ ������ �ȴ�.
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
���ڿ� �Լ�
1. strcpy_s
2. strcat_s
3. strcmp
*/


int main()
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};
	// ����ü ����� ������ ���� .�� �̿��� �����Ѵ�
	tStudent.iKor = 100;

	// ���ڿ��� �迭�� �־��� ���� �ܼ� �������� �Ұ����ϴ�
	// strcpy_s��� �Լ��� �̿��ؼ� ���ڿ��� �����ؾ��Ѵ�
	// ���ڿ��� ���� �׻� NULL������ �������Ѵ�
	// �迭�� NULL���� �ν��ϸ� �迭�� ������ �ν��ϰԵȴ�
	// strcpy_s�Լ��� �������� NULL���� �־��ֱ� ������ �����ϴ�
	strcpy_s(tStudent.strName, "asdasdfasdf");
	cout << "�̸� : " << tStudent.strName << endl;

	// strcat_s�� �����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�
	strcat_s(tStudent.strName, "�����ٶ�");

	// strcmp �Լ��� �� ���ڿ��� ���� ������ 0, �ٸ��� 0�� �ƴ� �ٸ� ���� ��ȯ�Ѵ�
	char strName[NAME_SIZE] = {};
	cout << "���� �̸��� �Է��ϼ��� : ";
	cin >> strName;
	if (strcmp(tStudent.strName, strName) == 0)
		cout << "�л��� ã�ҽ��ϴ�" << endl;
	else
		cout << "ã�� �л��� �����ϴ�" << endl;

	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng<< endl;
	cout << "���� : " << tStudent.iMath << endl;

	return 0;
}