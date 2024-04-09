#include "240409_DLL.h"

void InitList(PLIST pList)
{
	pList->pBegin = new NODE;
	pList->pEnd = new NODE;
	pList->iSize = 0;

	// ���۳���� �������� ������ ����̴�
	pList->pBegin->pNext = pList->pEnd;

	// ����������� ���� ���� ���۳���̴�.
	pList->pEnd->pPrev = pList->pBegin;

	pList->pEnd->pNext = NULL;
	pList->pBegin->pPrev = NULL;
}

void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
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
	cout << "1. �л��߰�" << endl;
	cout << "2. �л�����" << endl;
	cout << "3. �л�Ž��" << endl;
	cout << "4. �л����" << endl;
	cout << "5. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";

	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

// const �������̱� ������ ����Ű�� ����� ���� ������ �� ����
void OutputStudent(const PSTUDENT pStudent)
{
	cout << "�̸� : " << pStudent->strName << "\t�й� : " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t���� : " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << endl;
	cout << "���� : " << pStudent->iTotal << "\t��� : " << pStudent->fAvg << endl;
}

void Output(PLIST pList)
{
	int iMenu;

	while (1)
	{
		system("cls");
		cout << "==========�л����==========" << endl;
		cout << "1. ���������" << endl;
		cout << "2. ���������" << endl;
		cout << "�޴��� �����ϼ��� : ";
		iMenu = InputInt();

		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (iMenu)
	{
	case OT_OUTPUT:
		//�߰��Ǵ� ������ begin�� end ���̿� ��ġ�ȴ� �׷��Ƿ� begin�� ���� ��带 ���´�
		pNode = pList->pBegin->pNext;
		// ��尡 End�� �������� ���̻� ����� ��尡 �����Ƿ� �ݺ��� �����Ѵ�
		while (pNode != pList->pEnd)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pNext;
		}
		break;
	case OT_INVERSE:
		//���������� ����Ҷ��� end�� ���� ��带 ������ ��� ���� ���� �����Ѵ�
		// begin�� ������ ��� �ݺ��������Ѵ�
		pNode = pList->pEnd->pPrev;

		while (pNode != pList->pBegin)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pPrev;
		}
		break;
	}
	system("pause");
}

void Push_Back(PLIST pList)
{
	system("cls");
	cout << "==========�л��߰�==========" << endl;

	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "�й� : ";
	tStudent.iNumber = InputInt();

	cout << "���� : ";
	tStudent.iKor = InputInt();

	cout << "���� : ";
	tStudent.iEng = InputInt();

	cout << "���� : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;


	// ���� �߰��Ǵ� ���� End����� �������� End��� ���̿� �߰��ؾ� �Ѵ�
	// �׷��� pEnd�� pPrev ��带 ���س��´�
	PNODE pPrev = pList->pEnd->pPrev;

	// pEnd ��� ���� ����� �������� �߰��� ��带 �����Ѵ�
	pPrev->pNext = pNode;

	// �߰��� ����� ���� ���� End�� ���� ��带 �����Ѵ�
	pNode->pPrev = pPrev;

	// ���� �߰��� ����� ���� ��带 pEnd�� �����Ѵ�
	pNode->pNext = pList->pEnd;

	// pEnd ����� ���� ���� ���� �߰��� ��带 �����Ѵ�
	pList->pEnd->pPrev = pNode;

	pList->iSize++;
}


void Push_Front(PLIST pList)
{
	system("cls");
	cout << "==========�л��߰�==========" << endl;

	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "�й� : ";
	tStudent.iNumber = InputInt();

	cout << "���� : ";
	tStudent.iKor = InputInt();

	cout << "���� : ";
	tStudent.iEng = InputInt();

	cout << "���� : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;


	// ���� �߰��Ǵ� ���� End����� �������� End��� ���̿� �߰��ؾ� �Ѵ�
	// �׷��� pBegin�� pNext ��带 ���س��´�
	PNODE pNext = pList->pBegin->pNext;

	// pBegin ��� ���� ����� �������� �߰��� ��带 �����Ѵ�
	pNext->pPrev = pNode;

	// �߰��� ����� ���� ���� End�� ���� ��带 �����Ѵ�
	pNode->pNext = pNext;

	// ���� �߰��� ����� ���� ��带 pEnd�� �����Ѵ�
	pNode->pPrev = pList->pBegin;

	// pEnd ����� ���� ���� ���� �߰��� ��带 �����Ѵ�
	pList->pBegin->pNext = pNode;

	pList->iSize++;
}

void Search(PLIST pList)
{
	system("cls");
	cout << "==========�л�Ž��==========" << endl;

	cout << "Ž���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "ã�� �л��� �����ϴ�" << endl;
	system("pause");
}
/*
���� 
���� ����� ���� ����� ������ ���� ���� ���� �Ǿ��ִ�
�׷���
���� ���� �������� �ϱ� ������ ��������� ������带 ���� ����� �������� �ش�
���� ����� ������ ���� ��忡�� �������� �ش�

DN->PN->NN = DN		- ���� ����� ���� ����� ������ ���� ���� ���� �Ǿ��ִ�

DN->PN->NN = DN->NN	- ���� ���� �������� �ϱ� ������ ��������� ������带 ���� ����� �������� �ش�
DN->NN->PN = DN->PN	- ���� ����� ������ ���� ��忡�� �������� �ش�

*/
void Delete(PLIST pList)
{
	system("cls");
	cout << "==========�л�Ž��==========" << endl;


	cout << "������ �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			pList->iSize--;

			cout << strName << "�л��� �����Ͽ����ϴ�" << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "������ �л��� �����ϴ�" << endl;
	system("pause");
}