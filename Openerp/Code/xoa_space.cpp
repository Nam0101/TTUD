#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	int n;
	do{
		cout << "Nhap n (0 < n <= 10): ";
		cin >> n;
	}
	while(n <= 0 || n > 10);
	srand(time(NULL));
	cout << "Day so nguyen ngau nhien le - chan xen ke: " << endl;
	for(int i = 0; i < n; i++){
		int a = rand();
		if(i % 2 == 0) a = a | 1;
		else a = a & 0xfffffffe;
		cout << a << " "; 
	}
}
