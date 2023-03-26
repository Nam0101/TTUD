#include <iostream>
using namespace std;

#define MAX 10000
#define P 1000000007

int N, M;
int a[MAX + 1];
long long Q = 0;
int _min[MAX + 1], _max[MAX + 1];

void input(){
	cin >> N >> M;
	_min[0] = 99999; _max[0] = -99999;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		_min[i] = min(_min[i - 1], a[i]);
		_max[i] = max(_max[i - 1], a[i]);
	}
}

int main(){
	input();
	for(int i = N; i >= 1; i--){
		if(a[i] + 2 * _min[i] > M || a[i] + 2 * _max[i] < M) continue;
		for(int j = i - 1; j >= 1; j--){
			int tmp = a[i] + a[j];
			if(tmp + _min[i] > M || tmp + _max[i] < M) continue;
			for(int k = j - 1; k >= 1; k--){
				if(a[i] + a[j] + a[k] == M) Q++;
			}
		}
	}
	cout << Q % P;
}
