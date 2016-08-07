#include <stdio.h>
#include <iostream>

using namespace std;
//TestCase가 정해지지 않았으므로 아래 형식으로 입력을 받음
int main(void){
	int a, b;
	while (cin >> a >> b){
		printf("%d\n", a + b);
	}
}
