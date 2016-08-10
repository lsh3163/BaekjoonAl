#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
//부모 번호를 저장할 parent 배열 선언
int parent[100001];
//방문여부를 판단하는 visited 배열 선언
bool visited[100001];
//인접 리스트 생성
vector<vector<int> > graph;
//bfs 함수=>각 정점에서 갈 수 있는 정점을 탐색하면서
//parent 배열에 부모를 저장
void bfs(int root){
	queue<int> q;
	visited[root] = true;
	q.push(root);
	parent[root] = 0;

	//bfs탐색
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			//now행에 있는 다음 갈 수 있는 정점들 중
			int there = graph[now][i];
			//방문한 적이 없다면
			if (!visited[there]){
				//큐에 넣고 탐색
				visited[there] = true;
				q.push(there);
				//부모 배열에 저장
				parent[there] = now;
			}
		
		}
	}

}
int main(){
	cin >> N;
	graph.resize(N + 1);
	for (int i = 1; i <= N - 1; i++){
		int u, v;
		cin >> u; cin >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(1);
	for (int i = 2; i <= N; i++){
		printf("%d\n", parent[i]);
	}
}
