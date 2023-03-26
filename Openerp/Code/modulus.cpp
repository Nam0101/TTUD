#include <iostream>
using namespace std;
#define P 1000000007

int addmod(int a, int b){
	a %= P;
	b %= P;
	int z = P - a;
	if(z > b) return a + b;
	return b - z;
}

int mulmod(int a, int b){
	a %= P;
	b %= P;
	if(a == 1) return b;
	if(b == 1) return a;
	int c = 0;
	if(a > b){
		int t = a;
		a = b;
		b = a;
	}
	c = mulmod(a, b / 2);
	c = addmod(c, c);
	if(b % 2 == 0) return addmod(c, c);
	return addmod(a, c);
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << mulmod(a, b);
}
