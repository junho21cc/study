#pragma once

#include <string>
using namespace std;

// cannot be defined in the result type of a function ����
// ���� �������� ã�ƺ����� ���ϰ� �ٸ� ����̴�.

class Player
{
private:
	string name;
public:
	Player();
	~Player();
	void set_Player_name(string Name);
	string show_player_name();
};
