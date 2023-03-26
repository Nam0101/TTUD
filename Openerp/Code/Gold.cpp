#include <iostream>
using namespace std;

#define MAX 100000

int n, L1, L2;
int a[MAX];
int s[MAX];
int res;

void input(){
	cin >> n >> L1 >> L2;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s[i] = 0;
	}
	res = 0;
}

int main(){
	input();
	for(int i = 0; i < n; i++){
		for(int j = L1; j <= L2; j++){
			int sj = 0;
			if(i - j >= 0){
				sj = s[i - j];
			}
			s[i] = max(s[i], sj + a[i]);
		}
		res = max(res, s[i]);	
	}	
	cout << res << endl;	
}
