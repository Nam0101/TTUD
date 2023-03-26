#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int n, m, t, idxCC[N], nCC;
vector<int> a[N];
int d[N], f[N], p[N];
char color[N];
void DFS(int u)
{
    t++;
    d[u] = t;
    color[u] = 'G';
    idxCC[u] = nCC;
    for (int v : a[u])
    {
        if (color[v] == 'W')
        {
            p[v] = u;
            DFS(v);
        }
    }
    t++;
    f[u] = t;
    color[u] = 'B';
}
void init()
{
    for (int v = 1; v <= n; v++)
    {
        color[v] = 'W';
    }
    t = 0;
}
void DFS()
{
    init();
    nCC = 0;
    for (int v = 1; v <= n; v++)
    {
        if (color[v] == 'W')
        {
            nCC++;
            DFS(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }
    DFS();
    cout << nCC << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << idxCC[i] << " ";
    }
    return 0;
}