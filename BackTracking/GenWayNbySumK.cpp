// cho so nguyen n,k.
// chọn n số nguyên dương sao cho tổng chúng bằng k
// in ra các cách chọn
// 3 7
// 1 1 5
// 1 2 4
// 1 3 3
// 2 2 3
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
int n, k;
std::vector<int> a;
void input()
{
    std::cin >> n >> k;
}
void output()
{
    ft(i, 0, a.size() - 1)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
int last()
{
    if (a.size() == 0)
        return 1;
    return a[a.size() - 1];
}
void Try(int i, int sum)
{
    if (i == n)
    {
        if (sum == k)
        {
            output();
        }
        return;
    }
    for (int j = last(); j <= k; j++)
    {
        if (sum + j <= k)
        {
            a.push_back(j);
            Try(i + 1, sum + j);
            a.pop_back();
        }
    }
}

void solve()
{
    input();
    Try(0, 0);
}
int main()
{
    solve();
    return 0;
}