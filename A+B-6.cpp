#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void){
	int T;
	cin >> T;
	while (T--){
		//a,b를 문자열로 입력을 받은뒤
		//a와 b는 0~9이므로 한자리수인거 보장
		string s;
		cin >> s;
		//s[1]이 콤마이므로
		int answer = (s[0] - '0') + (s[2] - '0');
		printf("%d\n", answer);
	}
}
