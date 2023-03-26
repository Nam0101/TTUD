#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<bool> visited(100005, false);
int n, m;
queue<int> q;
void input()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
int main()
{
    input();
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}