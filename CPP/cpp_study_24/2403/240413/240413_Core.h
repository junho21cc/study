#pragma once

#include "240413_value.h"

// 헤더파일에는 클래스의 선언부분이 들어온다.
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
	// 이 함수는 전체 게임을 초기화하는 역할을 한다.
	bool Init();

	// 이 함수는 게임을 동작시키는 역할을 한다.
	void Run();

private:
	int OutputMenu();
};