#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 10000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
ll n, k;
ll a[MAX];
ll sum[MAX][MAX]; // sum i j = sum a[i] + a[i+1] + ... + a[j]
double avg_max = 0;
void input()
{
    cin >> n >> k;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                sum[i][j] = a[i];
            sum[i][j] = sum[i][j - 1] + a[j];
        }
    }
}

void solve()
{
    for (long long i = 0; i < n - k; i++)
    {
        for (long long j = i + k - 1; j < n; j++)
        {
            if (a[j] < avg_max)
                continue;
            double tmp = (double)sum[i][j] / (j - i + 1);
            if ((tmp > avg_max))
                avg_max = tmp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    printf("%.5lf", avg_max);

    // cout << sum[0][3];
    return 0;
}