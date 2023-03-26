// TSP
#include <stdio.h>

using namespace std;

#define MAX 15

int n, m;
int x[MAX + 1]; // luu tru loi giai trong qua trinh duyet
bool t[MAX + 1];
long long cnt = 0;
int C[MAX + 1][MAX + 1];
int f = 0;
int C_min = 99999; // do dai chang nho nhat
int CC_min;

void updateBest(){
	cnt += f + C[x[n]][x[1]] <= m;
}

void TRY(int k){
	int v;
	for(v = 2; v <= n; v++){
	    if(f + C[x[k - 1]][v] > m) continue;
		if(!t[v]){
			x[k] = v;
			t[v] = true;
			f += C[x[k - 1]][v];
			CC_min -= C_min;
			if(k == n) updateBest();
			else if(f + CC_min < m){
				TRY(k + 1);		
			}
			t[v] = false;
			f -= C[x[k - 1]][v];
			CC_min += C_min;
		}
	} 
}

void input(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
	   t[i] = false;
		for(int j = 1; j <= n; j++){
			scanf("%d", &C[i][j]);
			C_min = C_min > C[i][j] ? C[i][j] : C_min; // cap nhat do dai chang nho nhat
		}
	}
	CC_min = C_min * n;
}

void init(){
	f = 0;
	x[1] = 1;
	t[1] = true;
}

int main(){
	input();
	init();
	TRY(2);
	printf("%d", cnt);
}
