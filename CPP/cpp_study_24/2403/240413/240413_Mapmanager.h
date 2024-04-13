#pragma once

#include "240413_value.h"

// Ŭ���� ���漱�� : �̰����� ���漱���� Ŭ������ �ִ� ��� �ν��ϰ� �����.
// ���漱�� �� �κп����� ������ �ϴ� ���̱� ������ ���漱���� Ŭ������ ��ü
// �� �����ϴ��� ����� ����� ����� �� ����.
// �ܼ��� ������ ������ ������ �������� �ַ� ����ϰ� ���漱���� ���������
// �� ������� ����� #include �ϴ� ��Ȳ�� �����ְ� cpp���� ���� �����
// �� include�� ���־ ������� ���� include�ϴ� ��Ȳ�� ������ �� �ִ�.
class Stage;
class MapManager
{
private:
	MapManager();
	~MapManager();

private:
	static MapManager* map_manager_instance_;

public:
	static MapManager* GetInstance();
	static void DestroyInst();

private:
	Stage* stage_[STAGE_MAX_COUNT];
	int enable_stage_;

public:
	Stage* GetStage()
	{
		return stage_[enable_stage_];
	}

public:
	bool Init();
	void Run(int stage);
	void Render();


};