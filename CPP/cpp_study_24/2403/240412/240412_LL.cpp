#include <iostream>

using namespace std;

class CListNode
{
public:
	CListNode():
		m_pNext(NULL),
		m_pPrev(NULL)
	{

	}
	~CListNode()
	{

	}
public:
	int m_iData;
	CListNode* m_pNext;
	CListNode* m_pPrev;

};

class CList
{
public:
	CList()
	{
		m_pBegin = new CListNode;
		m_pEnd = new CListNode;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_isize = 0;
	}
	~CList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	}
private:
	CListNode* m_pBegin;
	CListNode* m_pEnd;
	int m_isize;
public:
	void push_back(int iData)
	{
		CListNode* pNode = new CListNode;

		pNode->m_iData = iData;

		CListNode* pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		m_isize++;
	}

	bool empty()
	{
		return m_isize == 0;
	}

	void clear()
	{
		CListNode* pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			CListNode* pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_isize = 0;
	}

	int pop_back()
	{
		CListNode* pPrev = m_pEnd->m_pPrev;

		if (pPrev == m_pBegin)
			return INT_MAX;

		int iData = pPrev->m_iData;

		CListNode* pPrevP = pPrev->m_pPrev;

		pPrevP->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrevP;

		m_isize--;

		delete pPrev;

		return iData;
	}
};

int main()
{
	CList list;

	for (int i = 0; i < 100; i++)
	{
		list.push_back(i);
	}

	while (!list.empty())
	{
		cout << list.pop_back() << endl;
	}

	return 0;
}