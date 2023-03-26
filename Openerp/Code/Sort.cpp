#include <stdio.h>

#define MAX 1000000

float a[MAX];
int n;

void input(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%f", &a[i]);
	}
}

void swap(int i, int j){
	float tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int partition(int L, int R, int idPivot){
	float pivot = a[idPivot];
	swap(idPivot, R);
	int storeId = L;
	for(int i = L; i < R; i++){
		if(a[i] < pivot){
			swap(storeId, i);
			storeId++;
		}
	}
	swap(storeId, R);
	return storeId;
}

void qSort(int L, int R){
	if(L < R){
		int id = (L + R) / 2;
		id = partition(L, R, id);
		if(id > L) qSort(L, id - 1);
		if(id < R) qSort(id + 1, R);
	}
}

void heapify(int i, int N){
	int L = 2 * i;
	int R = 2 * i + 1;
	int max = i;
	if(L < N and a[L] > a[max]) max = L;
	if(R < N and a[R] > a[max]) max = R;
	if(i != max){
		swap(i, max);
		heapify(max, N);
	}
}

void buildHeap(){
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify(i, n);
	}
}

void HSort(){
	buildHeap();
	for(int i = n - 1; i > 0; i--){
		swap(0, i);
		heapify(0, i - 1);
	}
}

void output(){
	for(int i = 0; i < n; i++){
	    printf("%.2f ", a[i]);
	}
}

int main(){
	//srand(time(NULL));
	input();
	HSort();
	output();
}
