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

	// FileStream 소멸자에서 fclose 사용하기 때문에
	// 별도로 fclose 를 사용할 필요가 없다.

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
	// 맵은 스크롤 처리를 해야한다. 그렇기 때문에 현재 플레이어가
	// 이동한 위치로부터 맵을 출력해주어야 한다. 출력 크기는
	// 세로 4칸 가로 10칸으로 해준다. 지금은 플레이어가 시작 위치에 있다고
	// 가정하고 처음 4 x 10 출력을 해준다.
	// 0 : 벽, 1 : 길, 2 : 시작점, 3 : 도착점, 4 : 코인

	Player* player = ObjectManager::GetInstance()->GetPlayer();

	int x = player->GetX();
	int y = player->GetY();

	// 맵의 출력은 플레이어의 위치를 중심으로 출력이다.
	// 세로는 플레이어 2칸 위부터 두칸 아래까지 출력 => 총 5칸
	// 가로는 플레이어 위치부터 오른쪽 10칸까지 출력.
	// 출력될 블럭 수를 2로 나누어서 출력될 가장 아래쪽 인덱스를 구한다.
	// 플레이어 위치보다 2칸 아래까지 출력하도록 한다.
	int y_count = y + (RENDER_BLOCK_Y / 2);

	// 만약 출력될 아래 2칸이 맵의 가장 아래쪽 인덱스보다 크거나 같다면,
	// 출력될 아래쪽 인덱스는 맵의 마지막 인덱스로 고정한다.
	if (y_count >= BLOCK_Y)
		y_count = BLOCK_Y - 1;

	int x_count = x + RENDER_BLOCK_X;
	if (x_count >= BLOCK_X)
		x_count = BLOCK_X - 1;

	// 출력해야할 최소 인덱스를 구해준다.
	// 현재 코드에서 그럴 가능성은 적지만, 플레이어가 범위 끝까지 올라갈 경우
	// 맵 범위 밖은 출력이 되면 안 되므로 y_min < 0 으로 예외처리 함.
	int y_min = y_count - (RENDER_BLOCK_Y - 1);
	if (y_min < 0)		y_min = 0;

	// 가장 마지막 길 10칸은 스크롤이 되지 않고 모두 보여주기 위해서
		// 반복문의 최소값을 (블럭 전체길이 - 출력될 블럭) 으로 처리해준다.
	int x_min = x;
	if (x_min > BLOCK_X - RENDER_BLOCK_X)
		x_min = BLOCK_X - RENDER_BLOCK_X;

	for (int i = y_min; i <= y_count; ++i) // 플레이어 발 한 칸 아래까지 출력
	{
		for (int j = x_min; j <= x_count; ++j) // 플레이어 앞 10칸 출력
		{
			if (i == y && j == x)
				cout << "★";
			else if (stage_[i][j] == sbt_wall)
				cout << "■";
			else if (stage_[i][j] == sbt_road)
				cout << "  ";
			else if (stage_[i][j] == sbt_start)
				cout << "◑";
			else if (stage_[i][j] == sbt_end)
				cout << "◐";
			else if (stage_[i][j] == sbt_coin)
				cout << "＠";
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