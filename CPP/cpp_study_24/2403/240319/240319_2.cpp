#include <iostream>

using namespace std;

int main()
{
	/*
	do while �� : �ݺ����� �� ����
	���� : do {} while(���ǽ�) �� ���·� ����
	while���� ó�� ���Ժ��� ���ǹ��� üũ������ do while ���� �ѹ� ������ ���� �ϰ� ����
	���ǽ��� üũ�� true �� ��쿡�� ���۵ȴ�
	*/
	int iNumber = 0; 
	
	do
	{
		cout << iNumber << endl;
	} while (iNumber > 0);

	/*
	�迭 : �������� ������ �ѹ��� ������ �� �� �ִ� ���
	���� : ����Ÿ�� �迭��[����] �� ���·� ������ �� �ִ�
	�迭�� Ư¡ : �迭�� ���ӵ� �޸𸮺��� ������ �Ҵ�ȴ�
	�迭�� �ε����� ����ؼ� ���ϴ� �κп� �����Ͽ� ���� ������ �� �ִ�
	�ε����¤� 0���� ����-1�� �����̴�.�� 10�̶�� 0~9������ �ε����� ���� �ȴ�

	�迭 �Ӹ� �ƴ϶� �Ϲ� �����鵵 ������ �ϰ� ���� �ʱ�ȭ ��Ű�� ���� ��� ������ ���� ���� �ȴ�
	
	�迭 ��ü�� 0���� �ʱ�ȭ ��Ű�� �ʹٸ�
	int iArray[10] = {}�̷� �������� �ϸ� �ȴ�
	

	�迭 ������ 2�� �����ϸ� ������ �迭�̵ǰ�, 3�� �����ϸ� 3���� ������ �ȴ�.


	*/

	int iArray[10];
	
	for (int i = 0; i < 10; i++)
	{
		iArray[i] = i;
		cout << iArray[i] << endl;
	}
	
	int iArray2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << iArray2[i][j] << " ";
		}
		cout << endl;
	}

	system("cls");

	srand((unsigned int)time(0));

	// �ζ� ���α׷�
	int Lotto[45] = {};

	for (int i = 0; i < 45; i++)
	{
		Lotto[i] = i + 1;
	}
	// ���´�
	int Temp, Idx1, Idx2;

	for (int i = 0; i < 100; i++)
	{
		Idx1 = rand() % 45;
		Idx2 = rand() % 45;

		Temp = Lotto[Idx1];
		Lotto[Idx1] = Lotto[Idx2];
		Lotto[Idx2] = Temp;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << Lotto[i] << endl;
	}

	return 0;
}