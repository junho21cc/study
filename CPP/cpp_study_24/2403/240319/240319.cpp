#include <iostream>
#include <time.h> // �ð��� ���õ� �Լ��� ���ԵǾ��ִ�

using namespace std;

/*
����ü : ���ӵ� ���ڿ� �̸��� �ο��� �� �ִ� ����̴�
enum ����ü ��{}�� ���·� �����ȴ�
����ü���� �̿��Ͽ� ����ü Ÿ���� ������ ���� �����ϴ�
��, ����ü ��ü�� ����� ���� ���� Ÿ���� �� �� �� �ִ�.
����ü�� ���ڿ� �̸��� �ٿ��ִ� ����̴�.
*/

enum NUM
{
	NUM_0, // �ƹ��͵� �ο����� ������� 0���� 1�� ���ʴ�� ���� �ο��ȴ�
	NUM_1,
	NUM_2,
	NUM_3,
};

#define NUM_4 4

int main()
{
	
	// if���� ����Ͽ� ������ ��� �߻���Ű����
	// ��ǻ�Ϳ��� �׻� ���ϴ°��� �ð��ۿ� ���� �� �ð��� �̿��Ѵ�
	// signed ������� �Ѵ� ��밡��, unsigned ����� ��� ����
	srand((unsigned int)time(0)); // �� ��ȯ, type casting�� �Ѵ� ���ϳ�? ���� ��� �߻��ϱ� ������
	
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	// 0~99������ ������ ���̰� �ϰ� �ʹ�.
	cout << (rand() % 100) << endl;

	// 100~199������ ������ ���̰� �ϰ� �ʹ�.
	cout << (rand() % 100 + 100) << endl;

	// 0~99.99������ ������ ���̰� �ϰ� �ʹ�.
	cout << (rand() % 10000 / 100.f) << endl;

	int iUpgrade = 0;
	cout << "upgrade �⺻ ��ġ�� �Է��Ͻÿ� : ";
	cin >> iUpgrade;

	float fPercent = rand() % 10000 / 100.f;

	cout << "upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	// ��ȭ Ȯ�� : 0~3 : 100%, 4~6% : 20%, 7~9 : 10%, 10~13 : 1%, 14~15 : 0.01%
	if (iUpgrade <= 3)
		cout << "��ȭ ����" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	
	/* switch
	�б⹮�� �� �����̴�. if���� ������ üũ�ϴ� �б⹮�̶��
	switch���� ���� ������ üũ�ϴ� �б⹮�̴�.
	���� : switch(����) {}�� ���·� �����ȴ�
	�ڵ���ȿ��� case, break ������ ���� �ȴ�
	case ��� : �� ���·� ó���� �ǰ� �������� ���������� ���� case�ڿ� ���� ����� ���ϰ� �ȴ�
	*/
	
	int iNumber;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	switch (iNumber)
	{
	case NUM_1: 
		cout << "�Է��� ���ڴ� 1�Դϴ�." << endl;
		break; // ���⿡ break�� ������� �Ʒ����ִ� case ������ ������ ������ �ǰ� �Ѵ�
	case NUM_2:
		cout << "�Է��� ���ڴ� 2�Դϴ�." << endl;
		break;
	case NUM_3:
		cout << "�Է��� ���ڴ� 3�Դϴ�." << endl;
		break;
	case NUM_4:
		cout << "�Է��� ���ڴ� 4�Դϴ�." << endl;
		break;
	default: // if ���� else�� ����� ������ �Ѵ�
		cout << "�� ���� �����Դϴ�." << endl;
	}
	
	// ����ü Ÿ���� ������ �����ߴ�. ����ü Ÿ�� ������ ������ 4byte�� �����ϰ� �ȴ�
	// ����ü�� �̿��ؼ� ������ ������ ���� ǥ�� ������
	// ����ü�� ������ ���� �ȿ��� �����ؼ� ����Ѵ�
	NUM eNum;

	// sizeof(Ÿ�� or ����)�� ����ϰ� �Ǹ� �ش� Ÿ�� Ȥ�� ������ �޸� ũ�⸦ �����ش�
	cout << sizeof(NUM) << endl;
	// typeid(Ÿ�� or ����).name()�� ����ϰ� �Ǹ� typeid �ȿ� �� Ÿ�� Ȥ��
	// ������ Ÿ���� ���ڿ��� ��ȯ���ش�
	cout << typeid(eNum).name() << endl;


	/*
	�ݺ��� : Ư�� �۾��� �ݺ��ؼ� �����ϴ� ����̴�
	���� : for, while, do while 3������ �����Ѵ�.
	while(���ǽ�){}�� ���·� �����ȴ�.
	���ǽ��� üũ�ؼ� ture�� ��� �ڵ尡 ���۵ǰ� �ٽ� ���ǽ��� üũ�Ѵ� ��������? false�� �ɶ�����
	������ �ݺ��� �ȿ��� break�� �� ��� �ش� �ݺ����� �������´�
	*/
	
	iNumber = 0;
	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
			break;
	}
	// ȭ���� ������ �����ش�
	system("cls");

	srand((unsigned int)time(0));

	int iPlayer, iAI;
	while (true)
	{
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> iPlayer;

		if (iPlayer < 1 || iPlayer > 4)
		{
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			//  �Ͻ�����
			system("pause");
			// countinue : �ݺ����� ���������� �̵���Ų��
			continue;
		}
		else if (iPlayer == 4)
			break;

		iAI = rand() % 3 + 1;

		switch (iAI)
		{
		case 1:
			cout << " AI : ����" << endl;
			break;
		case 2:
			cout << " AI : ����" << endl;
			break;
		case 3:
			cout << " AI : ��" << endl;
			break;
		}

		int iWin = iPlayer = iAI;

		if (iWin == 1 || iWin == -2)
			cout << "Player�� �¸�" << endl;
		else if (iWin == 0)
			cout << "���" << endl;
		else
			cout << "AI �¸�" << endl;
	}

	system("cls");

	// ���� ������ �����ﰢ��
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	// �Ʒ��� ������ �����ﰢ��
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	// �ﰢ��
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
	// �������� 2�ܺ��� 9�ܱ��� ����Ѵ�
	for (int i = 2; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << "*" << j << " = " << i * j << endl;
		}
	}
	// �������� ��������� 
	// 2 3 4
	// 5 6 7
	// 8 9 10 �������� ����ϰ� �ʹ�
	
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