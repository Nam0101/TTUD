// F[0] "0"
// F[1] "1"
// F[2] "10"
// F[3] "101"
// F[4] "10110"
// F[n]=F[n-1]+F[n-2]
// cho n và xâu nhị phân p
// đếm số lần xuất hiện của p trong F[n]
// 0<=n<=100
// 0<=p<=100000
#include <bits/stdc++.h>
#define ll long long
int c[100000];
int mc[2];
int n;
ll l[100000];
std::string f[100000];
std::string pInput;
void input()
{
    scanf("%d", &n);
    std::cin >> pInput;
}
void preprocess()
{
    f[0] = "0";
    f[1] = "1";
    l[0] = 1;
    l[1] = 1;
    int i = 2;
    while (true)
    {
        f[i] = f[i - 1] + f[i - 2];
        l[i] = l[i - 1] + l[i - 2];
        if (l[i - 1] > pInput.length())
            break;
        i++;
    }
}
ll count(std::string s, std::string p)
{
    if (s.length() < p.length())
    {
        return 0;
    }
    ll res = 0;
    for (int i = 0; i <= s.length() - p.length(); i++)
    {
        if (s.substr(i, p.length()) == p)
        {
            res++;
        }
    }
    return res;
}
ll count(int n, std::string p)
{
    if (c[n] < 0)
    {
        c[n] = count(n - 1, p) + count(n - 2, p) + mc[n % 2];
    }
    return c[n];
}
ll slove(int n, std::string p)
{
    int lp = p.length();
    if (l[n] < lp)
        return 0;
    for (int j = 0; j <= n; j++)
        c[j] = -1;
    int i = 1;
    while (l[i - 1] < lp)
        i++;
    c[i - 1] = count(f[i - 1], p);
    c[i] = count(f[i], p);
    std::string x = f[i].substr(0, lp - 1);
    std::string a = f[i - 1].substr(f[i - 1].length() - lp + 1, lp - 1);
    std::string b = f[i].substr(f[i].length() - lp + 1, lp - 1);
    mc[i % 2] = count(a + x, p);
    mc[(i + 1) % 2] = count(b + x, p);
    return count(n, p);
}
int main()
{
    input();
    preprocess();
    printf("%lld", slove(n, pInput));
    return 0;
}