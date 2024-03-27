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
		// �޴��� ����Ѵ�
		cout << "1. �л����" << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";

		int iMenu;
		cin >> iMenu;
		/*
		cin << int ����;��� �������� ������ �Է��ؾ� �Ѵ�. 
		�����ʿ� ���� ����Ÿ�Կ� ���缭 ���� �Է��ؾ� �ϴµ� �Ǽ��� ������ �ƴ�
		���ڸ� �Է��� ��� ������ �߻��Ѵ�. �׷��� ������ ����ó���� �ַ��� �߻��ߴ����� 
		���⿡�� üũ�Ͽ� ������ �߻��ϸ� cin ������ �ַ����۸� ����ְ� cin ���ο� (�Է¹��۰�
		�ִµ� �Էº��۴� �Է��� ���� �����س��� �� ���� ������ �־��ִ� ������ �Ѵ�.)
		�Է¹��ۿ� \n�� ���������Ƿ� ���۸� ��ȸ�Ͽ� \n�� �����ش�

		���� : �ӽ��������
		���� �ַ��� üũ�Ѵ�.
		cin.fail()�� ������ �Է¾ַ��� �߻�������� true�� ��ȯ�Ѵ�
		*/

		if (cin.fail())
		{
			// �������۸� �����ش�
			cin.clear();

			//�Է¹��ۿ� \n�� ���������Ƿ� �Է¹��۸� �˻��� �����ش�
			// cin.ignore�� �� �Ķ���Ͱ��� �˻��ϰ��� �ϴ� (����ũ��, ã�����ϴ� ����)�̴�
			// �׷��� ó������ \n�� �ִ°� ���� ã�Ƽ� �� �κ��� ���� �ٽ� �Է¹��� �� �ֵ��� ���ش�

			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "================= �л��߰� =================" << endl;

			//����Ϸ��� �л��� ����� �� �ִ� �ִ�ġ�ϰ�� ���̻� ����� �ȵǰ� ���´�
			if (iStudentCount == STUDENT_MAX)
				break;

			//�л������� �߰��Ѵ� �л������� �й�, �̸�, �ּ�, ��ȭ��ȣ, ���� ������ �Է¹޴´�
			// ������ ������ ����� �����Է¹����� �ʴ´�
			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;

			// cin�� ' '�� ���� '\n'�� ���� ������ �Ǵ��Ѵ�.
			cin.ignore(1024, '\n');
			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNum, PHONE_SIZE);

			cout << "�������� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "�������� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "�������� : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal = 
				tStudentArr[iStudentCount].iKor + 
				tStudentArr[iStudentCount].iEng + 
				tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3;

			// �й� �߰����ֱ�
			tStudentArr[iStudentCount].iNumber = iStdNumber;
			iStdNumber++;
			iStudentCount++;

			cout << "�л��߰� �Ϸ�" << endl;
			break;
		case MENU_DELETE:
			system("cls");

			cout << "================= �л����� =================" << endl;


			char strName[NAME_SIZE] = {};
			cin.ignore(1024, '\n');
			cout << "������ �̸��� �Է��ϼ��� : ";
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

			cout << "================= �л�Ž�� =================" << endl;

			char strName[NAME_SIZE] = {};

			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "�̸� : " << tStudentArr[i].strName << endl;
					cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
					cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNum << endl;
					cout << "�й� : " << tStudentArr[i].iNumber << endl;
					cout << "�������� : " << tStudentArr[i].iKor << endl;
					cout << "�������� : " << tStudentArr[i].iEng << endl;
					cout << "�������� : " << tStudentArr[i].iMath << endl;
					cout << "���� : " << tStudentArr[i].iTotal << endl;
					cout << "��� : " << tStudentArr[i].fAvg << endl;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");

			cout << "================= �л���� =================" << endl;
			// ��ϵ� �л� �� ��ŭ �ݺ��Ͽ� ����Ѵ�

			for (int i = 0; i < iStdNumber; i++)
			{
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNum << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "�������� : " << tStudentArr[i].iKor << endl;
				cout << "�������� : " << tStudentArr[i].iEng << endl;
				cout << "�������� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl;
			}
			
			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ� " << endl;
			break;
		}

		system("pause");
	}


	return 0;
}