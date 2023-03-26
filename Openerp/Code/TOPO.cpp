#include <iostream>
#include <list>
using namespace std;

#define MAX 1000

int N, M;
list<int> A[MAX];

int d[MAX];
int x[MAX], idx = 0;

void input(char* filename){
	FILE* f = fopen(filename, "r");
	fscanf(f, "%d%d", &N, &M);
	for(int u = 1; u <= N; u++) d[u] = 0;
	for(int i = 1; i <= M; i++){
		int u, v;
		fscanf(f, "%d%d", &u, &v);
		A[u].push_back(v);
		d[v]++;
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

void solve(){
	bool f = false;
	while(!f){
		f = true;
		for(int u = 1; u <= N; u++){
			if(d[u] == 0){
				f = false;
				x[idx++] = u;
				d[u] = -1;
				for(list<int>::iterator it = A[u].begin(); it != A[u].end(); it++){
					int v = *it;
					d[v]--;
				}
				break;
			}
		}
	}
}

int main(){
	input("topo.txt");
	solve();
	for(int i = 0; i < N; i++){
		cout << x[i] << " ";
	}
}
