#include <iostream>
using namespace std;

#define MAX1 100
#define MAX2 500
int n, M;
int a[MAX1 + 1];
int b[MAX1 + 1];
unsigned long long m[MAX1 + 1][MAX2 + 1];

void input(){
	cin >> n >> M;
	b[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}
}

int main(){
	input();
	for(int q = 1; q <= M; q++){
		if(q % a[1] == 0) m[1][q] = 1;
		else m[1][q] = 0;
	}
	for(int i = 2; i<= n; i++){
		for(int q = 1; q <= M; q++){
			int bnd = (q - b[i - 1]) / a[i];
			unsigned long long cnt = 0;
			for(int v = 1; v <= bnd; v++){
				cnt += m[i - 1][q - a[i] * v];
			}
			m[i][q] = cnt % 1000000007;
		}
	}
	cout << m[n][M];
}
