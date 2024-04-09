// #pragma once : 이 헤더파일을 딱 한번만 포함 시키겠다는 의미이다
#pragma once
#include <iostream>

using namespace std;

#define NAME_SIZE 32

enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

enum OUTPUT_TYPE
{
	OT_NONE,
	OT_OUTPUT,
	OT_INVERSE
};

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, * PSTUDENT;

typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;
}NODE, * PNODE;

typedef struct _tagList
{
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;

void InputString(char* pString, int iSize);
void InitList(PLIST pList);

void DestroyList(PLIST pList);

int InputInt();

int OutputMenu();
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);

void Push_Back(PLIST pList);
void Push_Front(PLIST pList);

void Search(PLIST pList);
void Delete(PLIST pList);