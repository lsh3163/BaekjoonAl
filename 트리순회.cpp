#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include <conio.h>
using namespace std;
int N;
//pair의 first엔 left,second엔 right 값을 저장할 vector node생성
vector<pair<int,int>> node;
//preorder 함수
void preorder(int now){
	//now가 0이란 말은 자식이 없다는 말이므로 함수 종료
	if (now == 0){
		return;
	}
	//now에 해당하는 영어 대문자 출력
	printf("%c", now - 1 + 'A');
	//preorder 순서에 따라 
	preorder(node[now].first);
	preorder(node[now].second);
	return;
}
void inorder(int now){
	if (now == 0){
		return;
	}
	inorder(node[now].first);
	printf("%c", now - 1 + 'A');
	inorder(node[now].second);
	return;
}
void postorder(int now){
	if (now == 0){
		return;
	}
	postorder(node[now].first);
	postorder(node[now].second);
	printf("%c", now - 1 + 'A');
	return;
}


int main(){
	cin >> N;
	node.resize(N + 1);
	for (int i = 1; i <= N; i++){
		char me, left, right;
		cin >> me; cin >> left; cin >> right;
		//left 와 right 가 0이 아니면 해당 영어 대문자를
		//숫자 index로 바꿔 다루기 쉽게 만듬
		if (left != '.'){
			node[me - 'A' + 1].first = left - 'A' + 1;
		}
		if (right != '.'){
			node[me - 'A' + 1].second = right - 'A' + 1;
		}
		//0이면 자식이 없음
		if (left == '.'){
			node[me - 'A' + 1].first = 0;
		}
		if (right == '.'){
			node[me - 'A' + 1].second = 0;
		}
	}
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);
	_getch();
}
