# 이진 탐색 트리

이진 탐색: 배열의 중앙값을 찾아서 배열을 반으로 분할하는 과정을 재귀함수로 반복한다.

이진 탐색 트리 정의
1. 이진트리
2. 모든 노드는 서로 다른 하나의 Data를 저장
3. root->left < root
4. root->right > root

## 이진 탐색 트리 연산
root node를 선언

원소가 없는 이진 탐색 트리는 root node의 Data를 원소로 사용되지 않을 값으로 초기화

* 검색
* 추가
 * 질문_1: 시간 복잡도는 프로그래밍의 효율적인 문제이기때문에 사용하는건가?
* 질문_2: 메모리를 새로 할당받아서 연결하는 과정은 root를 변경하는 과정이기때문에 파라미터를 BTNode** root라고 해야되는것이 아닌가?
* 질문_3: C++에서 root->left->insert(root, InsertData)는 어떤 의미를 갖는가


### 삭제
* 노드가 child를 갖고있는지를 판단하고 삭제한다.
* child가 없다면 그냥 삭제
* child가 1개 있다면 child의 subtree를 올려준다.
* child가 2개 있다면 left child의 최대값 또는 right child의 최솟값을 올려준다. 
* 

## 균형 이진 탐색 트리
Balanced Binary Serach Tree
AVL tree
Red-black tree
2-3 tree
B+ tree
