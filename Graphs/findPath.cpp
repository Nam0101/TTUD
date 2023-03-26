#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;
vector<int> adj[100005];
vector<int> visited(100005, false);
vector<int> parent;
int n, m, start, endNode;
int cur_comp;
void input()
{
    cin >> n >> m >> start >> endNode;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            dfs(v);
        }
    }
}
void Path(int s, int t)
{
    parent.resize(n + 1);
    dfs(s);
    if (!visited[t])
    {
        cout << "No Path";
        return;
    }
    vector<int> path;
    for (int v = t; v != s; v = parent[v])
    {
        path.pb(v);
    }
    path.pb(s);
    reverse(path.begin(), path.end());
    for (int v : path)
    {
        cout << v << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    Path(start, endNode);
}