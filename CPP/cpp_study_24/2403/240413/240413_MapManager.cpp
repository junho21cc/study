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
	// 스테이지 메모리 해제
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
			cout << "게임 클리어!!" << endl;
			system("pause");
			break;
		}

		// 위에 코드대로만 실행하면 화면 전환이 너무 빠르다.
		// Sleep도 WinAPI에서 제공하는 함수.
		// Sleep 함수의 인자로 주는 숫자의 ms초만큼 잠시 멈춘다.
		// 여기선 500ms 씩 멈춘다. 즉 0.5초씩 멈춤.
		// 1/1000초 단위로 컨트롤 할 수도 있다.
		Sleep(50);
	}
}

void MapManager::Render()
{
	stage_[0]->Render();
}