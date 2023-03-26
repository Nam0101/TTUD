#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 100

int n;
int x[MAX]; // map 1 tho va 1 cong viec
int x_min[MAX];
bool t1[MAX], t2[MAX]; // danh dau
int f;
int f_min;
int C[MAX][MAX];
int C_min;

void genData(char* fn, int n){
	FILE* f = fopen(fn, "w");
	fprintf(f, "%d\n", n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			x = rand() % 20 + 1;
			fprintf(f, "%d ", x);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}

void input(char* fn){
	FILE* f = fopen(fn, "r");
	fscanf(f, "%d", &n);
	C_min = 99999;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fscanf(f, "%d", &C[i][j]);
			if(C_min > C[i][j]) C_min = C[i][j];	// cap nhat gia nho nhat
		}
	}
}

void init(){
	for(int i = 0; i < n; i++){
		t1[i] = false;
		t2[i] = false;
	}	
	f = 0;
	f_min = 999999;
}

void update(){
	if(f < f_min){
		f_min = f;
		for(int i = 0; i < n; i++)
			x_min[i] = x[i];
		cout << "Min = " << f_min << endl;
	}
}

void TRY(int k){
	for(int v = 0; v < n; v++){
		if(!t1[k] && !t2[v]){
			x[k] = v;
			t1[k] = true;
			t2[v] = true;
			f+= C[k][v];
			if(k == n - 1){
				update();
			} 				
			else{
				if(f + C_min * (n - k - 1) < f_min)
					TRY(k + 1);
			}		
			t1[k] = false;
			t2[v] = false;
			f -= C[k][v];
		}
	}
}

void solution(){
	for(int i = 0; i < n; i++){
		cout << i + 1 << "->" << x_min[i] + 1 << " ";
	}
	cout << endl;
}

int main(){
	genData("PhancongCV.txt", 20);
	input("PhancongCV.txt");
	init();
	TRY(0);
	solution();
}
