# 그래프
node(vertex)와 edge(link)로 이루어져있음

## 그래프의 종류

node에 가중치가 존재하는지

edge에 방향성이 존재하는지 따라서 나뉜다

## 특별한그래프
self edge를 가진 그래프

multi edge를 가진 그래프


## 복잡도에 따른 그래프(edge에 따른 그래프)

#### 1. 완전 그래프

    n개의 vertex들이 서로 연결된 그래프
    하나의  vertex가 n-1개의 vertex와 연결
    edge의 수: n(n-1)/2
    방향 그래프의 경우는 n(n-1)개의 edge 를 가짐

#### 2. 밀집 그래프

    n개의 vertex들의 대부분이 서로 연결된 그래프
    Edge의 수: O(n^2)
    방향 그래프의 경우에도 O(n^2)개의 edge를 가짐

#### 3. 희소 그래프

각 vertex 들이 상수 개의 vertex와 연결된 그래프
한 vertex에서 연결된 vertex의 수: O(1)
edge의 수: O(n)

## 그래프의 기본 용어

#### Vertex
하나의 개체를 표현

원 내부의 숫자나 문자로 표현

#### Edge
    vertex와 vertex의 1대1 관계를 나타냄
    vertex의 쌍으로 표현: (0, 1)
    방향성이 있는 관계: (0, 1) != (1, 0)
    방향성이 없는 관계: {0, 1} = {1, 0}

#### Adjacent & Incident
    vetex u와 v가 edge로 연결되어 있다면
    u와 v는 인접해 있다.(adjacent)
    두 edge가 같은 vertex를 공유하고 있다면
    두 edge는 인접해있다.(incident)

#### 부분 그래프

#### 경로(Path)
    1. vertex u에서 vertex v로 가는 경로는 vertex들의 연속체임
    2. 여러 개의 경로가 존재할 수 있음
    3. 경로의 길이
    경로에 있는 vertex 또는 edge의 수
    가중치 graph의 경우
    경로에 있는 edge의 가중치의 합
    4. 단순경로
    시작 vertex와 끝 vertex를 제외한 모든 vertex가 서로 다른 경로

#### 순환
    첫번째 vertex와 마지막 vertex가 일치하는 경로

#### 비순환 그래프
    순환이 존재하지 않는 그래프

#### 연결
    1. vertex u와 v사이에 경로가 존재할때 연결되있다고 한다.
    2. 어떤 그래프에 속한 모든 vertex들이 연결되었을 때 이 그래프는 연결되었다고 함
    3. 연결 성분: 연결된 부분 그래프의 최대치
    4. 트리는 연결된 비순환 그래프
    5. 방향 그래프에서는 경로가 방향성이 추가되기 때문에 강한 연결이라고 한다.
       서로 오고가는 edge가 있어야 연결되있다고 한다.

#### vertex의 차수(Degree)
vertex에 연결된 edge의 수

#### 신장 트리

## 그래프의 구현

#### 1. Edge 리스트
    그래프의 edge의 리스트를 제시함
    인접 행렬-매트릭스
    무방향 그래프 ->(대칭 행렬)
    n*n array

#### 2. 인접 리스트
    n개의 연결 리스트

## 그래프의 연산
    1. DFS
    2. BFS
    3. Greedy 

## 그래프의 시각화
[graphviz](https://dreampuf.github.io/GraphvizOnline/)
: 그래프를 보여준다.

내가 만든 방향성이 있는 그래프: [그래프](https://bit.ly/3sB0vTF)
내가 만든 방향성이 없는 그래프: [그래프](https://bit.ly/39I3hOn)



