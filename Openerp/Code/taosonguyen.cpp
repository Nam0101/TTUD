#include <iostream>
using namespace std;

int main(){
	char s[7];
	fflush(stdin);
	cout << "Nhap: ";
	cin.getline(s, 7);
	int n = 0;
	for(int i = 0; i < 6; i++){
		n = n * 10 + s[i] - '0';
	}
	cout << "Gia tri so: " << n;
}
