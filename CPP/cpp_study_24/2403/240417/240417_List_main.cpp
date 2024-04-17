#include <iostream>

#include "240417_CList.h"

// using namespace std;

/*
cout�� endl�� namespace����� ����Ѵ�
*/
using std::cout;
using std::cin;
using std::endl;


class CMyOstream
{
public:
	CMyOstream& operator << (int _idata)
	{
		printf("%d", _idata);
		return *this;
	}
	CMyOstream& operator << (const char* _pString)
	{
		printf("%s", _pString);
		return *this;
	}
	CMyOstream& operator >> (int& _idata)
	{
		scanf_s("%d", &_idata);
		return *this;
	}
};

CMyOstream mycout;

namespace MYSPACE
{
	int g_int;
}

int main()
{
	CList<int> list;

	for (int i = 0; i < 4; i++)
	{
		list.push_back(i);
	}

	MYSPACE::g_int = 0;

	cout << "�ȳ�" << MYSPACE::g_int << endl;


	mycout << 10 << 20 << 30;
	mycout << "�ȳ�";
	int a = 0;
	mycout >> a;

	mycout << a;

	return 0;
}


/*

extern Ű���� : �ٸ� ���Ͽ��� �̹� �̸��� ���� ���������� ������ �Ǿ��ٴ� �ǹ�. ��, �ٸ� ���ϰ��� ������ �����ϰ� �ִٶ�� ���̴�.

_EXPORT_STD extern "C++" __PURE_APPDOMAIN_GLOBAL _CRTDATA2_IMPORT istream cin;
_EXPORT_STD extern "C++" __PURE_APPDOMAIN_GLOBAL _CRTDATA2_IMPORT ostream cout;
*/