#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100];
bool visited[100];
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
// Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges. Write a program that compute the sequence of nodes visited using a DFS algorithm (the nodes are considered in a lexicographic order)
void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
}
int main()
{
    input();
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs(1);
    return 0;
}