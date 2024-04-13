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
	// ���漱���� �ڵ� ���� ���� �ƴ϶�, �ش� Ÿ����
	// ����ϰ��� �Ϸ��� ��ġ���� �� ���� �ִ�.
	class Player* player_;

public:
	class Player* GetPlayer()
	{
		return player_;
	}

public:
	bool Init();
};