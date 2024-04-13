#include "240413_Core.h"
#include "240413_MapManager.h"
#include "240413_ObjectManager.h"
#include "240413_Player.h"

Core* Core::core_instance_ = NULL;

// cpp ���Ͽ��� Ŭ������ �����κ��� �ִ�.
Core::Core()
{
}

Core::~Core()
{
	MapManager::DestroyInst();
	ObjectManager::DestroyInst();
}

Core* Core::GetInstance()
{
	if (!core_instance_)
		core_instance_ = new Core;

	return core_instance_;
}

void Core::DestroyInst()
{
	SAFE_DELETE(core_instance_);
}

bool Core::Init()
{
	// �� �����ڸ� �ʱ�ȭ�Ѵ�. ���н� false�� �����Ѵ�.
	if (!MapManager::GetInstance()->Init())
		return false;

	// ������Ʈ ������ �ʱ�ȭ
	if (!ObjectManager::GetInstance()->Init())
		return false;

	return true;
}

void Core::Run()
{
	//CMapManager::GetInst()->Render();

	while (true)
	{
		int stage = OutputMenu();
		if (stage == 4)
			break;

		else if (stage == 0)
			continue;

		MapManager::GetInstance()->Run(stage - 1);
	}
}

int Core::OutputMenu()
{
	system("cls");
	cout << "1. Stage1" << endl;
	cout << "2. Stage2" << endl;
	cout << "3. Stage3" << endl;
	cout << "4. Exit" << endl;
	cout << "Input Stage : ";
	int input = InputInt();

	if (input < 1 || input > 4)
		return 0;

	return input;
}