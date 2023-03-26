#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	int* a = new int[n];
	cout << "Nhap mang: " << endl;
	for(int i = 0; i < n; i++){
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	int m = 0, *b;
	b = new int[n];
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0) b[m++] = a[i];
	}
	cout << "Mang cac so nguyen chia het cho 2: " << endl;
	for(int i = 0; i < m; i++){
		cout << b[i] << " ";
	}
}
