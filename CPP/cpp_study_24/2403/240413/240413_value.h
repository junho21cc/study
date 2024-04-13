
#pragma once

#include <iostream>
// Windows.h ������� �������� ����� ����� �� �ִ� ���� �Լ�����
// �������ְ� �ִ�. �츮�� ���⿡�� Ű�Է� ����� Ȱ���� ���̴�.
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

// ��ũ�δ� #define�� �̿��ؼ� ����� ������ִ� ���̴�. �� ��ũ�θ� ����ϰ�
// �Ǹ� ����� �κп� �����ϴܰ迡�� ���� �ڵ带 �������ִ� �����̴�.
// ��ũ���� ���� : �극��ũ �����͸� �ɰ� ���� üũ�� �� ����.
#define	SAFE_DELETE(p)	if(p)	{ delete p; p = NULL; }

// Stage Max Count
#define	STAGE_MAX_COUNT	3

// �ִ� �� ����
#define BLOCK_X 50
#define BLOCK_Y 10

// ȭ�鿡 ��µ� ���� ����
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