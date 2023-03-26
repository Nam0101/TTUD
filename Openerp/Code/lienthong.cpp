#include <iostream>
#include <list>
using namespace std;

#define MAX 100000

int N, M;
list<int> A[MAX];

int d[MAX];
int f[MAX];
int p[MAX];
char color[MAX];
int t;

int idxCC[MAX]; // idxCC la chi so cua thanh phan lien thong chua v (Connected Component)
int nCC;

void DFS(int u)
{
	t++;
	d[u] = t;
	color[u] = 'G';
	idxCC[u] = nCC;
	for (list<int>::iterator it = A[u].begin(); it != A[u].end(); it++)
	{
		int v = *it;
		if (color[v] == 'W')
		{
			p[v] = u;
			DFS(v);
		}
	}
	// u tro thanh da duyet xong
	t++;
	f[u] = t;
	color[u] = 'B';
}

void init()
{
	for (int v = 1; v <= N; v++)
	{
		color[v] = 'W';
	}
	t = 0;
}

void DFS()
{
	init();
	nCC = 0;
	for (int v = 1; v <= N; v++)
	{
		if (color[v] == 'W')
		{
			nCC++;
			DFS(v);
		}
	}
	for (int k = 1; k <= nCC; k++)
	{
		printf("Thanh phan lien thong thu %d: ", k);
		for (int v = 1; v <= N; v++)
		{
			if (idxCC[v] == k)
				printf("%d ", v);
		}
		printf("\n");
	}
}

void input(char *fileName)
{
	FILE *f = fopen(fileName, "r");
	fscanf(f, "%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		fscanf(f, "%d%d", &u, &v);
		A[u].push_back(v);
		A[v].push_back(u);
	}
	fclose(f);
}

void printGraph()
{
	for (int v = 1; v <= N; v++)
	{
		printf("A[%d] = ", v);
		for (list<int>::iterator it = A[v].begin(); it != A[v].end(); it++)
		{
			printf("%d ", *it);
		}
		printf("\n");
	}
}

int main()
{
	input("lienthong.txt");
	printGraph();
	DFS();
}
