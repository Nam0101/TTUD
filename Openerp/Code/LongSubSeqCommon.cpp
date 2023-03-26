#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100

int m[MAX + 1][MAX + 1];
int n1, n2;
int a[MAX + 1], b[MAX + 1];

void init(){
	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= n2; j++){
			m[i][j] = 0;
		}
	}
}

void input(){
	cin >> n1;
	for(int i = 1; i <= n1; i++) cin >> a[i];
	cin >> n2;
	for(int i = 1; i <= n2; i++) cin >> b[i];
	init();
}

void input2(){
	FILE* f = fopen("LSC.txt", "r");
	fscanf(f, "%d", &n1);
	for(int i = 1; i <= n1; i++) fscanf(f, "%d", &a[i]);
	fscanf(f, "%d", &n2);
	for(int i = 1; i <= n2; i++) fscanf(f, "%d", &b[i]);
	init();
}

int main(){
	input2();
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			m[i][j] = max(m[i - 1][j], m[i][j - 1]);
			if(a[i] == b[j]) {
				m[i][j] = m[i - 1][j - 1] + 1;
			}
			else{
				m[i][j] = max(m[i][j - 1], m[i - 1][j]);
			}
		}
	}
	cout << "m = \n";
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << m[n1][n2];
}
