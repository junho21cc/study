#include <iostream>

using namespace std;

/*
���ø� : ������ �ܰ迡�� Ÿ���� �������� ����̴�
Ÿ���� �پ��ϰ� �ٲ� �� �ִ�?
template <typename ���ϴ��̸�>�� ���·� ��� �����ϴ�
template <class ���ϴ��̸�>�� ���·� ��� �����ϴ�

ex) teplate <typename T> �� ġȯ �ڷ���
void Output()
{
	cout << typeid(T).name() << endl;
}
��ó�� �Լ��� ����� ȣ���
Output<int>();
Output<float>();

�̷��� ���ָ�, int, float�� Ÿ���� ��������. ��Ȳ�� ���� �־��ִ� Ÿ������ Ÿ���� ���������� �ٲ�� ���̴�

����Ÿ���� �������� ������ �� �� �ִ�.
templaye<typename T, typename T1>
void Output()
{
	
}
��ġ�� ������ ������ ������ ���̴�.
*/

// �Լ� ���ø�
template<typename T> 
T sum(T a, T b)
{
	return a + b;
}


template <typename T>
void OutputType()
{
	cout << typeid(T).name() << endl;
}

template<typename T>
void OutputType(T data)
{
	cout << "==== Output Data ====" << endl;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}

int main()
{
	OutputType<int>();
	OutputType<float>();

	OutputType(10);
	OutputType(3.1);
	OutputType("csd");
	OutputType('c');

	return 0;
}