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

// ���
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
	��ü���� ��� Ư¡
	1. ĸ��ȭ(���м�)
	2. ���
	3. ������
	4. �߻�ȭ

	��ӹ��� �ڽ�Ŭ������ (�θ�+�ڽ��� �������κκ�) �̷� ������� �޸� �Ҵ��� �ȴ�
	�׷��� �ڽ��� �θ��� private ����� ������ �� ����.
	������ public����� �ƴ� ���е� ����� �ڽĿ��� ����ϰ� �ʹٸ� ���������� protected�� �������شٸ� �ȴ�

	�������� Ŭ������ ��������ÿ� �����ڰ� ����ȴ�
	������ �ڽ�Ŭ������ ��� �ұ�?
	�ڽ� Ŭ������ (�θ�+�ڽ��� �������κκ�) �̷� ������� ����� ������ �θ�Ŭ������ �����ڰ� ����ǰ�, 
	�ڽ��� �����ڰ� ����ȴ�

	�ڽ��� �����ڿ��� �θ��� ����������� �ʱ�ȭ(�̴ϼȶ���¡)�� �Ұ����ϴ�

	������ ȣ�� ��ü�� �ְ� �Ǵ� Ŭ����(�ڽ�Ŭ����) ���� ������ 
	�̴ϼȶ����� �Ǳ� ���� �θ� Ŭ���������� �̵��ϱ⿡ ���� ������ 
	[�ڽ� Ŭ���� ������ ȣ�� > �θ� Ŭ���� ������ ȣ�� > �θ� Ŭ���� �ʱ�ȭ 
	> �θ� Ŭ���� ��� ���� > �ڽ� Ŭ���� �ʱ�ȭ > �ڽ� Ŭ���� ��� ����] �̴�.
	*/

	CParent parent;
	CChild child;

	return 0;
}