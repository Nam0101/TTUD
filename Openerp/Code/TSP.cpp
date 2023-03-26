// TSP
#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 20

int n, m;
int x[MAX]; // luu tru loi giai trong qua trinh duyet
int x_min[MAX]; // luu tru loi giai tot nhat
bool t[MAX + 1];
int cnt = 1;
int C[MAX + 1][MAX + 1];
int f = 0;
int f_min;
int C_min; // do dai chang nho nhat

void updateBest(){
	if(f + C[x[n]][x[1]] < f_min){
		f_min = f + C[x[n]][x[1]];
		for(int i = 1; i <= n; i++)
			x_min[i] = x[i];
	}
}

bool check(int v, int k){
	return !t[v] && C[x[k - 1]][x[k]] != -1;
}

void TRY(int k){
	int v;
	for(v = 1; v <= n; v++){
		if(check(v,k)){
			x[k] = v;
			t[v] = true;
			f += C[x[k - 1]][x[k]];
			if(k == n) updateBest();
			else {
				int g = f + C_min * (n - k + 1);
				if(g < f_min)
					TRY(k + 1);		
			}
			t[v] = false;
			f -= C[x[k - 1]][x[k]];
		}
	} 
}

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			C[i][j] = -1;	
		}
	}
	int i, j, c;
	for(int _i = 1; _i <= m; _i++){
		cin >> i >> j >> c;
		C[i][j] = c;
	}
}

void init(){
	for(int i = 1; i <= n; i++) t[i] = false;
	f_min = 99999;
	f = 0;
	x[1] = 1;
	t[1] = true;
}

void printSolution(){
	cout << f_min;	
}

int main(){
	input();
	init();
	TRY(2);
	printSolution();
}
