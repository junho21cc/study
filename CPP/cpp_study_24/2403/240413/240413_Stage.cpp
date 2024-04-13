#include "240413_Stage.h"
#include "240413_FileStream.h"
#include "240413_Player.h"
#include "240413_ObjectManager.h"


Stage::Stage()
{
}

Stage::~Stage()
{
}

bool Stage::Init()
{
	return true;
}

bool Stage::Init(const char* pFileName)
{
	FileStream file;

	if (!file.Open(pFileName, "rt"))
		return false;

	// FileStream �Ҹ��ڿ��� fclose ����ϱ� ������
	// ������ fclose �� ����� �ʿ䰡 ����.

	for (int i = 0; i < BLOCK_Y; i++)
	{
		int size = 0;
		file.ReadLine(origin_stage_[i], size);

		for (int j = 0; j < BLOCK_X; j++)
		{
			stage_[i][j] = origin_stage_[i][j];
			if (origin_stage_[i][j] == sbt_start)
			{
				start_.x = j;
				start_.y = i;
			}
			else if (origin_stage_[i][j] == sbt_end)
			{
				end_.x = j;
				end_.y = i;
			}
		}
	}

	return true;
}

void Stage::Render()
{
	// ���� ��ũ�� ó���� �ؾ��Ѵ�. �׷��� ������ ���� �÷��̾
	// �̵��� ��ġ�κ��� ���� ������־�� �Ѵ�. ��� ũ���
	// ���� 4ĭ ���� 10ĭ���� ���ش�. ������ �÷��̾ ���� ��ġ�� �ִٰ�
	// �����ϰ� ó�� 4 x 10 ����� ���ش�.
	// 0 : ��, 1 : ��, 2 : ������, 3 : ������, 4 : ����

	Player* player = ObjectManager::GetInstance()->GetPlayer();

	int x = player->GetX();
	int y = player->GetY();

	// ���� ����� �÷��̾��� ��ġ�� �߽����� ����̴�.
	// ���δ� �÷��̾� 2ĭ ������ ��ĭ �Ʒ����� ��� => �� 5ĭ
	// ���δ� �÷��̾� ��ġ���� ������ 10ĭ���� ���.
	// ��µ� �� ���� 2�� ����� ��µ� ���� �Ʒ��� �ε����� ���Ѵ�.
	// �÷��̾� ��ġ���� 2ĭ �Ʒ����� ����ϵ��� �Ѵ�.
	int y_count = y + (RENDER_BLOCK_Y / 2);

	// ���� ��µ� �Ʒ� 2ĭ�� ���� ���� �Ʒ��� �ε������� ũ�ų� ���ٸ�,
	// ��µ� �Ʒ��� �ε����� ���� ������ �ε����� �����Ѵ�.
	if (y_count >= BLOCK_Y)
		y_count = BLOCK_Y - 1;

	int x_count = x + RENDER_BLOCK_X;
	if (x_count >= BLOCK_X)
		x_count = BLOCK_X - 1;

	// ����ؾ��� �ּ� �ε����� �����ش�.
	// ���� �ڵ忡�� �׷� ���ɼ��� ������, �÷��̾ ���� ������ �ö� ���
	// �� ���� ���� ����� �Ǹ� �� �ǹǷ� y_min < 0 ���� ����ó�� ��.
	int y_min = y_count - (RENDER_BLOCK_Y - 1);
	if (y_min < 0)		y_min = 0;

	// ���� ������ �� 10ĭ�� ��ũ���� ���� �ʰ� ��� �����ֱ� ���ؼ�
		// �ݺ����� �ּҰ��� (�� ��ü���� - ��µ� ��) ���� ó�����ش�.
	int x_min = x;
	if (x_min > BLOCK_X - RENDER_BLOCK_X)
		x_min = BLOCK_X - RENDER_BLOCK_X;

	for (int i = y_min; i <= y_count; ++i) // �÷��̾� �� �� ĭ �Ʒ����� ���
	{
		for (int j = x_min; j <= x_count; ++j) // �÷��̾� �� 10ĭ ���
		{
			if (i == y && j == x)
				cout << "��";
			else if (stage_[i][j] == sbt_wall)
				cout << "��";
			else if (stage_[i][j] == sbt_road)
				cout << "  ";
			else if (stage_[i][j] == sbt_start)
				cout << "��";
			else if (stage_[i][j] == sbt_end)
				cout << "��";
			else if (stage_[i][j] == sbt_coin)
				cout << "��";
			else
				cout << "//";
		}
		cout << endl;
	}
}

void Stage::ResetStage()
{
	for (int i = 0; i < BLOCK_Y; i++)
	{
		for (int j = 0; j < BLOCK_X; j++)
		{
			stage_[i][j] = origin_stage_[i][j];
		}
	}
}