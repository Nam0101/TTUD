#include <iostream>
using namespace std;

#define MAX 1000

int n;
long long a[MAX], b[MAX];
int res = 0;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for(int i = 0; i < n; i++){
		bool flag = true;
		for(int j = 0; j < n; j++){
			if(a[j] > a[i] && b[j] > b[i]) {
				flag = false;
				break;
			}
		}
		if(flag) res++;
	}
	cout << res;
}
