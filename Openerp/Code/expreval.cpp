#include <iostream>
using namespace std;

#define MAX 100000

int n;
int a[MAX], b[MAX];
int flag = -1;
long long tmp = 1;

long long res = 0;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) cin >> b[i];
	b[0] = 1;
	//
	for(int i = 0; i < n; i++){
		if(b[i] < 2){
			if(i == n - 1 || b[i + 1] < 2){
				res += (b[i] == 0) ? -a[i] : a[i];
			}
			else{
				flag = b[i];
				tmp = a[i];
			}
		}
		else if(b[i] == 2){
			tmp = (tmp * a[i]) % 1000000007;
			if(i == n - 1 || b[i + 1] < 2){
				res += (flag == 0) ? -tmp : tmp;
			}
		}
	}
	res = (res % 1000000007 + 1000000007) % 1000000007;	
	cout << res;
}
