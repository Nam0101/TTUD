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

//int partition(int L, int R, int idPivot){
//	float pivot = a[idPivot];
//	swap(idPivot, R);
//	int storeId = L;
//	for(int i = L; i < R; i++){
//		if(a[i] < pivot){
//			swap(storeId, i);
//			storeId++;
//		}
//	}
//	swap(storeId, R);
//	return storeId;
//}
//
//void qSort(int L, int R){
//	if(L < R){
//		int id = (L + R) / 2;
//		id = partition(L, R, id);
//		if(id > L) qSort(L, id - 1);
//		if(id < R) qSort(id + 1, R);
//	}
//}

void qSort(int l, int r){
		int i=l, j=r;
		float key = a[(l+r)/2];
		do{
			while(a[i]<key) i++;
			while(a[j]>key) j--;
			if(i<=j){
				float t=a[i];
				a[i]=a[j];
				a[j]=t;
				i++;
				j--;
			}
		}
		while(i<=j);
		if(l<j) qSort(l,j);
		if(i<r) qSort(i,r);
	}

void output(){
	for(int i = 0; i < n; i++){
	    printf("%.2f ", a[i]);
	}
}

int main(){
	//srand(time(NULL));
	input();
	qSort(0, n - 1);
	output();
}
