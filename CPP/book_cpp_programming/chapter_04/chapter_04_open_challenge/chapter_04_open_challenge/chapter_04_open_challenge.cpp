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
	this->name = "�̸�����";
}

int main()
{
	int num;
	string who;

	WordGame* word = new WordGame[];

	cout << "���� �ձ� ������ �����մϴ�" << endl;
	cout << "������ �����ϴ� �ο��� �� �� �Դϱ�?";
	cin >> num;
	if (num <= 0)
		return 0;
	Player* player = new Player [num];

	for (int i = 0; i < num; i++)
	{
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ����>>";
		cin >> who;
		player[i].Player(who);
	}

	cout << "�����ϴ� �ܾ�� �ƹ��� �Դϴ�.";

	while (1)
	{
		string a;
		cin >> a;

		word->WordGame(a);
	}

	return 0;
}