#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1005;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n;
int x1[MAX], y1[MAX], x2[MAX], y2[MAX];
int x_min, x_max, y_min, y_max;
void input()
{
    std::cin >> n;
    ft(i, 1, n)
    {
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
}
void solve()
{
    x_min = x1[1];
    x_max = x2[1];
    y_min = y1[1];
    y_max = y2[1];
    ft(i, 2, n)
    {
        x_min = std::min(x_min, x1[i]);
        x_max = std::max(x_max, x2[i]);
        y_min = std::min(y_min, y1[i]);
        y_max = std::max(y_max, y2[i]);
    }
    // diện tích hình chữ nhật
    std::cout << (x_max - x_min) * (y_max - y_min) << std::endl;
}
int main()
{
    input();
    solve();
    return 0;
}