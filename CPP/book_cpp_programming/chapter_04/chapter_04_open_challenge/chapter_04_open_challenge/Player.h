#pragma once

#include <string>
using namespace std;

// cannot be defined in the result type of a function ����
// ���� �������� ã�ƺ����� ���ϰ� �ٸ� ����̴�.

class Player
{
public:
	string name;
public:
	Player();
	~Player();
	void set_Player_name(string Name);
	void speak();
};
