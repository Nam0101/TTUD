// Cho N đồ vật và một cái túi có sức chứa tối đa là M.
// Đồ vật i có khối lượng w[i] và giá trị a[i].
// Tìm cách lấy một số đồ vật sao cho tổng khối lượng không vượt quá M và tổng giá trị lớn nhất có thể.
#include <bits/stdc++.h>
#define long long ll
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
int n, m, w[1005], a[1005], f[1005][1005]; // n là số đồ vật, m là sức chứa của túi, w[i] là khối lượng của đồ vật i, a[i] là giá trị của đồ vật i, f[i][j] là giá trị lớn nhất có thể lấy được khi có i đồ vật và túi có sức chứa là j.
void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &a[i]);
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= w[i])
                f[i][j] = std::max(f[i][j], f[i - 1][j - w[i]] + a[i]); // f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + a[i]); là công thức quy hoạch động.
        }
    printf("%d", f[n][m]);
}
int main()
{
    input();
    solve();
    return 0;
}