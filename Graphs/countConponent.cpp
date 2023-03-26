#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[1005][1005]; // ma trận x/o
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool visited[1005][1005];
int countComponent = 0;
void DFS(int i, int j)
{
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int u = i + dx[k];
        int v = j + dy[k];
        if (u >= 1 && u <= n && v >= 1 && v <= m && a[u][v] == 'x' && !visited[u][v])
        {
            DFS(u, v);
        }
    }
}
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    input();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'x' && !visited[i][j])
            {
                DFS(i, j);
                countComponent++;
            }
        }
    }
    cout << countComponent;
}