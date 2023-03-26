#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 5;
int n, k;
int a[MAXN];
int res = 0;
const double eps = 1e-6;

void input(){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void Try(int i, int sum){
    if(i == n){
        if(abs(sum - k) < eps){
            res++;
        }
        return;
    }
    Try(i + 1, sum + a[i]);
    Try(i + 1, sum - a[i]);
}

int main(){
    freopen("test.txt", "r", stdin);
    cin >> n;
    cin >> k;
    input();
    Try(1, a[0]);
    cout << res << endl;
    return 0;
}
