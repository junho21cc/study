#include <iostream>

// ���Ϳ� ����Ʈ�� Ŭ���� ���ø����� �⺻������ �����ϴ� �ý����̴�
#include <vector>
#include <list>

using namespace std;



int main()
{
	// vector�� �޸������� ���ӵ� �ڷᱸ��
	vector<int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	// vector���� push_front �Լ��� �������� �ʴ´�. ��ȿ�����̱� ������

	vecInt[0] = 100;
	vecInt.at(0);
	// vecInt[0]; ���� ���尡 ������ ���̴�
	

	vecInt.data();
	vecInt.size();
	vecInt.capacity();

	// list�� �޸������� ���ӵ��� ���� �ڷᱸ��
	list<int> listInt;
	listInt.push_front(100);
	listInt.push_back(10);


	for (size_t i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt.at(i) << endl;
	}

	vector<int>::iterator veciter = veciter.begin();
	*veciter = 100;
	veciter++;

	vecInt[0] = 100;



	// iterator(inner class)
	list<int>::iterator iter = listInt.begin();
	int iData = *iter;
	iter++;
	iData = *iter;




	return 0;
}