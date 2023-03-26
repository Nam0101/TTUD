#include <iostream>
using namespace std;

#define P 1000000007

int addmod(int a, int b){
	a %= P;
	b %= P;
	int c = P - a;
	if(b < c) return a + b;
	return b - c;
}

int mulmod(int a, int b){
	if(b == 1) return a % P;
	if(b % 2){
		int c = mulmod(a, b / 2);
		c = addmod(c, c);
		return addmod(c, a);
	}
	else{
		int c = mulmod(a, b / 2);
		return addmod(c, c);
	}
}

int expmod(int a, int b){
	int c = 1;
	for(int i = 1; i <= b / 2; i++){
		c = mulmod(c, a);
	}
	c = mulmod(c, c);
	if(b % 2) c = mulmod(c, a);
	return c;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << expmod(a, b);
}
