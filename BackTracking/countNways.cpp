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
#define mod 1000000007
int dp[1000000];
long long count;
void input()
{
    std::cin >> n;
}
int Count(int n)
{
    dp[0] = 1; // base case
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] += dp[j - i];
        }
    }
    return dp[n];
}

int main()
{
    input();
    count = Count(n);
    std::cout << count % mod << std::endl;
    return 0;
}