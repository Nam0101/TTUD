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
int a[MAX];
int num;
ll res = 0;
ll sum[MAX];
void input()
{

    std::cin >> n;
    std::cin >> a[0];
    sum[0] = a[0];
    ft(i, 1, n - 1)
    {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
}

void solution1()
{
    ft(i, 0, n - 1)
    {
        ft(j, 0, i)
        {
            if ((sum[i] - sum[j - 1]) % 2 == 0)
            {
                res = (res + 1) % 1000000007;
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // freopen("Daychan.txt", "r", stdin);
    input();
    solution1();
    std::cout << res << std::endl;
    return 0;
}