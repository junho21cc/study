#pragma once

#include "240413_value.h"

// ������Ͽ��� Ŭ������ ����κ��� ���´�.
class Core
{
private:
	Core();
	~Core();

private:
	static Core* core_instance_;

public:
	static Core* GetInstance();
	static void DestroyInst();

public:
	// �� �Լ��� ��ü ������ �ʱ�ȭ�ϴ� ������ �Ѵ�.
	bool Init();

	// �� �Լ��� ������ ���۽�Ű�� ������ �Ѵ�.
	void Run();

private:
	int OutputMenu();
};