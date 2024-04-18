#include <iostream>

// 벡터와 리스트는 클래스 템플릿으로 기본적으로 지원하는 시스템이다
#include <vector>
#include <list>

using namespace std;



int main()
{
	// vector은 메모리적으로 연속된 자료구조
	vector<int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	// vector에는 push_front 함수를 지원하지 않는다. 비효율적이기 때문에

	vecInt[0] = 100;
	vecInt.at(0);
	// vecInt[0]; 위에 문장가 동일한 뜻이다
	

	vecInt.data();
	vecInt.size();
	vecInt.capacity();

	// list는 메모리적으로 연속되지 않은 자료구조
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