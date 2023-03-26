#include <bits/stdc++.h>
std::vector<int> adj[100005];
std::vector<bool> visited(100005, false);
std::vector<int> order;

void topoSort(int u)
{
    if (visited[u])
        return;
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
            topoSort(v);
    }
    order.push_back(u);
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            topoSort(i);
    }
    reverse(order.begin(), order.end());
    for (int i = 0; i < order.size(); i++)
    {
        std::cout << order[i] << " ";
    }
    return 0;
}
