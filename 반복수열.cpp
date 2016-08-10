#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int A, P;
//9^5*5<10^6이므로 visited 배열을 이렇게 잡자.
int visited[1231231];
int bfs(int root){
	int cnt = 1;
	//visited 배열은 방문 한적 있으면 cnot,없으면 0
	visited[root] = cnt;
	//숫자,횟수
	queue<pair<int, int> > q;
	q.push(make_pair(root, cnt));
	while (!q.empty()){
		int now = q.front().first;
		int count = q.front().second;
		q.pop();
		int n = now;
		//다음 들어갈 next를 만들어 주고
		int next = 0;
		while (n > 0){
			int a = n % 10;
			int b = 1;
			for (int i = 0; i < P; i++){
				b *= a;
			}
			next += b;
			n /= 10;
		}
		//방문한 적이 없으면 연산 횟수를 1추가해서 큐에다가 넣고
		if (visited[next] == 0){
			visited[next] = count + 1;
			q.push(make_pair(next, count + 1));
		}
		//있으면 원래 거기 들어있던 연산횟수 -1출력
		else if (visited[next] > 0){
			return visited[next] - 1;
		}
	}
}
int main(void){
	cin >> A; cin >> P;
	int answer = bfs(A);
	printf("%d", answer);
}
