#pragma once

#include <string>
using namespace std;

// cannot be defined in the result type of a function 오류
// 무슨 오류인지 찾아봤지만 나하고 다른 경우이다.

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
