#include <iostream>
using namespace std;

#define MAX 10000
#define P 1000000007

int N, M;
int a[MAX + 1];
long long Q = 0;
int t2[10000][10000];

void init(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			t2[i][j] = 0;
		}
	}
}

void input(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
	}
}

int main(){
	input();
	init();
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			t2[i][a[i] + a[j]]++;
		}
	}
	for(int i = 0; i < N; i++){
		Q += t2[i + 1][M - a[i]];
	}
	cout << Q % P;
}
