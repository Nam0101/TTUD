#include <iostream>
using namespace std;

#define MAX 1000000

int n;
int tmp = 0, m = 0;
int a[MAX];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		tmp += a[i];
		if(tmp < 0) tmp = 0;
		if(m < tmp) m = tmp;
	}
	cout << m;
}
