#pragma once
#include "240413_value.h"
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

private:
	static ObjectManager* obj_manager_instance_;

public:
	static ObjectManager* GetInstance()
	{
		if (!obj_manager_instance_)
			obj_manager_instance_ = new ObjectManager;
		return obj_manager_instance_;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(obj_manager_instance_);
	}

private:
	// 전방선언을 코드 가장 위가 아니라, 해당 타입을
	// 사용하고자 하려는 위치에서 할 수도 있다.
	class Player* player_;

public:
	class Player* GetPlayer()
	{
		return player_;
	}

public:
	bool Init();
};