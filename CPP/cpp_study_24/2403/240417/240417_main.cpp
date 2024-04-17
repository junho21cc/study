#include <iostream>

using namespace std;

/*
템플릿 : 컴파일 단계에서 타입을 결정짓는 기능이다
타입이 다양하게 바뀔 수 있다?
template <typename 원하는이름>의 형태로 사용 가능하다
template <class 원하는이름>의 형태로 사용 가능하다

ex) teplate <typename T> → 치환 자료형
void Output()
{
	cout << typeid(T).name() << endl;
}
위처럼 함수를 만들고 호출시
Output<int>();
Output<float>();

이렇게 해주면, int, float로 타입이 정해진다. 상황에 따라 넣어주는 타입으로 타입이 가변적으로 바뀌는 것이다

가변타입은 여려개를 지정해 줄 수 있다.
templaye<typename T, typename T1>
void Output()
{
	
}
위치럼 여러개 지정도 가능한 것이다.
*/

// 함수 템플릿
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