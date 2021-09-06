#pragma once

#include <string>
#include "Player.h"
using namespace std;

class WordGame
{
private:
	int player_num;
	string prev_word;
	string now_word;

	Player* player;
public:
	WordGame();
	WordGame(int num);
	~WordGame();
	bool is_end_game();
	void start();
	void run();
};
