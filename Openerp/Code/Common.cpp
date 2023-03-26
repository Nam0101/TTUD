#include <iostream>
using namespace std;

#define MAX 1000000

int n, m;
int a[MAX], b[MAX];
int t1[MAX], t2[MAX];
int res = 0;

void input(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];	
	}
}

void swap(int *a, int i, int j){
	float tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int partition(int* a, int L, int R, int idPivot){
	float pivot = a[idPivot];
	swap(a, idPivot, R);
	int storeId = L;
	for(int i = L; i < R; i++){
		if(a[i] < pivot){
			swap(a, storeId, i);
			storeId++;
		}
	}
	swap(a, storeId, R);
	return storeId;
}

void qSort(int *a, int L, int R){
	if(L < R){
		int id = (L + R) / 2;
		id = partition(a, L, R, id);
		if(id > L) qSort(a, L, id - 1);
		if(id < R) qSort(a, id + 1, R);
	}
}

int binSearch(int* a, int L, int R, int x){
	if(L > R) return -1;
	int id = (L + R) / 2;
	if(a[id] == x) return id;
	else if(a[id] < x) return binSearch(a, id + 1, R, x);
	else return binSearch(a, L, id - 1, x);
}

int main(){
	input();
	qSort(b, 0, m - 1);
	for(int i = 0; i < n; i++){
		if(binSearch(b, 0, m - 1, a[i]) != -1) res++;
	}
	cout << res;
}
