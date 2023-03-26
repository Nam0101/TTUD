#include <iostream>
using namespace std;

#define MAX 100

int N, S;
int t = 0;
int a[MAX], b[MAX];
int res = 0;

void solution(){
	if(t > S) return;
	res++;
}

bool check(int v, int k){
	return t <= S;
}

void TRY(int k){
	for(int v = k; v < N; v++){
		if(check(v, k)){
			t += a[v];
			if(t >= S) solution();
			else TRY(v + 1);
			t -= a[v];
		}
	}
}

int main(){
	cin >> N >> S;
	for(int i = 0; i < N; i++) cin >> a[i];
	TRY(0);
	cout << res;
}
