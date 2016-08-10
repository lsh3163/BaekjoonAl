#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int N;
//first엔 번호 ,second엔 가중치
vector<vector<pair<int, int> > > graph;
//방문여부 확인 배열
bool visited[100001];
pair<int, int> further(int root){
	queue<pair<int, int> > q;
	q.push(make_pair(root, 0));
	visited[root] = true;
	pair<int, int> ret;
	ret.first = -1;
	ret.second = -1;
	//bfs탐색
	while (!q.empty()){
		//큐에 front에서 현재 정점과 현재까지 거리의 합 불러옴
		int now = q.front().first;
		int distance = q.front().second;
		q.pop();
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			//저장할 때first에 정점 저장 했으므로
			int next = graph[now][i].first;
			//현재 거리에 다음 정점까지의 거리를 더한게 
			//다음 큐 쌍에 넣을 것
			int nextD = distance + graph[now][i].second;
			if (!visited[next]){
				visited[next] = true;
				q.push(make_pair(next, nextD));
				//ret보다 nextD가 더 크면
				if (nextD > ret.second){
					//계속 거리 큰거의 정점과 거리를 ret에 저장
					ret.first = next;
					ret.second = nextD;
				}
			}
		}
	}
	return ret;
}
int main(){
	cin >> N;
	graph.resize(N + 1);
	for (int i = 1; i <= N;i++){
		//정점 번호 u
		//v,x를 입력받음
		int u, v, x;
		cin >> u;
		while (true){
			cin >> v;
			if (v == -1){
				break;
			}
			cin >> x;
			graph[u].push_back(make_pair(v, x));
			graph[v].push_back(make_pair(u, x));
		}
	}
	//1에서 제일 먼 점과 그 거리를 저장
	pair<int, int> result = further(1);
	int point = result.first;
	memset(visited, false, N + 1);
	//그 먼점에서 가장 먼 점과 그 거리를 저장=> 답
	pair<int, int> result2 = further(point);
	int answer = result2.second;
	printf("%d", answer);
}
