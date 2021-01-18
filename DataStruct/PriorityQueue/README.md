# Heap
* 우선순위 큐: 가장 우선순위가 높은 원소가 가장 먼저 제거되는 큐

## 히입(Heap)이란?
->이진트리를 기반으로 구현된 우선순위큐

->완전이진트리

## 히입(Heap)의 종류
->최대 히입: 모든 노드의 값은 자식 노드의 값보다 작지 않음(크거나 같음)

->최소 히입: 모든 노드의 값은 자식 노드의 값보다 크지 않음(작거나 같음)

경우에 따라서 큰값이 높은 우선순위일 수도 있고, 작은값이 높은 우선순위일 수도 있다.

    자료구조: 자료(를) 효율(적으로) 관리(하는) 기법

## 우선순위큐의 연산

    추가: 새로운 원소의 위치는 그 중요도에 따라서 결정됨

    제가: 가장 우선 순위가 높은 원소 삭제

    탑: 큐에서 가장 우선순위가 높은 원소를 찾음


## 히입(Heap)의 구현
완전이진트리에서 각 노드에 위에서 아래로,

왼쪽에서 오른쪽으로 번호를 부여

배열에서 첫 번째 원소부터 번호를 부여

    K번째 노드의 부모 노드 = K/2(버림)
    K번째 노드의 LeftChildNode = 2*K
    K번째 노드의 LeftChildNode = 2*K + 1

배열의 index를 통해서 Heapify를 해준다.

하향식 재구성: root부터 leaf까지

상향식 재구성: leaf부터 root까지

## 힙의 연산

### 추가
최대 힙에 새로운 원소(노드)를 추가 // 완전이진트리라는 조건

1. 원소를 힙의 마지막위치에 삽입

2. 힙화(Heapify)를 통해서 새로운 원소가 삽입된 힙을 재구성

	ex) 최대힙, 바텀업

추가된 Node는 ChildNode다.

'''

	void HeapifyBottomUp(Heap* H->UsedSize)
	{
		int Child_Index = H->UsedSize;
		int Parent_Index = Child_Index /= 2;
		while(H->Nodes[Child_Index].Data > H->Nodes[Parent_Index].Data)
		{
			SwapNodes(&H->Nodes[Child_Index], &H->Nodes[Parent_Index]);
			Child_Index /= 2;
			Parent_Index /= 2;
		}
	}
'''

### 제거

최대 힙에서 Root Node 제거 or Top을 제거

(완전이진트리이기 때문에) 마지막노드 제거

	1. Root Node에 저장된 값을 제거
	2. 힙의 마지막 노드에 저장된 값을 루트 노드로 옮기고 옮긴 노드를 제거
	3. 루트 노드로부터 하향식 힙 재구성 수행

힙에서는 내가 제거할 원소를 지정하지 않는다

단지 루트 노드에 있는 값 또는 리프노드에 있는값을 제거한다.