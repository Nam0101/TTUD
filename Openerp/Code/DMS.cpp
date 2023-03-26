#include <iostream>
using namespace std;

#define MAX 100

int n, m;
int a[MAX], x[MAX];
int t = 0;
int res = 0;

void solution(){
	res++;
}

bool check(int v, int k){
	return k != n - 1 && t + a[k] * v < m || k == n - 1 && t + a[k] * v == m;
}

void TRY(int k){
	int v;
	for(v = 1; v <= (m - t) / a[k]; v++){
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
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
	input();
	TRY(0);
	cout << res;
}
