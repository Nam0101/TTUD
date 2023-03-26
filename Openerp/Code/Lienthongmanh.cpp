#include <iostream>
#include <list>
using namespace std;

#define MAX 1000

int N, M;
list<int> A[MAX];
list<int> B[MAX];

int d[MAX], f[MAX], p[MAX];
char color[MAX];
int t;
int x[MAX], idx = 0;
int idxCC[MAX], nCC;

void input(char* filename){
	FILE* f = fopen(filename, "r");
	fscanf(f, "%d%d", &N, &M);
	for(int i = 1; i <= M; i++){
		int u, v;
		fscanf(f, "%d%d", &u, &v);
		A[u].push_back(v);
	}
	fclose(f);
}

void comp_graph(){ // xay dung do thi bu
	for(int u = 1; u <= N; u++){
		for(list<int>::iterator it = A[u].begin(); it != A[u].end(); it++){
			int v = *it;
			B[v].push_back(u);
		}
	}
}

void init(){
	for(int v = 1; v <= N; v++){
		color[v] = 'W';
	}
	t = 0;
}

void DFS1(int u){
	t++;
	d[u] = t;
	color[u] = 'G';
	for(list<int>::iterator it = A[u].begin(); it != A[u].end(); it++){
		int v = *it;
		if(color[v] == 'W'){
			p[v] = u;
			DFS1(v);
		}
	}
	// u tro thanh da duyet xong
	t++;
	f[u] = t;
	color[u] = 'B';
	x[idx++] = u;
}

void DFS1(){
	init();
	for(int v = 1; v <= N; v++){
		if(color[v] == 'W'){
			DFS1(v);
		}
	}
}

void DFS2(int u){
	color[u] = 'G';
	idxCC[u] = nCC;
	for(list<int>::iterator it = B[u].begin(); it != B[u].end(); it++){
		int v = *it;
		if(color[v] == 'W'){
			p[v] = u;
			DFS2(v);
		}
	}
	// u tro thanh da duyet xong
	color[u] = 'B';
}

void DFS2(){
	init();
	nCC = 0;
	for(; idx >= 0; idx--){
		int v = x[idx];
		if(color[v] == 'W'){
			nCC++;
			DFS2(v);
		}
	}
}

void result(){
	for(int k = 1; k <= nCC; k++){
		printf("Thanh phan lien thong thu %d: ", k);
		for(int v = 1; v <= N; v++){
			if(idxCC[v] == k)
				printf("%d ", v);
		}
		printf("\n");
	}
}

int main(){
	input("lienthongmanh.txt");
	DFS1();
	comp_graph();
	DFS2();
	result();
}
