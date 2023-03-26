#include <iostream>
#define MAX 10000
using namespace std;

int x[MAX];
int N, I, K;
int cnt = 0;
int t = 0;

void solution(){
	for(int i = 0; i < N; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

bool check(int v, int k){
	return v == 1 || t < I - 1;
}

void TRY(int k){
	if(cnt > K) return;
	for(int v = 0; v <= 1; v++){
		if(check(v, k)){
			x[k] = v;
			t = v ? 0 : t + 1;
			if(k == N - 1){
			    cnt++;
			    if(cnt == K) solution();
			}
			else TRY(k + 1);
		}
	}
}

void input(){
	cin >> N >> K >> I; 
}

int main(){
	input();
	TRY(0);
	if(cnt < K) cout << -1;
}
