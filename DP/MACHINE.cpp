// cho n đoạn, đoạn i bắt đầu từ s[i] và kết thúc tại t[i] có giá trị là v[i]=t[i]-s[i]
// chọn i,j sao cho t[i]<s[j] hoặc t[j]<s[i] và v[i]+v[j] lớn nhất
// 2<=n<=100000
// 1<=s[i]<=t[i]<=2000000
#include <bits/stdc++.h>
#define long long ll
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
#define maxN 2000005
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
int n;
int t[maxN], s[maxN], v[maxN];
int maxV[maxN]; // maxV[i] là giá trị tốt nhất kết thúc <=i
void input()
{
    scanf("%d", &n);
    ft(i, 1, n)
    {
        scanf("%d%d", &s[i], &t[i]);
        v[i] = t[i] - s[i];
    }
}
int main()
{
    input();
    ft(i, 1, n)
    {
        maxV[t[i]] = std::max(maxV[t[i]], v[i]);
    }
    ft(i, 1, maxN - 1)
    {
        maxV[i] = std::max(maxV[i], maxV[i - 1]);
    }
    int res = 0;
    ft(i, 1, n)
    {
        res = std::max(res, maxV[s[i] - 1] + v[i]);
    }
    printf("%d", res);
}