#include <iostream>
#include <string>

using namespace std;

class WordGame
{
private:
	string game_string;
public:
	WordGame();
	WordGame(string word);
};


WordGame::WordGame()
{
	game_string = " ";
}
WordGame::WordGame(string word)
{
	game_string = word;
}

class Player
{
private:
	string name;
public:
	Player();
	Player(string name);
};

Player::Player(string Name)
{
	this->name = Name;
}

Player::Player()
{
	this->name = "이름없음";
}

int main()
{
	int num;
	string who;

	WordGame* word = new WordGame[];

	cout << "끝말 잇기 게임을 시작합니다" << endl;
	cout << "게임을 참가하는 인원은 몇 명 입니까?";
	cin >> num;
	if (num <= 0)
		return 0;
	Player* player = new Player [num];

	for (int i = 0; i < num; i++)
	{
		cout << "참가자의 이름을 입력하세요. 빈칸없이>>";
		cin >> who;
		player[i].Player(who);
	}

	cout << "시작하는 단어는 아버지 입니다.";

	while (1)
	{
		string a;
		cin >> a;

		word->WordGame(a);
	}

	return 0;
}