#include <iostream>
#include <list>
using namespace std;

//DFS (u):
//	t = t + 1
//	d[u] = t
//	color(u) = G
//	for v in A[u] do
//		if color[v] == W then
//			p[v] = u
//			dfs(v)
//
//DFS(G = (V,E)):
//	for v in V do
//		color[v] = W
//		p[v] = null
//	for v in V do
//		if color[v] == W then
//			DFS(v)

#define MAX 100000

int N, M;
list<int> A[MAX];

int d[MAX];
int f[MAX];
int p[MAX];
char color[MAX];
int t;

void DFS(int u){
	t++;
	d[u] = t;
	color[u] = 'G';
	for(list<int>::iterator it = A[u].begin(); it != A[u].end(); it++){
		int v = *it;
		if(color[v] == 'W'){
			p[v] = u;
			DFS(v);
		}
	}
	// u tro thanh da duyet xong
	t++;
	f[u] = t;
	color[u] = 'B';
}

void init(){
	for(int v = 1; v <= N; v++){
		color[v] = 'W';
	}
	t = 0;
}

void DFS(){
	init();
	for(int v = 1; v <= N; v++){
		if(color[v] == 'W'){
			DFS(v);
		}
	}
}

void input(char* fileName){
	FILE* f = fopen(fileName, "r");
	fscanf(f, "%d%d", &N, &M);
	for(int i = 1; i <= M; i++){
		int u, v;
		fscanf(f, "%d%d", &u, &v);
		A[u].push_back(v);
	}
	fclose(f);
}

void printGraph(){
	for(int v = 1; v <= N; v++){
		printf("A[%d] = ", v);
		for(list<int>::iterator it = A[v].begin(); it != A[v].end(); it++){
			printf("%d ", *it);
		}
		printf("\n");
	}
}

int main(){
	input("dfs.txt");
	printGraph();
}
