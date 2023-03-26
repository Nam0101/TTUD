#include <iostream>
using namespace std;

#define MAX 100000

int n;
int a[MAX];
int S[MAX];
int res = -99999;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	//
	S[0] = 1;
	for(int i = 1; i < n; i++){
		S[i] = 1;
		for(int j = 0 ; j < i; j++){
			if(a[j] < a[i]){
				if(S[i] < S[j] + 1) S[i] = S[j] + 1;
			}
		}
		if(res < S[i]) res = S[i];
	}
	cout << res;
}
