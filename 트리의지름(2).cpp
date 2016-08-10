#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
vector<vector<pair<int, int > > > graph;
bool visited[12345];
pair<int, int>furthest(int root){
	memset(visited, false, 12345);
	queue<pair<int, int > > q;
	visited[root] = true;
	q.push(make_pair(root, 0));
	pair<int, int > ret;
	ret.first = -1;
	ret.second = -1;
	while (!q.empty()){
		int now = q.front().first;
		int dis = q.front().second;
		int len = graph[now].size();
		q.pop();
		for (int i = 0; i < len; i++){
			if (!visited[graph[now][i].first]){
				visited[graph[now][i].first] = true;
				q.push(make_pair(graph[now][i].first, dis + graph[now][i].second));
				if (dis + graph[now][i].second>ret.second){
					ret.first = graph[now][i].first;
					ret.second = dis + graph[now][i].second;
				}
			}
		}
	
	}
	return ret;
}
int main(){
	int n;
	cin >> n;
	graph.resize(n + 1);
	n--;
	while (n--){
		int u, v, x;
		cin >> u; cin >> v; cin >> x;
		graph[u].push_back(make_pair(v, x));
		graph[v].push_back(make_pair(u, x));
	}
	pair<int, int > first = furthest(1);
	pair<int, int > answer = furthest(first.first);
	printf("%d", answer.second);
}
