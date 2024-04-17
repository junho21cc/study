#pragma once

// cpp�� ����ü�� classó�� ����Ҽ��ֱ⶧���� �����ڿ� �Ҹ��ڸ� ����� �ִ�
template<typename T>
struct tListNode
{
	T				data;
	tListNode<T>*	pNext;
	tListNode<T>*	pPrev;

	tListNode()
		: data(), pNext(nullptr), pPrev(nullptr)
	{
	}
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data), pNext(_pNext), pPrev(_pPrev)
	{
	}
};

template<typename T>
class CList
{
private:
	tListNode<T>*	m_pHead;
	tListNode<T>*	m_pTail;
	int				m_iCount;
public:
	void push_back(const T& _data);
	void push_front(const T& _data);

public:
	CList();
	~CList();
};

template<typename T>
void CList<T>::push_back(const T& _data)
{
	// �Էµ� �����͸� ������ ��带 �����Ҵ� ��
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	// ó�� �Էµ� �����Ͷ��
	if (nullptr == m_pHead)
	{
		// this->�� ��������
		this->m_pHead = pNewNode;
		this->m_pTail = pNewNode;

	}
	else
	{
		// �����Ͱ� 1�� �̻󿡼� �Էµ� ���
		// ���� ���� ������ ������(tail)�� �����ϰ� �ִ� ��尡
		// ���� ������ ���� ���� ����Ű�� �Ѵ�
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		//List�� ������ ����� �ּҰ��� ���� �Էµ� ���� �����Ѵ�
		m_pTail = pNewNode;
	}

	//������ ���� ����
	m_iCount++;
}

template<typename T>
void CList<T>::push_front(const T& _data)
{
	// ���� ������ ����� ������ ���� ������� �ּҰ����� ä��
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	// ���� ������� ������� �ּҰ��� ���� ������ ����� �ּҷ� ä��
	m_pHead->pPrev = pNewNode;

	// ����Ʈ�� ���� ������ ��带 ���ο� ����ּҷ� �����Ѵ�
	m_pHead = pNewNode;

	//������ ���� ����
	m_iCount++;
}

template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{

}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeletNode = m_pHead;
	while (pDeletNode)
	{
		tListNode<T>* pNext = pDeletNode->pNext;
		delete(pDeletNode);
		pDeletNode = pNext;
	}
}