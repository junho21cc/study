#include "240413_Player.h"
#include "240413_MapManager.h"
#include "240413_Stage.h"

Player::Player()
{
}

Player::~Player()
{
}

bool Player::Init()
{
	pos_.x = 0;
	pos_.y = 8;

	is_jump_ = false;
	complete_ = false;
	jump_dir_ = jd_stop;
	jump_state_ = 0;
	score_ = 0;

	return true;
}

void Player::Update()
{
	Stage* stage = MapManager::GetInstance()->GetStage();
	// 키 입력을 받는다.
	// GetAsyncKeyState 함수는 Win32 API 에서 제공되는 키 입력 함수이다.
	// W키를 눌렀을 때 바로 반응하게 하기 위해 0x8000과 & 연산을 하여
	// 눌렀을 경우 true가 나오게 된다
	// 이건 이렇게 정해져있다. 나중에 winAPI 배울때 제대로 배운다.
	if (GetAsyncKeyState('A') & 0x8000)
	{
		if (stage->GetBlock(pos_.x - 1, pos_.y) != sbt_wall)
		{
			--pos_.x;
			if (pos_.x < 0)
				pos_.x = 0;
		}
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		if (stage->GetBlock(pos_.x + 1, pos_.y) != sbt_wall)
		{
			++pos_.x;
			if (pos_.x >= BLOCK_X)
				pos_.x = 49;
		}
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !is_jump_)
	{
		is_jump_ = true;
		jump_dir_ = jd_up;
		jump_state_ = 0;
	}

	if (is_jump_)
	{
		switch (jump_dir_)
		{
		case jd_up:
			++jump_state_;

			if (jump_state_ > JUMP_BLOCK_MAX)
			{
				jump_state_ = JUMP_BLOCK_MAX;
				jump_dir_ = jd_down;
			}

			else if (stage->GetBlock(pos_.x, pos_.y - 1) == sbt_wall)
			{
				--jump_state_;
				jump_dir_ = jd_down;
			}

			else
			{
				--pos_.y;
			}
			break;

		case jd_down:
			if (pos_.y >= BLOCK_Y)
			{
				cout << "플레이어 사망" << endl;
				system("pause");
				pos_ = stage->GetStart();
			}

			else if (stage->GetBlock(pos_.x, pos_.y + 1) == sbt_wall)
			{
				jump_dir_ = jd_stop;
				is_jump_ = false;
			}

			else
			{
				++pos_.y;
			}

			break;
		}
	}

	if (stage->GetBlock(pos_.x, pos_.y + 1) != sbt_wall && !is_jump_)
	{
		++pos_.y;
	}

	if (stage->GetBlock(pos_.x, pos_.y) == sbt_coin)
	{
		// 이렇게 변경하면, 사망하고 다시 게임을 시작할 때도 기존에 있던 코인이 이미 사라져있다.
		// 스테이지의 원본 정보를 저장해 둬야한다.
		stage->ChangeBlock(pos_.x, pos_.y, sbt_road);
		score_ += 1000;
	}

	else if (stage->GetBlock(pos_.x, pos_.y) == sbt_end)
	{
		complete_ = true;
	}

	if (pos_.y >= BLOCK_Y)
	{
		cout << "플레이어 사망" << endl;
		pos_ = stage->GetStart();
		score_ = 0;
		stage->ResetStage();

		system("pause");
	}
}