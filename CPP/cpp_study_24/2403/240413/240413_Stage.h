#pragma once

#include "240413_value.h"

enum StageBlockType
{
	sbt_wall = '0',
	sbt_road = '1',
	sbt_start = '2',
	sbt_end = '3',
	sbt_coin = '4'
};

class Stage
{
public:
	Stage();
	~Stage();

private:
	char origin_stage_[BLOCK_Y][BLOCK_X];
	char stage_[BLOCK_Y][BLOCK_X];
	POINT start_;
	POINT end_;

public:
	POINT GetStart() { return start_; }
	POINT GetEnd() { return end_; }

	char GetBlock(int x, int y)
	{
		return stage_[y][x];
	}

	void ChangeBlock(int x, int y, StageBlockType block)
	{
		stage_[y][x] = block;
	}

public:
	// �� �Լ��� �׳� �ʱ�ȭ�� ������ �Լ��̴�.
	bool Init();

	// �� �Լ��� ���Ͽ��� ������ �о�ͼ� ������ ������ �Լ��̴�.
	bool Init(const char* pFileName);
	void Render();
	void ResetStage();
};