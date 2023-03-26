#include <bits/stdc++.h>
#define long long ll
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int N, T, D;        // N là số nhà kho, T là thời gian tối đa, D là khoảng cách tối đa giữa 2 nhà kho
int a[1000];        // a[i] là số lượng hàng hóa tại nhà kho i
int t[1000];        // t[i] là thời gian để lấy hàng hóa tại nhà kho i
int dp[1000][1000]; // f[i][j] là số lượng hàng tối đa thu được khi xét các nhà kho từ 1 đến i và thời gian không quá là j
// ans = max(dp[i][k]) với k = 0,1,2,...,T;i = 1,2,...,N
void input()
{
    scanf("%d%d%d", &N, &T, &D);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &t[i]);
}
void solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= T; k++)
        {
            if (k < t[i])
            {
                dp[i][k] = -1000000ll;
            }
            else
            {
                for (int j = i - D; j < i; j++)
                {
                    if (j >= 0)
                    {
                        dp[i][k] = std::max(dp[i][k], dp[j][k - t[i]] + a[i]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= T; i++)
        for (int j = 1; j <= N; j++)
            ans = std::max(ans, dp[j][i]);
    printf("%d", ans);
}
int main()
{
    input();
    solve();
    return 0;
}