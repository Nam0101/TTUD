// có K xe giống hệt nhau, mỗi xe chứa tối đa Q gói hàng
// có n khách hàng, mỗi khách hàng i yêu cầu d[i] gói hàng
// mỗi khách hàng được phục vụ bởi một xe
// mỗi xe phục vụ tối thiểu 1 khách hàng
// đếm số cách sắp xếp lộ trình để phục vụ khách hàng
#include <iostream>
using namespace std;
int n, K, Q;
int d[100];//số request của khách hàng i
int x[100];//x[i] là xe phục vụ khách hàng i    
int q[100];//số gói hàng còn trống của xe i
int c[100];//số cách lộ trình của xe i
int res;
   
void input(){
    cin >> n >> K >> Q;
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }
}
int custom_factorial(int t){
    if(t==1) return 1;
    if(t==0) return 1;
    return t*custom_factorial(t-1);
}
void Try(int i)
{
    if (i == n)
    {
        int tmp = 1;
        for (int j = 0; j < K; j++)
            tmp *= custom_factorial(c[j]);
        res += tmp;
        return;
    }
    for(int k=0;k<K;k++){
        if(q[k]>=d[i]){
            q[k]-=d[i];
            c[k]++;
            Try(i+1);
            q[k]+=d[i];
            c[k]--;
        }
    }
}
int main(){
    input();
    for(int i=0;i<K;i++){
        q[i]=Q;
    }
    Try(0);
    cout << res;

}