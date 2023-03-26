// Sudoku 3

#include <iostream>
using namespace std;

int T;
bool flag;
int tmp;
int t[8][8];
int t1[8][9], t2[8][9], t3[4][9];

void init(){
	flag = true;
	for(int i = 0; i < 8; i++){
		for(int j = 1; j < 9; j++){
			t1[i][j] = 0;
			t2[i][j] = 0;
			if(i < 4) t3[i][j] = 0;
		}
	}
}

void solution(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}

bool check(int v, int x, int y){
	return t1[x][v] < 1 && t2[y][v] < 1 && t3[2 * (x / 4) + (y / 4)][v] < 2;
}

void TRY(int x, int y){
	if(t[x][y] != 0){
		if(x == 7 && y == 7) solution();
		else{
			if(y < 7) TRY(x, y + 1);
			else TRY(x + 1, 0);
		}
	}
	else
	for(int v = 1; v <= 8; v++){
		if(check(v, x, y)){
			t[x][y] = v;
			t1[x][v]++;
			t2[y][v]++;
			t3[2 * (x / 4) + (y / 4)][v]++;
			if(x == 7 && y == 7) solution();
			else{
				if(y < 7) TRY(x, y + 1);
				else TRY(x + 1, 0);
			}
			t1[x][v]--;
			t2[y][v]--;
			t3[2 * (x / 4) + (y / 4)][v]--;
		}
	}
}

void input(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cin >> tmp;
			t[i][j] = tmp;
			if(tmp){
				t1[i][tmp]++;
				t2[j][tmp]++;
				t3[2 * (i / 4) + (j / 4)][tmp]++;
				if(t1[i][tmp] > 1 || t2[j][tmp] > 1 || t3[2 * (i / 4) + (j / 4)][tmp] > 2){
					flag = false;
				}
			}
		}
	}
}

int main(){
	cin >> T;
	for(int i = 0; i < T; i++){
		init();
		input();
		if(!flag) cout << "Test case #" << i + 1 << ": NO" << endl;
		else {
			cout << "Test case #" << i + 1 << ": YES" << endl;
			TRY(0, 0);
		}
	}
}
