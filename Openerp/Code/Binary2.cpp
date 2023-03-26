#include <iostream>
#define MAX 100
using namespace std;

int x[MAX];
int k, n;

void solution(){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << endl;
}

bool check(int v, int k){
	if(k == 1) return true;
	return !(v && x[k - 1] == 1);
}

void TRY(int k){
	int v;
	for(v = 0; v <= 1; v++){
		if(check(v, k)){
			x[k] = v;
			if(k == n) solution();
			else TRY(k + 1);
		}
	}
}

void input(){
	cin >> n;
}

int main(){
	input();
	TRY(1);
}
