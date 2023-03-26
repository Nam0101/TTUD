#include <bits/stdc++.h>

int a[] = {1, 5, 10, 50, 100, 500};
int n, ans;

int main()
{
    std::cin >> n;
    int dp[n + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < 6; i++)
        for (int j = a[i]; j <= n; j++)
            dp[j] = std::min(dp[j], dp[j - a[i]] + 1);
    std::cout << dp[n];
}