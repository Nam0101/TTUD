// Linear Equation

#include <iostream>
using namespace std;

#define MAX 10

int n, M, a[MAX], x[MAX];
int res = 0; // numbers of solution
int t = 0;

void solution(){
	res++;
	for(int i = 0; i < n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

bool check(int v, int k){
	return k != n - 1 && t + a[k] * v < M || k == n - 1 && t + a[k] * v == M;
}

void TRY(int k){
	int v;
	for(v = 1; v <= (M - t) / a[k]; v++){
		if(check(v, k)){
			x[k] = v;
			t += a[k] * v;	// cap nhat gia tang
			if(k == n - 1) solution();
			else TRY(k + 1);
			t -= a[k] * v;	// khoi phuc khi backtrack
		}
	}
}

void input(){
	cin >> n >> M;
	for(int i = 0; i < n; i++){
		cin >> a[i];
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
