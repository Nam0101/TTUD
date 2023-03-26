#include <bits/stdc++.h>
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 1000005
#define pii pair<int, int>
int n;
ll a[MAX];
int dp[MAX];
ll sum;
void input()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
}
ll Res;
void solution()
{
    for (int i = 1; i <= n; i++)
    {
        sum = std::max(sum + a[i], a[i]);
        if (sum % 2 == 0)
            Res = std::max(Res, sum);
    }
    std::cout << Res;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    solution();
    return 0;
}