#include "WordGame.h"
#include <iostream>

using namespace std;

WordGame::WordGame()
{

}

WordGame::~WordGame()
{
}

bool WordGame::is_end_game()
{
    if (prev_word.at(prev_word.size()-1) == now_word.at(1) && prev_word.at(prev_word.size() - 2) == now_word.at(0))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void WordGame::start()
{
    prev_word = "�ƹ���";

    cout << "���� �ձ� ������ �����մϴ�" << endl;
    cout << "�����ϴ� �ο��� ����Դϱ�?";
    cin >> player_num;

    player = (Player*)new Player[player_num];


    new int;

    for (int i = 0; i < player_num; i++)
    {
        string name;
        cout << "�������� �̸��� �Է��ϼ���. ��ĭ����>>";
        cin >> name;

        player[i].set_Player_name(name);
    }
}

void WordGame::run()
{
    int i = 0;
    while (1)
    {
        // ���� start()���� ����� Player class�� �����ϰ� �ʹ�.
        cout << player[i].name << ">>";
        cin >> now_word;

        if (is_end_game())
        {
            cout << "��!" << endl;
            cout << player[i].name << "�̰� �����ϴ�!";
            return;
        }
        prev_word = now_word;
        i++;
        if (i == player_num)
        {
            i = 0;
        }
    }
}
