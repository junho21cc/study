#include <iostream>

using namespace std;

// pp�� main�Լ� �ȿ� �ִ� int** Ÿ���� p������ �ּҸ� ���� �ȴ�
void Test(int** pp)
{
	*pp = new int;
}


int main()
{
	int* p = NULL;

	p = new int;

	Test(&p);

	FILE* pFile = NULL;
	
	/*
	1������ : ������ �����������δ�.
	2������ : ���ϰ���̴�. ������ �����Ǵ� ���� ��δ� ���� ������Ʈ�� �ִ� ���� �����̴�.
	���� �������Ϸ� �������� ��쿡�� �ش� exe������ �ִ� ��θ� �������� �������ش�
	3������ : ���� ����̴�. ���� ũ�� 2������ ���еȴ�
	���� �б�, ����, ������ �ְ�
	��������, �ؽ�Ʈ����, ���̳ʸ����� 2���� ��尡 �־ ���ļ� ����Ѵ�
	r : �б�, w : ����, a : ����
	t : �ؽ�Ʈ����, b : ���̳ʸ�����
	
	fopen_s(&pFile, "hot.txt", "wt");

	if (pFile != NULL)
	{
		// fwrite, freed 2���� �Լ��� �����ȴ�
		// fputs, fgets�� �����ȴ�.


		char* pText = (char*)"abcd";
			
		1�����ڴ� �����ϰ��� �ϴ� ���� �޸� �ּҸ� �־��ش�.
		2�����ڴ� �����ϰ��� �ϴ� ���� ����Ÿ���� �޸� ũ�⸦ �־��ش�
		3�����ڴ� �����ϰ��� �ϴ� ���� ������ �־��ش�
		4�����ڴ� ������ ������ ��Ʈ���� �־��ش�
		
		fwrite(pText, 1, 4, pFile);

		fclose(pFile);

		cout << "���ϸ���� ����" << endl;
	}
	*/

	fopen_s(&pFile, "hot.txt", "rt");

	if (pFile)
	{
		char strText[5] = {};

		fread(strText, 1, 4, pFile);

		cout << strText << endl;
	}
	return 0;
}