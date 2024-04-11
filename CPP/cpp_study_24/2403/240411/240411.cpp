#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define STUDENT_MAX 10

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, * PSTUDENT;


int main()
{
	/*
	* ���� �����
	STUDENT tStudent[STUDENT_MAX] = {};

	for (int i = 0; i < STUDENT_MAX; i++)
	{
		cout << "�̸� : ";
		cin >> tStudent[i].strName;

		tStudent[i].iNumber = i + 1;

		cout << "���� : ";
		cin >> tStudent[i].iKor;
		cout << "���� : ";
		cin >> tStudent[i].iEng;
		cout << "���� : ";
		cin >> tStudent[i].iMath;

		tStudent[i].iTotal = tStudent[i].iKor + tStudent[i].iEng + tStudent[i].iMath;

		tStudent[i].fAvg = tStudent[i].iTotal / 3.f;
	}

	// �л������� ���Ͽ� �����Ѵ�
	
	int iStudentCount = STUDENT_MAX;

	FILE* pFile = NULL;

	fopen_s(&pFile, "Student.std", "wb");

	if (pFile)
	{
		fwrite(&iStudentCount, 4, 1, pFile);

		for (int i = 0; i < iStudentCount; i++)
		{
			fwrite(&tStudent[i], sizeof(STUDENT), 1, pFile);
		}

		fclose(pFile);
	}
	*/

	STUDENT tStudent[STUDENT_MAX] = {};

	FILE* pFile = NULL;

	fopen_s(&pFile, "Student.std", "rb");

	int iStudentCount = 0;
	if (pFile)
	{

		// �����Ҷ� �л����� ���� ���� �����߱� ������ �л����� ���ϸ��� �о�´�

		fread(&iStudentCount, 4, 1, pFile);

		for (int i = 0; i < iStudentCount; i++)
		{
			fread(&tStudent[i], sizeof(STUDENT), 1, pFile);
		}

		fclose(pFile);
	}

	for (int i = 0; i < iStudentCount; i++)
	{
		cout << "�̸� : " << tStudent[i].strName << endl;
		cout << "�й� : " << tStudent[i].iNumber << endl;
		cout << "���� : " << tStudent[i].iKor << endl;
		cout << "���� : " << tStudent[i].iEng << endl;
		cout << "���� : " << tStudent[i].iMath << endl;
		cout << "���� : " << tStudent[i].iTotal << endl;
		cout << "��� : " << tStudent[i].fAvg << endl;
		cout << endl;
	}

	return 0;
}