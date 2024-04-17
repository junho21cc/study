#include <iostream>

#include "240417_CList.h"

// using namespace std;

/*
cout과 endl만 namespace기능을 사용한다
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

	cout << "안녕" << MYSPACE::g_int << endl;


	mycout << 10 << 20 << 30;
	mycout << "안녕";
	int a = 0;
	mycout >> a;

	mycout << a;

	return 0;
}


/*

extern 키워드 : 다른 파일에서 이미 이름이 같은 전역변수가 선언이 되었다는 의미. 즉, 다른 파일간의 변수를 공유하고 있다라는 뜻이다.

_EXPORT_STD extern "C++" __PURE_APPDOMAIN_GLOBAL _CRTDATA2_IMPORT istream cin;
_EXPORT_STD extern "C++" __PURE_APPDOMAIN_GLOBAL _CRTDATA2_IMPORT ostream cout;
*/