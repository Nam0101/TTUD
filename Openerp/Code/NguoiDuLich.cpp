// TSP
#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 100

int n, m;
int x[MAX]; // luu tru loi giai trong qua trinh duyet
int x_min[MAX]; // luu tru loi giai tot nhat
bool t[MAX + 1];
int cnt = 0;
int C[MAX + 1][MAX + 1];
int f = 0;
int f_min;
int C_min; // do dai chang nho nhat

void genData(char* fn, int n){
	FILE* f = fopen(fn, "w");
	fprintf(f, "%d\n", n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			if(i == j) x = 0;
			else x = rand() % 20 + 1;
			fprintf(f, "%d ", x);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}

void updateBest(){
	if(f + C[x[n]][x[1]] < f_min){
		f_min = f + C[x[n]][x[1]];
	}
	if(f + C[x[n]][x[1]] < m){
		cnt++;
	}
}

bool check(int v, int k){
	return !t[v];
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

void input(char* fn){
	FILE* f = fopen(fn, "r");
	fscanf(f, "%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			fscanf(f, "%d", &C[i][j]);
			if(C_min > C[i][j]) C_min = C[i][j]; // cap nhat do dai chang nho nhat
		}
	}
	fclose(f);
}

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> C[i][j];
			if(C_min > C[i][j]) C_min = C[i][j]; // cap nhat do dai chang nho nhat
		}
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
	cout << cnt;
}

int main(){
//	genData("TSP.txt", 20);
//	input("TSP.txt");
	input();
	init();
	TRY(2);
	printSolution();
}
