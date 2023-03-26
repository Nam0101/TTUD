// Sudoku 2

#include <iostream>
using namespace std;

int mat[9][9], t[9][9], cnt = 0;
bool t1[9][9], t2[9][9], t3[9][9];

void input(){
	FILE* f;
	f = fopen("sudoku.txt", "r");
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			fscanf(f,"%d", &mat[i][j]);
			if(mat[i][j]){
				t1[i][mat[i][j] - 1] = true;
				t2[j][mat[i][j] - 1] = true;
				t3[3 * (i / 3) + (j / 3)][mat[i][j] - 1] = true;	
			}
		}
	}
}

void init(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			t1[i][j] = false;
			t2[i][j] = false;
			t3[i][j] = false;
		}
	}
}

void solution(){
	cnt++;
	cout << cnt << "." << endl;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;
}

bool check(int v, int x, int y){
	return !t1[x][v - 1] && !t2[y][v - 1] && !t3[3 * (x / 3) + (y / 3)][v - 1];
}

void TRY(int x, int y){
	if(mat[x][y] != 0){
		t[x][y] = mat[x][y];
		if(x == 8 && y == 8) solution();
		else{
			if(y < 8) TRY(x, y + 1);
			else TRY(x + 1, 0);
		}
	}
	else
	for(int v = 1; v <= 9; v++){
		if(check(v, x, y)){
			t[x][y] = v;
			t1[x][v - 1] = true;
			t2[y][v - 1] = true;
			t3[3 * (x / 3) + (y / 3)][v - 1] = true;
			if(x == 8 && y == 8) solution();
			else{
				if(y < 8) TRY(x, y + 1);
				else TRY(x + 1, 0);
			}
			t1[x][v - 1] = false;
			t2[y][v - 1] = false;
			t3[3 * (x / 3) + (y / 3)][v - 1] = false;
		}
	}
}

int main(){
	init();
	input();
	TRY(0, 0);
}
