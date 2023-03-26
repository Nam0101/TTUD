#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
#define maxN 100000
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n;
int a[maxN];
ll res;
int input()
{
    std::cin >> n;
    ft(i, 0, n - 1)
    {
        std::cin >> a[i];
    }
}
int count()
{
    ft(i, 0, n - 1)
    {
        if (a[i] < a[i + 1])
        {
            res++;
        }
    }
    return res;
}
int main()
{
    input();
    std::cout << count();
}