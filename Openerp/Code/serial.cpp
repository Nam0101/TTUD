#include <iostream>
using namespace std;

#define MAX 100

int N;
int t = 0;
int x[MAX];

void solution(int k){
	if(t > N) return;
	for(int i = 0; i <= k; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

bool check(int v, int k){
	return t < N && v >= x[k - 1];
}

void TRY(int k){
	for(int v = 1; v <= N; v++){
		if(check(v, k)){
			x[k] = v;
			t += v;
			if(t >= N) solution(k);
			else
			TRY(k + 1);
			t -= v;
		}
	}
}

int main(){
	cin >> N;
	TRY(0);
}
