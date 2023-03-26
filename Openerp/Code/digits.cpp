#include <iostream>
using namespace std;

int N;
int t1[10];
int x[7];
int res = 0;

void solution(){
	int s = x[0] * 100 + x[1] * 10 + x[2] - x[6] * 100 - 62 + x[3] * 1000 + x[4] * 100 + x[5] * 10 + x[2];
	if(s == N) res++;
}

bool check(int v){
	return !t1[v];
}

void TRY(int k){
	for(int v = 1; v <= 9; v++){
		if(check(v)){
			x[k] = v;
			// cap nhat danh dau
			t1[v] = true;
			if(k == 6) solution();
			else TRY(k + 1);
			// khoi phuc danh dau
			t1[v] = false;
		}
	}
}

int main(){
	cin >> N;
	for(int i = 1; i < 10; i++) t1[i] = false;
	TRY(0);
	cout << res;
}
