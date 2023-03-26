// Cho một đồ thị đầy đủ có trọng số.
// Yêu cầu:Tìm một cách di chuyển qua mỗi đỉnh đúng một lần và quay về đỉnh xuất phát sao cho tổng trọng số các cạnh đi qua là nhỏ nhất (chu trình hamilton nhỏ nhất).
#include <bits/stdc++.h>
using namespace std;
int n;
int c[100][100];
int x[100];
int best = 1000000;
bool mark[100];
int minC = 1000000;
// 4 0 1 1 9 1 0 9 3 1 9 0 2 9 3 2 0

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] < minC)
                minC = c[i][j];
        }
    }
}
void duyet(int i, int sum)
{
    if (i == n + 1)
    {
        if (sum + c[x[n]][1] < best)
        {
            best = sum + c[x[n]][1];
        }
        return;
    }
    for (int j = 2; j <= n; j++)
    {
        if (!mark[j])
        {
            if (sum + c[x[i - 1]][j] + minC * (n - i) >= best)
                continue;
            mark[j] = 1;
            x[i] = j;
            duyet(i + 1, sum + c[x[i - 1]][j]);
            mark[j] = 0;
        }
    }
}
int main()
{
    input();

    x[1] = 1;
    mark[1] = 1;
    duyet(2, 0);
    cout << best;
    return 0;
}