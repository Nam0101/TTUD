#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];
void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}
int maxLeftMid(int i,int j){
    int maxLM=a[j];
    int sum=0;
    for(int k=j;k>=i;k--){
        sum+=a[k];
        if(sum>maxLM) maxLM=sum;
    }
    return maxLM;
}
int maxRightMid(int i,int j){
    int maxRM=a[i];
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=a[k];
        if(sum>maxRM) maxRM=sum;
    }
    return maxRM;
}
int subSeqMax(int i,int j){
    if(i == j) return a[i];
    int mid = (i+j)/2;
    int left = subSeqMax(i,mid);
    int right = subSeqMax(mid+1,j);
    int maxLM= maxLeftMid(i,mid);
    int maxRM= maxRightMid(mid+1,j);
    int midMax = maxLM+maxRM;
    return max(max(left,right),midMax); 
}

int main(){
    input();   
    cout << subSeqMax(0,n-1); 
}