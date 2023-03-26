#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1e6 + 5;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
unsigned long long int a, b;
unsigned long long int mod = 1e9 + 7;
unsigned long long int expmod(unsigned long long int a, unsigned long long int b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b % 2 == 0)
    {
        unsigned long long int x = expmod(a, b / 2) % mod;
        return (x * x) % mod;
    }
    else
    {
        return (a % mod * expmod(a, b - 1) % mod) % mod;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> a >> b;
    std::cout << expmod(a, b) << std::endl;
    return 0;
}