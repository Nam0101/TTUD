// So hoan vi
#include <iostream>
using namespace std;

#define MAX 20

int n, K, x[MAX], t[MAX + 1];
int cnt = 0;

void solution(){
	for(int i = 0; i < n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

bool check(int v, int k){
	return t[v] == 0;
}

void TRY(int k){
	if(cnt > K) return;
	for(int v = 1; v <= n; v++){
		if(check(v,k)){
			x[k] = v;
			t[v] = 1;
			if(k == n - 1) {
				cnt++;
				if(cnt == K) solution();
			}
			else TRY(k + 1);	
			t[v] = 0;
		}
	} 
}

void input(){
	cin >> n >> K;
	for(int i = 1; i <= n; i++) t[i] = 0;
}

int main(){
	input();
	TRY(0);
	if(cnt < K) cout << -1;
}
