#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n, k;
int a[MAXN];

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void solution()
{
    int sum = 0;
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    for (int i = k; i < n; i++)
    {
        sum += a[i];
        sum -= a[i - k];
        res = max(res, sum);
    }
    cout << res << endl;
}
int main()
{
    input();
    solution();
    return 0;
}