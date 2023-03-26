#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 30;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n, A, B;
int a[MAX];
int res = 0;
void Input()
{
    std::cin >> n >> A >> B;
    ft(i, 1, n)
    {
        std::cin >> a[i];
    }
}

void Try(int i, int sum)
{
    if (i == n + 1)
    {
        if (sum >= A && sum <= B)
        {
            res++;
        }
        return;
    }
    Try(i + 1, sum + a[i]);
    Try(i + 1, sum);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    Input();
    Try(1, 0);

    std::cout << res;
}