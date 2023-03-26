// Balanced Courses Assignment
#include <iostream>
using namespace std;

#define MAX1 10
#define MAX2 30

int m, n;
bool teach[MAX1 + 1][MAX2 + 1];
bool confl[MAX2 + 1][MAX2 + 1]; 
//


bool check(int v, int k){
	
}

void TRY(int k){
	for(int v = 1; v <= m; v++){
		if(check(v, k)){
			//
			if(k == n){
				
			}
			else{
				//
				TRY(k + 1);
			}
		}
	}
}

void init(){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			teach[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			confl[i][j] = 0;
		}
	}
}

void input(){
	for(int i = 1; i <= m; i++){
		int k, p;
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> p;
			teach[i][p] = 1;
		}
	} 
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		confl[a][b] = confl[b][a] = 1;
	}
}

int main(){
	cin >> m >> n;
	init();
	input();
}
