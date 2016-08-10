#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
vector<vector<int > > graph;
//1아니면 -1
int color[21212];
bool visited[21212];
bool bfs(int root){
	queue<int> q;
	q.push(root);
	visited[root] = true;
	color[root] = 1;
	while (!q.empty()){
		int n = q.front();
		int now_c = color[n];
		int next_c = -now_c;
		q.pop();
		int len = graph[n].size();
		for (int i = 0; i < len; i++){
			//방문한 적이 없으면
			if (!visited[graph[n][i]]){
				visited[graph[n][i]] = true;
				q.push(graph[n][i]);
				color[graph[n][i]] = next_c;
			}
			//방문한 적이 있고 현재 색깔과 다음에 칠할 색깔이 같으면 false
			if ((color[graph[n][i]] == now_c) && visited[graph[n][i]]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		//정점의 개수 ,간선의 개수
		int V, E;
		cin >> V; cin >> E;
		//그래프 초기화
		graph.clear();
		//정점 1~V까지 쓸것이므로
		graph.resize(V + 1);
		//간선의 개수만큼 입력을 받음
		for (int i = 0; i < E; i++){
			int u, v;
			cin >> u; cin >> v;
			//양 방향이므로
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 0; i < 21212; i++){
			//방문한 적이 없으므로 0으로 초기화
			color[i] = 0;
			visited[i] = false;
		}
		bool answer = true;
		for (int i = 1; i <= V; i++){
			if (!visited[i]){
				//한 그래프에 대하여 하나라도 이분그래프가 아니면 
				//이분 그래프가 아니므로
				answer &= bfs(i);
			}
		}
		if (answer){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
