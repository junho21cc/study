#include <iostream>

using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	cout << "-----------char ������-----------" << endl;
	int iNumber = 10;

	// ���������� ����迭�� �����. �װ��� �޸� �ּҸ� ���� �ִ°��� pText��
	const char* pText = "�ؽ�Ʈ ���ڿ�";

	cout << pText << endl;
	cout << (int*)pText << endl;

	// ���ڸ� �ٲ��. �׷��� �ٸ� �޸𸮿� �Ҵ�ȴ�
	pText = "abcd";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// ����� ���ڰ� ������ �׷��� �ٸ� �޸𸮿� �Ҵ�ȴ�
	pText = "abcde";
	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	char str[8] = "abcdefg"; // �迭�� ���۵Ǵ� ���� �迭�� �޸� �ּҴ�. �� �����ʹ�

	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	cout << "-----------����ü ������-----------" << endl;
	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	cout << "���� : " << tStudent.iKor << endl;

	// �����͸� ���� ���� : �ٸ� ������ �޸� �ּҸ� �˰��ֱ⶧���� ���� �����ϱ� ���ؼ� ����Ѵ�

	_tagStudent* pStudent = &tStudent;

	// ������ �켱���������� .�� ���� �ν��ϰԵȴ�. �׷��Ƿ� ��ȣ�� ����Ѵ�
	(*pStudent).iKor = 50;
	cout << "���� : " << tStudent.iKor << endl;

	// �̷� ������ε� ������ �� �ִ�.
	pStudent->iKor = 80;
	cout << "���� : " << tStudent.iKor << endl;

	cout << "-----------Void ������-----------" << endl;
	// void : �ֺ�, ����/ "Ÿ���� ����."
	// void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ��� ������ �����ϴ�
	// �� �������� �Ұ����ϰ� �޸� �ּҸ� ���� �����ϴ�

	void* pVoid = &iNumber;

	cout << "iNumber Address : " << pVoid << endl;

	// *pVoid = 10;
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	// iNumber�� �޸� �ּҰ��� �̿��� ���� �����Ѵ�
	cout << iNumber << endl;

	//���� ������ ���ٷ� ��� �� �� �ִ�
	*((int*)pVoid) = 9999;

	// iNumber�� �޸� �ּҰ��� �̿��� ���� �����Ѵ�
	cout << iNumber << endl;
	cout << "-----------���� ������-----------" << endl;
	// ���������� : ����Ÿ�� **�����̸� = ��;

	int iNumber1 = 1111;
	iNumber = 2222;
	int* pNum = &iNumber;

	// ����������. �Ϲ� ������ ������ �Ϲ� ������ �޸� �ּҸ� �����ϴ� ������� ���������ʹ� �������� �������̴�
	int** ppNum = &pNum;

	*pNum = 3333;

	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "*pNum Value : " << *pNum << endl;		// *pNum�� �� = iNumber�� ��
	cout << "pNum Value : " << pNum << endl;	// pNum�� ��
	cout << "pNum Address : " << &pNum << endl;	// pNum�� �޸� �ּҰ�
	cout << "*ppNum : " << *ppNum << endl;		// *ppNum�� ���������� pNum�� ���̴�
	cout << "**ppNum : " << **ppNum << endl;	// **ppNum�� ���������� *pNum�� ���̴�
	cout << "ppNum Value : " << ppNum << endl;	// ppNum�� ���� pNum�� �޸� �ּҰ��̴�
	cout << "ppNum Address : " << &ppNum << endl;	// &ppNum�� ���� ppNum�� �޸� �ּҰ��̴�


	return 0;
}