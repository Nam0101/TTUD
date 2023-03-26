#include <bits/stdc++.h>
#define long long ll
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 1000005
#define pii pair<int, int>
// cần phân bổ M cửa hàng cho N chi nhánh
// số cửa hàng được phân bổ cho chi nhánh i phải dương và chia hết cho số nv bán hàng a[i]
// đếm số cách phân bố
int n;
int a[MAX];
int dp[MAX];
int sum[MAX];
void input()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
}
void solution()
{
    dp[0] = a[0];
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        dp[i] = std::max(a[i], sum[i] + a[i]);
    }
    std::cout << dp[n - 1];
}
int main()
{
    input();
    solution();
    return 0;
}