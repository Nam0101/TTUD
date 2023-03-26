// Sudoku 2

#include <iostream>
#include <windows.h>
using namespace std;

int mat[9][9], t[9][9], cnt = 0;
bool t1[9][9], t2[9][9], t3[9][9];
HANDLE hConsoleColor;

void init(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			t1[i][j] = false;
			t2[i][j] = false;
			t3[i][j] = false;
		}
	}
   hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
   system("color f0");
   system("title Sudoku");
   SetConsoleTextAttribute(hConsoleColor, 0xf0);
}

void solution(){
	cnt++;
	cout << cnt << "." << endl;
	cout << (char)218;
	for(int i = 0; i < 2; i++) 
		cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char) 194;
	cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191<< endl;
	for(int i = 0; i < 9; i++){
		cout << (char)179;
		for(int j = 0; j < 9; j++){
			if(!mat[i][j]) SetConsoleTextAttribute(hConsoleColor, 0xfc);
			cout << t[i][j] << " ";
			SetConsoleTextAttribute(hConsoleColor, 0xf0);
			if(j % 3 == 2) cout << (char)8 << (char)179;
		}
		cout << endl;
		if(i == 2 || i == 5){
			cout << (char)195;
			for(int j = 0; j < 2; j++){
				cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)197;
			}
			cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)180;
			cout << endl;	
		}
	}
	cout << (char)192;
	for(int i = 0; i < 2; i++) 
		cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)193;
	cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << endl;
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

int main(){
	init();
	input();
	TRY(0, 0);
}
