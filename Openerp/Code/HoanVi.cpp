// So hoan vi
#include <iostream>
using namespace std;

#define MAX 20

int n, x[MAX], t[MAX + 1];
int cnt = 1;

void solution(){
	cout << cnt << ". ";
	for(int i = 0; i < n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
	cnt++;
}

bool check(int v, int k){
	return t[v] == 0;
}

void TRY(int k){
	int v;
	for(v = 1; v <= n; v++){
		if(check(v,k)){
			x[k] = v;
			t[v] = 1;
			if(k == n - 1) solution();
			else TRY(k + 1);	
			t[v] = 0;
		}
	} 
}

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++) t[i] = 0;
}

int main(){
	input();
	TRY(0);
}
