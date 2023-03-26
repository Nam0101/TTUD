// Linear Equation

#include <iostream>
using namespace std;

#define MAX 10

int n, M, a[MAX], x[MAX];
int res = 0; // numbers of solution
int s;
int t = 0;

void solution(){
	res++;
}

bool check(int v, int k){
	s = 0;
	for(int i = 0; i < k; i++)
		s += a[i] * x[i];
	s += a[k] * v;
	return k != n - 1 && s < M || k == n - 1 && s == M;
}

void TRY(int k){
	int v;
	for(v = 1; v <= M / a[k]; v++){
		if(check(v, k)){
			x[k] = v;
			if(k == n - 1) solution();
			else TRY(k + 1);
		}
	}
}

void input(){
	cin >> n >> M;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		t += a[i];
	}
}

void output(){
	cout << res;
}

int main(){
	input();
	TRY(0);
	output();
}
