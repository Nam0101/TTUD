#include <iostream>
using namespace std;

#define MAX 10000
#define P 1000000007

int N;
int a[MAX];
long long Q = 0;

void input(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
}

int main(){
	input();
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			if(a[i] < a[j]) Q++;
		}
	}
	cout << Q % P;
}
