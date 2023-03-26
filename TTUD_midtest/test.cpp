#include<bits/stdc++.h>
using namespace std;
#define N 1000001

int n;
int A[N];
int q;
int sum =0;
void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
}

int solution(){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum +=A[j];
            if(sum %2 == 0 ){
                q++;
                sum = 0;
            }
        }
    }
    return q;
}

int main(){
    input();
    int n = solution();
    cout <<n;
    return 0;
}