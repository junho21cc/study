#include <iostream>

using namespace std;

class CParent
{
private:
	int m_i;
public:
	CParent()
		:m_i(0)
	{}
	~CParent()
	{}

};

// 상속
class CChild : public CParent
{
private:
	float m_f;

public:
	CChild()
		: m_f(0.f)
	{}

};

int main()
{
	/*
	객체지향 언어 특징
	1. 캡슐화(은닉성)
	2. 상속
	3. 다형성
	4. 추상화

	상속받은 자식클래스는 (부모+자식의 독립적인부분) 이런 모양으로 메모리 할당이 된다
	그래서 자식은 부모의 private 멤버에 접근할 수 없다.
	하지만 public멤버가 아닌 은닉된 멤버를 자식에게 상속하고 싶다면 접근제한을 protected로 선언해준다면 된다

	독립적인 클래스는 선언과동시에 생성자가 실행된다
	하지만 자식클래스는 어떻게 할까?
	자식 클래스는 (부모+자식의 독립적인부분) 이런 모양으로 생겼기 때문에 부모클래스의 생성자가 실행되고, 
	자식의 생성자가 실행된다

	자식의 생성자에는 부모의 멤버변수들의 초기화(이니셜라이징)가 불가능하다

	생성자 호출 자체는 주가 되는 클래스(자식클래스) 먼저 되지만 
	이니셜라이저 되기 전에 부모 클래스쪽으로 이동하기에 실제 순서는 
	[자식 클래스 생성자 호출 > 부모 클래스 생성자 호출 > 부모 클래스 초기화 
	> 부모 클래스 기능 실행 > 자식 클래스 초기화 > 자식 클래스 기능 실행] 이다.
	*/

	CParent parent;
	CChild child;

	return 0;
}