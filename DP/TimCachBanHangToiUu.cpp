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
int n, L1, L2;
int a[1000000];
ll res;
void input()
{
    std::cin >> n >> L1 >> L2;
    ft(i, 1, n)
    {
        std::cin >> a[i];
    }
}
ll maxRes = 0;
void solution(int i, int j)
{
    if (i == n + 1)
    {
        maxRes = std::max(res, maxRes);
        return;
    }
    if (i == 1)
    {
        res = a[i];
        j = i;
        solution(i + 1, j);
    }
    else
    {
        if ((i - j) >= L1 && (i - j) <= L2)
        {
            res += a[i];
            solution(i + 1, i);
            res -= a[i];
        }
        else
        {
            solution(i + 1, j);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    solution(1, 1);
    std::cout << maxRes;
    return 0;
}