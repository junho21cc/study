#include "240413_Core.h"

/*
170727 ���� : ���� 50 x 10 ���� �����.
Stage Ŭ���� Init�Լ����� �� ���� �����
Stage Ŭ������ Render�Լ��� ���� �̸��� ����ϴ� �ڵ带 �ۼ��϶�.
�� �Ŀ� Map ������ Ŭ������ Run�Լ����� �ش� ���������� ����϶�.
(Render �Լ� ȣ���϶�� �ǹ�)
*/

int main()
{
	// ������ �ʱ�ȭ�Ѵ�.
	if (!Core::GetInstance()->Init())
	{
		cout << "���� �ʱ�ȭ ����!!" << endl;
		Core::DestroyInst();

		return 0;
	}

	// �ʱ�ȭ�� �����ߴٸ� ������ ������Ų��.
	Core::GetInstance()->Run();

	// ������ ������ CCore ��ü�� �޸𸮿��� ������Ų��.
	Core::DestroyInst();

	return 0;
}