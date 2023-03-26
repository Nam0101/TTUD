#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1000000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n;
int a[MAX];
int cnt;
void input(){
    std:: cin>>n;
    ft(i, 0, n-1){
        std:: cin>>a[i];
    }
}
int countSolution(){
    ft(i, 0, n-1){
       if(a[i+1]<a[i]){
           cnt++;
       }
    }
    return cnt;
}