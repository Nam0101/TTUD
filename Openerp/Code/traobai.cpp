#include <iostream>
using namespace std;

#define MAX 100000

int n, x;
int a, b;
int m[MAX + 1];

void mySwap(int i, int j){
	if(i > j){
		int tmp = m[i];
		
	}
	else{
		
	}
}

int main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		m[i] = (i < n) ? i + 1 : 0;
	}
	for(int i = 1; i <= x; i++){
		cin >> a >> b;
		mySwap(a, b);
	}
}
