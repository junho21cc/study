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
    prev_word = "아버지";

    cout << "끝말 잇기 게임을 시작합니다" << endl;
    cout << "참가하는 인원은 몇명입니까?";
    cin >> player_num;

    player = (Player*)new Player[player_num];


    new int;

    for (int i = 0; i < player_num; i++)
    {
        string name;
        cout << "참가자의 이름을 입력하세요. 빈칸없이>>";
        cin >> name;

        player[i].set_Player_name(name);
    }
}

void WordGame::run()
{
    int i = 0;
    while (1)
    {
        // 위에 start()에서 사용한 Player class를 재사용하고 싶다.
        cout << player[i].name << ">>";
        cin >> now_word;

        if (is_end_game())
        {
            cout << "끝!" << endl;
            cout << player[i].name << "이가 졌습니다!";
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
