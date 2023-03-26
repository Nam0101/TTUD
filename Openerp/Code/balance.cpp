#include <iostream>
using namespace std;

#define MAX 21

int n, b;
int a[MAX];
long long s = 0;
long long cnt = 0;

void TRY(int k){
	for(int v = 0; v <= 2; v++){
		s += (v - 1) * a[k];
		if(k == n) {
		    cnt += (s == b);
		}
		else TRY(k + 1);
		s -= (v - 1) * a[k];
	}
}

int main(){
	cin >> n >> b;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	s = 0;
	TRY(1);
	cout << cnt % 1000000007;
}
