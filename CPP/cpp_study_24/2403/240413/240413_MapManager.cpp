#include "240413_MapManager.h"
#include "240413_Stage.h"
#include "240413_ObjectManager.h"
#include "240413_Player.h"

MapManager* MapManager::map_manager_instance_ = NULL;

MapManager::MapManager()
{
	for (int i = 0; i < STAGE_MAX_COUNT; ++i)
	{
		stage_[i] = NULL;
	}
}

MapManager::~MapManager()
{
	// �������� �޸� ����
	for (int i = 0; i < STAGE_MAX_COUNT; ++i)
	{
		SAFE_DELETE(stage_[i]);
	}
}

MapManager* MapManager::GetInstance()
{
	if (!map_manager_instance_)
		map_manager_instance_ = new MapManager;

	return map_manager_instance_;
}

void MapManager::DestroyInst()
{
	SAFE_DELETE(map_manager_instance_);
}

bool MapManager::Init()
{
	const char* stage_file[3] = { "Stage1.txt", "Stage2.txt", "Stage3.txt" };
	for (int i = 0; i < STAGE_MAX_COUNT; ++i)
	{
		stage_[i] = new Stage;

		if (!stage_[i]->Init(stage_file[i]))
			return false;
	}

	return true;
}

void MapManager::Run(int stage)
{
	Player* player = ObjectManager::GetInstance()->GetPlayer();
	enable_stage_ = stage;

	player->SetPos(stage_[stage]->GetStart().x, stage_[stage]->GetStart().y);

	while (true)
	{
		system("cls");

		if (GetAsyncKeyState('Q') & 0x8000)
			break;

		player->Update();
		stage_[stage]->Render();
		cout << "Score : " << player->GetScore() << endl;

		if (player->GetComplete())
		{
			cout << "���� Ŭ����!!" << endl;
			system("pause");
			break;
		}

		// ���� �ڵ��θ� �����ϸ� ȭ�� ��ȯ�� �ʹ� ������.
		// Sleep�� WinAPI���� �����ϴ� �Լ�.
		// Sleep �Լ��� ���ڷ� �ִ� ������ ms�ʸ�ŭ ��� �����.
		// ���⼱ 500ms �� �����. �� 0.5�ʾ� ����.
		// 1/1000�� ������ ��Ʈ�� �� ���� �ִ�.
		Sleep(50);
	}
}

void MapManager::Render()
{
	stage_[0]->Render();
}