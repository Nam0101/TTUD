#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000

int n;
vector<int> A[MAX + 1];
long long cnt = 0;

void input(){
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}

void find(bool* t, int& cnt){
	
}

int dist(int i, int j){
	bool* t = new bool[n + 1];
	for(int i = 1; i <= n; i++) t[i] = false;
	
}

void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			cnt += dist(i, j);
		}
	}
}

int main(){
	input();
	solve();
	cout << cnt;
}
