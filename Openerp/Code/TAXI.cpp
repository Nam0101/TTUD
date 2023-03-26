#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 20

int N;
int C[MAX + 1][MAX + 1];
int f = 0, f_min = 99999;
bool t[MAX + 1];
int x[MAX + 1];
int C_min = 99999;

void updateBest(){
//	for(int i = 0; i <= N; i++) cout << x[i] << " ";
//	cout << endl;
//	cout << "f = " << f << endl;
	f_min = min(f_min, f + C[x[N]][0]);
}

bool check(int k, int v){
	if(f >= f_min) return false;
	if(t[v] || !C[x[k - 1]][v]) return false;
	if(v > N / 2) return !t[v] && t[v - N / 2];
	else return true;
}

void TRY(int k){
	for(int v = 1; v <= N; v++){
		if(check(k, v)){
			x[k] = v;
			t[v] = true;
			f += C[x[k - 1]][v];
//			cout << k << "/" << v << "/" << f << endl;
			if(k == N) updateBest();
			else {
				if(f + C_min * (N - k + 1) < f_min)
					TRY(k + 1);
			}
			t[v] = false;
			f -= C[x[k - 1]][v];
		}
	}
}

void input(){
	cin >>N;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			cin >> C[i][j];
			if(C[i][j] && C[i][j] < C_min) C_min = C[i][j];
		}
	}
}

void input(char* filename){
	FILE* f = fopen(filename, "r");
	fscanf(f,"%d", &N);
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			fscanf(f, "%d", &C[i][j]);
			if(C[i][j] && C[i][j] < C_min) C_min = C[i][j];
		}
	}
	fclose(f);
}

void init(){
	x[0] = 0;
	for(int i = 0; i <= N; i++) t[i] = false;
}

int main(){
	input("taxi.txt");
	init();
	TRY(1);
	cout << f_min;
}
