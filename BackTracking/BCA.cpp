// Có n môn học và m giáo viên,
// mỗi giáo viên chỉ có thể dạy các môn trong danh sách cho trước.
// Các môn học trùng giờ không thể được dạy bởi cùng một giáo viên.
// Tải của một giáo viên là số khóa học giáo viên phải dạy.
// Yêu cầu:Tìm cách xếp lịch để tải của giáo viên có tải cao nhất là nhỏ nhất.
#include <bits/stdc++.h>
using namespace std;
#define inf 10000000000
int n, m;
int l[100];      // số môn dạy của giáo viên i
int t[100][100]; // t[i][j]=1 nếu giáo viên i dạy môn j
int a[100][100]; // giáo viên j có thể dạy môn j không
int res;
int max_load;
vector<int> o[30];
bool check(int i, int x)
{
    if ((a[i][x] == 0) || l[i] + 1 >= res)
        return false;
    for (int j = 0; j < o[x].size(); j++)
    {
        if (t[i][o[x][j]] == 1)
            return false;
    }
    return true;
}
void Try(int i)
{
    if (i == n)
    {
        res = min(res, max_load);
        return;
    }
    for (int j = 0; j < m; j++)
    {
        if (check(j, i))
        {
            int tmp = max_load;
            t[j][i] = 1;
            l[i]++;
            max_load = max(max_load, l[i]);
            Try(i + 1);
            t[j][i] = 0;
            l[i]--;
            max_load = tmp;
        }
    }
}
int main()
{
    cin >> n >> m;
    int k, u, v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = 0;
            a[i][j] = 0;
        }
        l[i] = 0;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> u;
            u--;
            a[i][u] = 1;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        o[u].push_back(v);
        o[v].push_back(u);
    }
    res = inf;
    max_load = 0;
    Try(0);
    cout << res;
    return 0;
}