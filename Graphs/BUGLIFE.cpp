#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1000000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n, k, m;

int res;

std::vector<int> a[MAX];
int color[MAX];

void dfs(int u)
{
    for (int v : a[u])
    {
        if (color[v] == -1)
        {
            color[v] = !color[u];
            dfs(v);
        }
    }
}
int main()
{
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        std::cin >> n >> m;
        for (int j = 1; j <= n; j++)
            a[j].clear();
        for (int j = 1; j <= m; j++)
        {
            int u, v;
            std::cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        for (int j = 1; j <= n; j++)
            color[j] = -1;
        for (int j = 1; j <= n; j++)
        {
            if (color[j] == -1)
            {
                color[j] = 0;
                dfs(j);
            }
        }
        bool bipartite = true;
        for (int u = 1; u <= n; u++)
        {
            for (int v : a[u])
            {
                if (color[u] == color[v])
                {
                    bipartite = false;
                    break;
                }
            }
        }
        std::cout << "Scenario #" << i << ":\n";
        if (bipartite)
            std::cout << "No suspicious bugs found!\n";
        else
            std::cout << "Suspicious bugs found!\n";
    }
    for (int i = 1; i <= n; i++)
        color[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            dfs(i);
        }
    }
    bool bipartite = true;
    for (int u = 1; u <= n; u++)
    {
        for (int v : a[u])
        {
            if (color[u] == color[v])
            {
                bipartite = false;
                break;
            }
        }
    }
}