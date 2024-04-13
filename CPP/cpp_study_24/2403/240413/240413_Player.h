#pragma once

#include "240413_value.h"

#define JUMP_BLOCK_MAX 2

enum JumpDir
{
	jd_stop,
	jd_up,
	jd_down
};

class Player
{
public:
	Player();
	~Player();

private:
	POINT pos_;
	bool is_jump_;
	int jump_dir_;
	int jump_state_;
	int score_;
	bool complete_;

public:
	void SetPos(int x, int y)
	{
		pos_.x = x;
		pos_.y = y;
	}

public:
	int GetX() { return pos_.x; }
	int GetY() { return pos_.y; }
	int GetScore() { return score_; }
	int GetComplete() { return complete_; }

public:
	bool Init();
	void Update();
};