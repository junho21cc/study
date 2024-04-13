#pragma once

#include "240413_value.h"

// 클래스 전방선언 : 이곳에서 전방선언한 클래스가 있다 라고 인식하게 만든다.
// 전방선언 한 부분에서는 가정만 하는 것이기 때문에 전방선언한 클래스의 객체
// 를 생성하던가 기능을 끌어다 사용할 수 없다.
// 단순히 포인터 변수를 선언할 목적으로 주로 사용하고 전방선언을 사용함으로
// 써 헤더에서 헤더를 #include 하는 상황을 막아주고 cpp에서 실제 사용할
// 때 include를 해주어서 헤더간에 서로 include하는 상황을 막아줄 수 있다.
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