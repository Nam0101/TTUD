#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1005;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int a, b, c;
int dp[MAX]; // dp[i] là số bước nhỏ nhất để đổ đầy thùng i lít
void input()
{
    std::cin >> a >> b >> c;
}
void slove()
{
    dp[0] = dp[1] = 1;
    ft(i, 2, c)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}