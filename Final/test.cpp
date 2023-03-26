
#include <bits/stdc++.h>
using namespace std;
int n;
int sum, res;
void input()
{
    cin >> n;
    res = 0;
    sum = 0;
}
void solve(int k, int prev)
{
    for (int i = 1; i <= n; i++)
    {
        if (i >= prev)
        {
            sum += i;
            if (sum == n)
                res++;
            else if (k < n)
                solve(k + 1, i);
            sum -= i;
        }
    }
}
int main()
{
    input();
    solve(1, 0);
    cout << res;
    return 0;
}