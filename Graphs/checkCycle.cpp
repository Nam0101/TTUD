#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];
int start, endNode;
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
bool DFS(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            parent[v] = u;
            if (DFS(v))
            {
                return true;
            }
        }
        else if (parent[u] != v)
        {
            start = v;
            endNode = u;
            return true;
        }
    }
}
int main()
{
    freopen("checkCycle.txt", "r", stdin);
    input();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (DFS(i))
            {
                cout << "YES" << endl;
                vector<int> path;
                path.push_back(endNode);
                int u = endNode;
                while (u != start)
                {
                    u = parent[u];
                    path.push_back(u);
                }
                path.push_back(endNode);
                reverse(path.begin(), path.end());
                for (int i = 0; i < path.size(); i++)
                {
                    cout << path[i] << " ";
                }
                return 0;
            }
        }
    }
    cout << "NO";
}