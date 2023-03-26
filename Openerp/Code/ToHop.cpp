#include <iostream>
#define MAX 1000
using namespace std;

long long M[MAX][MAX];

void init(){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			M[i][j] = -1;
		}
	}
}

long long C(int k, int n){
	if(k == 0 || k == n) M[k][n] = 1;
	else{
		if(M[k][n] == -1){
			M[k][n] = (C(k - 1, n - 1) + C(k, n - 1)) % 1000000007;
		}
	}
	return M[k][n];
}

int main(){
	init();
	long long k, n;
	cin >> k >> n;
	cout << C(k, n) % 1000000007;
}
