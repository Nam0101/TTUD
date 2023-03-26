#include <iostream>
using namespace std;

#define MAX 100000

int N, M;
int a[MAX];
int b[MAX + 1];
int res = 0;

int main(){
    cin >> N >> M;
    b[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        b[i + 1] = b[i] + a[i];
    }
    //
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(b[j + 1] - b[i] <= M) {
            	res++;
				}
        }
    }
    cout << res;
}
