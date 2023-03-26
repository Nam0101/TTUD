// In tat ca so truong hop cua Sudoku
#include <iostream>
using namespace std;

int mat[9][9];
bool t1[9][9], t2[9][9], t3[9][9];
int cnt = 0;

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
	if(cnt > 100) exit(1);
	cout << cnt << "." << endl;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

bool check(int v, int x, int y){
	return t1[x][v - 1] == 0 && t2[y][v - 1] == 0 && t3[3 * (x / 3) + y / 3][v - 1] == 0;
}

void TRY(int x, int y){
	int v;
	for(v = 1; v <= 9; v++){
		if(check(v, x, y)){
			mat[x][y] = v;
			// cap nhat danh dau
			t1[x][v - 1] = true;
			t2[y][v - 1] = true;
			t3[3 * (x / 3) + y / 3][v - 1] = true;
			if(x == 8 && y == 8) solution();
			else{
				if(y == 8) TRY(x + 1, 0);
				else TRY(x, y + 1);
			}
			// khoi phuc trang thai khi backtrack
			t1[x][v - 1] = false;
			t2[y][v - 1] = false;
			t3[3 * (x / 3) + y / 3][v - 1] = false;
		}
	}	
}

int main(){
	init();
	TRY(0, 0);
}
