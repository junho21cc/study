#pragma once


template <typename T>
class CVectorNode
{
public:
	CVectorNode()
	{

	}
	~CVectorNode()
	{

	}
private:
	template <typename T>
	friend class CVector;

private:
	T m_Data;
	int m_iIndex;
};


template <typename T>
class CVector
{
public:
	CVector()
	{
		m_iSize = 0;
		m_iCapasity = 2;

		m_pArray = new NODE[m_iCapasity + 2];
	}
	CVector(int iSize)
	{
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}
	~CVector()
	{
		delete[] m_pArray;
	}

private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize;
	unsigned int m_iCapasity;

public:
	void push_back(const T& data)
	{
		if (full())
			resize(m_iSize * 2);

		m_pArray[m_iSize + 1].m_Data = data;
		// 0번은 begin이다 그런데 실제1번 인덱스부터 노드가 추가되는데 처음 추가된 노드는 0번부터 인덱스를 주도록 한다
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		m_iSize++;
	}
	void resize(int iSize)
	{
		// +2를 하는 이유는 begin과 end노드를 포함시켜 생성 해주기 위해서다
		PNODE pArray = new NODE[iSize + 2];

		// 위에서 2배만큼 공간을 새로할당하고기존에 있는 노드의 데이터를 새로운 할당한 공간에복사해준다
		// 메모리 주소에 +1을 해준 이유는 1번 인덱스부터 시작이기 때문에 여기부터 복사를 해주기 위해서다
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize);

		delete[] m_pArray;
		m_pArray = pArray;

		m_iCapasity *= 2;
	}

	bool full()
	{
		return m_iSize == m_iCapasity;
	}

	bool empty()
	{
		return m_iSize == 0;
	}

	unsigned int size() const
	{
		return m_iSize;
	}
	unsigned int capasity() const
	{
		return m_iCapasity;
	}

	T operator [](int idx)
	{
		return m_pArray[idx + 1].m_Data;
	}

	void reserve(int iSize)
	{
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];

		m_iCapasity = iSize;
		m_iSize = 0;
	}
};
