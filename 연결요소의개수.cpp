#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//정점의 개수 와 간선의 개수
int N, M;
//1~1000번 까지 방문여부를 판단할 배열
bool visited[1001];
//인접리스트 생성
vector<vector<int> > graph;
void dfs(int n){
	//현재 정점은 이 함수 호출과 동시에 방문한 것
	visited[n] = true;
	int len = graph[n].size();
	//이 행에 연결된 점들을 for문을 보면서
	for (int i = 0; i < len; i++){
		int there = graph[n][i];
		//방문한 적이 없다면
		if (!visited[there]){
			//그 점으로 ㄱㄱ씽
			dfs(there);
		}
	}
}
int main(void){
	cin >> N; cin >> M;
	//1~N까지 쓸것이므로
	graph.resize(N + 1);
	//간선의 개수 M만큼 연결된 두 정점 입력 받음
	while (M--){
		int u, v;
		cin >> u; cin >> v;
		//양 방향이므로
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	//연결요소를 셀 변수 cnt
	int cnt = 0;
	//1번 부터 N번까지 돌면서
	//방문하지 않은 점들에 대하여
	//탐색 시작 및 연결요소 개수 1추가
	//방문했다는 것은 전 탐색에 의하여 연결되어 있다는 뜻
	for (int i = 1; i <= N; i++){
		if (!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}
