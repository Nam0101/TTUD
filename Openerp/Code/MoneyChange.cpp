#include <iostream>
using namespace std;

int main(){
	int m, res = 0;
	int c[] = {500, 100, 50, 10, 5, 1};
	cin >> m;
	m = 1000 - m;
	for(int i = 0; i < 6; i++){
		res += m / c[i];
		m %= c[i];
	}
	cout << res;
}
