// đếm số phần tử của dãy con mà tổng các phần tử là chẵn
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];
// dynamic programming
    // f[i] là số phần tử của dãy con mà tổng các phần tử là chẵn và kết thúc ở a[i]
    // f[i] = f[i-1] + 1 nếu a[i] là số chẵn
    // f[i] = 0 nếu a[i] là số lẻ
    // f[i] = f[i-1] + 1 nếu a[i] là số chẵn và a[i-1] là số lẻ
    // f[i] = f[i-1] nếu a[i] là số lẻ và a[i-1] là số chẵn
    // f[i] = f[i-1] nếu a[i] là số lẻ và a[i-1] là số lẻ
    // f[i] = 0 nếu a[i] là số chẵn và a[i-1] là số chẵn
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
        f[i] = 0;
        if(a[i] % 2 == 0){
            f[i] = f[i-1] + 1;
            if(a[i-1] % 2 != 0){
                f[i] = f[i-1] + 1;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += f[i];
    }
    cout << res;    
}