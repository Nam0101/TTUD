#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];
// tìm dãy con mà các phần tử luôn tăng dài nhất
// dynamic programming  


void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

int main(){
    input();
    int f[100000];
    f[0] = 1;
    for(int i = 1; i < n; i++){
        f[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, f[i]);
    }
    cout << res;

}