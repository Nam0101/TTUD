#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 100005;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n;
int a[MAX];
int dp[MAX];
void input()
{
    std::cin >> n;
    ft(i, 1, n)
    {
        std::cin >> a[i];
    }
}
void solution()
{
    dp[1] = a[1];
    dp[2] = std::max(a[1], a[2]);
    ft(i, 3, n)
    {
        dp[i] = std::max(dp[i - 1], std::max(dp[i - 2] + a[i], dp[i - 3] + a[i]));
    }
    std::cout << dp[n];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    solution();
}