
#pragma once

#include <iostream>
// Windows.h 헤더에는 윈도우의 기능을 사용할 수 있는 여러 함수들을
// 제공해주고 있다. 우리는 여기에서 키입력 기능을 활용할 것이다.
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

// 매크로는 #define을 이용해서 기능을 만들어주는 것이다. 이 매크로를 사용하게
// 되면 사용한 부분에 컴파일단계에서 뒤의 코드를 복사해주는 개념이다.
// 매크로의 단점 : 브레이크 포인터를 걸고 값을 체크할 수 없다.
#define	SAFE_DELETE(p)	if(p)	{ delete p; p = NULL; }

// Stage Max Count
#define	STAGE_MAX_COUNT	3

// 최대 블럭 개수
#define BLOCK_X 50
#define BLOCK_Y 10

// 화면에 출력될 블럭의 범위
#define RENDER_BLOCK_X 10
#define RENDER_BLOCK_Y 5

static int InputInt()
{
	int input;
	cin >> input;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return input;
}