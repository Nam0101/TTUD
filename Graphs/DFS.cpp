#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;
vector<int> adj[100005];
vector<bool> visited(100005, false);
stack<int> s;
void dfs(int u)
{
    s.push(u);
    visited[u] = true;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);
    // print node visited
    return 0;
}