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
int n, k, m;
int a[MAX];
int res;
// tìm số dãy con có k phần tử có tổng bằng m
void input()
{
    std::cin >> n >> k >> m;
    ft(i, 1, n)
    {
        std::cin >> a[i];
    }
}
void solve()
{
    int sum = 0;
    int r = n;
    fdt(i, n, 1)
    {
        sum += a[i];
        while (sum > m && r >= i)
        {
            sum -= a[r--];
        }
        if (sum == m && r - i + 1 == k)
        {
            res++;
        }
    }
    std::cout << res;
}
// cái đoạn m cần tìm luôn có độ dài bằng k
// tính tổng đoạn có k phần tử
// sum1 = a[1]+...+a[k]
// sum2 = sum1-a[1] +a[k+1]
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    freopen("4-input.txt", "r", stdin);
    input();
    solve();
    return 0;
}