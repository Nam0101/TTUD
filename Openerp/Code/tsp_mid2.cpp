// TSP
#include <stdio.h>

using namespace std;

#define MAX 14

int n, m;
int x[MAX]; // luu tru loi giai trong qua trinh duyet
bool t[MAX];
int cnt = 0;
int C[MAX][MAX];
int f = 0;
int C_min = 99999; // do dai chang nho nhat

void TRY(int k){
	for(int v = 1; v < n; v++){
		if(!t[v]){
		   if(f - C[x[k - 1]][v] < 0) return;
			x[k] = v;
			t[v] = true;
			f -= C[x[k - 1]][v];
			if(k == n - 1) cnt += f - C[x[n - 1]][0] >= 0;
			else if(f - C_min * (n - k + 1) > 0){
			    TRY(k + 1);		
			}
			t[v] = false;
			f += C[x[k - 1]][v];
		}
	} 
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
	   t[i] = false;
		for(int j = 0; j < n; j++){
			scanf("%d", &C[i][j]);
			C_min = C_min > C[i][j] ? C[i][j] : C_min; // cap nhat do dai chang nho nhat
		}
	}
	f = m;
	x[0] = 0;
	t[0] = true;
	TRY(1);
	printf("%d", cnt);
}
