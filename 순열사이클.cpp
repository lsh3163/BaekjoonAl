#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <conio.h>
using namespace std;

//똑같은 dfs
int N;
vector<vector<int > > graph;
bool visited[1001];
void dfs(int n){
	visited[n] = true;
	int len = graph[n].size();
	for (int i = 0; i < len; i++){
		int there = graph[n][i];
		if (!visited[there]){
			dfs(there);
		}
	}
}
int main(void){
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		//visited배열 초기화
		memset(visited, false, sizeof(visited));
		//graph 초기화
		graph.clear();
		graph.resize(N + 1);
		for (int i = 1; i <= N; i++){
			int input;
			cin >> input;
			graph[i].push_back(input);
		}
		//연결요소의 개수를 구해주면 됩니다.
		int cnt = 0;
		for (int i = 1; i <= N; i++){
			if (!visited[i]){
				cnt++;
				dfs(i);
			}
		}
		printf("%d\n", cnt);
	}
}
