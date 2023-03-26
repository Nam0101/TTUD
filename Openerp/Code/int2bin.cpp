#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cout << "Nhap so nguyen n: ";
	cin >> n;
	char s[50];
	int i = 0;
	while(n > 0){
		s[i++] = n % 2 + '0';
		n /= 2;
	}
	s[i] = '\0';
	int len = strlen(s);
	for(i = 0; i < len / 2; i++){
		swap(s[i], s[len - i - 1]);
	}
	cout << "Chuyen sang nhi phan: " << s;
}
