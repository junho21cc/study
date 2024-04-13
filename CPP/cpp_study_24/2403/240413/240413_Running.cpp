#include "240413_Core.h"

/*
170727 숙제 : 맵을 50 x 10 맵을 만든다.
Stage 클래스 Init함수에서 이 맵을 만들고
Stage 클래스에 Render함수를 만들어서 이맵을 출력하는 코드를 작성하라.
그 후에 Map 관리자 클래스의 Run함수에서 해당 스테이지를 출력하라.
(Render 함수 호출하라는 의미)
*/

int main()
{
	// 게임을 초기화한다.
	if (!Core::GetInstance()->Init())
	{
		cout << "게임 초기화 실패!!" << endl;
		Core::DestroyInst();

		return 0;
	}

	// 초기화에 성공했다면 게임을 구동시킨다.
	Core::GetInstance()->Run();

	// 동작이 끝나면 CCore 객체를 메모리에서 해제시킨다.
	Core::DestroyInst();

	return 0;
}