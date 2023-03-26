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
int n, m;
std::vector<int> adj[100000];
std::vector<int> visited(100000, 0);
int color[100000];
void input()
{
    std::cin >> n >> m;
    ft(i, 1, m)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
bool dfs(int v, int c)
{
    color[v] = c;
    for (int u : adj[v])
    {
        if (color[u] == c)
            return false;
        if (color[u] == 0 && !dfs(u, -c))
            return false;
    }
    return true;
}
int main()
{
    input();
    bool is_bipartite = true;
    ft(i, 1, n)
    {
        if (color[i] == 0)
        {
            is_bipartite = is_bipartite && dfs(i, 1);
        }
    }

    std::cout << is_bipartite << std::endl;
    return 0;
}