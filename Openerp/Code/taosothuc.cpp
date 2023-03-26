#include <iostream>
using namespace std;

int main(){
	char s[7];
	fflush(stdin);
	cout << "Nhap: ";
	cin.getline(s, 7);
	float m = 0, pow = 10;
	bool dot = false;
	for(int i = 0; i < 6; i++){
		if(!dot) {
			if('0' <= s[i] && s[i] <= '9')
				m = m * 10 + s[i] - '0';
			else if(s[i] == '.')
				dot = true;
		}
		else{
			m = m + (s[i] - '0') / pow;
			pow *= 10;
		}
	}
	cout << "Gia tri so: " << m;
}
