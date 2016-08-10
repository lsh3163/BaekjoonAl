#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
//정점의 개수 와 간선의 개수
int N, M;
//시작 번호
int start;
//1~1000번 까지 방문여부를 판단할 배열
bool visited[1001];
//인접리스트 생성
vector<vector<int> > graph;
void dfs(int n){
	//현재 정점은 이 함수 호출과 동시에 방문한 것
	visited[n] = true;
	//그리고 그 방문한 점 출력
	printf("%d ", n);
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
//bfs는 dfs와 달리 while문안에서 탐색이 이루어짐
//고로 root
void bfs(int root){
	//탐색에 필요한 queue선언
	queue<int> q;
	//시작 정점 방문했다고 합시다
	visited[root] = true;
	//root에 연결된 점들 탐색을 위해서 큐에 넣고
	q.push(root);
	//queue가 빌 때까지 탐색
	while (!q.empty()){
		//front에서 현재정점 가지고 옴
		int now = q.front();
		//그 현재 정점들을 출력시켜주면 됨
		printf("%d ", now);
		q.pop();
		int len = graph[now].size();
		//now행에 있는 그 정점들을 보면서
		for (int i = 0; i < len; i++){
			//다음 후보 정점들 가지고 옴
			int next = graph[now][i];
			if (!visited[next]){
				//다음 정점 방문했다 해주고
				visited[next] = true;
				//다음 정점을 또 큐 맨 위에 쌓아줍니다.
				q.push(next);
			}
		}
	}
}
int main(void){
	cin >> N; cin >> M;
	cin >> start;
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
	//문제 조건에 따라 작은 번호부터 탐색해야하므로 sort
	for (int i = 1; i <= N; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(start);
	//다시 bfs해야 하므로 visited를 재활용 하기 위해 초기화
	memset(visited, false, N + 1);
	printf("\n");
	bfs(start);
}
