#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1000000;
const long long mod = 1000000007;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n;
ll res = 0;
int dp[51][51]; // f[i][j] = so cach chon các số sao cho tong bang i va so lon nhat la j
void input()
{
    std::cin >> n;
}
void output()
{
    std::cout << res % mod << std::endl;
}
int p[100]; // p[i] = so cach chon cac so sao cho tong bang i
void solve()
{
    input();
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i && j <= n / 2; j++)
        {
            p[i] += p[i - j]; //
        }
        std::cout << "p[" << i << "] = " << p[i] << std::endl;
    }
    res = p[n];
    output();
}
int main()
{
    solve();
    return 0;
}