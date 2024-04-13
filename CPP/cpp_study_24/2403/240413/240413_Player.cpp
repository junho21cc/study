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
	// Ű �Է��� �޴´�.
	// GetAsyncKeyState �Լ��� Win32 API ���� �����Ǵ� Ű �Է� �Լ��̴�.
	// WŰ�� ������ �� �ٷ� �����ϰ� �ϱ� ���� 0x8000�� & ������ �Ͽ�
	// ������ ��� true�� ������ �ȴ�
	// �̰� �̷��� �������ִ�. ���߿� winAPI ��ﶧ ����� ����.
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
				cout << "�÷��̾� ���" << endl;
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
		// �̷��� �����ϸ�, ����ϰ� �ٽ� ������ ������ ���� ������ �ִ� ������ �̹� ������ִ�.
		// ���������� ���� ������ ������ �־��Ѵ�.
		stage->ChangeBlock(pos_.x, pos_.y, sbt_road);
		score_ += 1000;
	}

	else if (stage->GetBlock(pos_.x, pos_.y) == sbt_end)
	{
		complete_ = true;
	}

	if (pos_.y >= BLOCK_Y)
	{
		cout << "�÷��̾� ���" << endl;
		pos_ = stage->GetStart();
		score_ = 0;
		stage->ResetStage();

		system("pause");
	}
}