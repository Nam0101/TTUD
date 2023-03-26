#include <bits/stdc++.h>
#define ve vector<edge>
using namespace std;

struct edge
{
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(edge const &other)
    {
        return w < other.w;
    }
};
vector<edge> Prim(int n, vector<ve> adj)
{
    vector<bool> visited(n, false); // visited[i] = true if i is visited
    vector<edge> result;            // result edges
    vector<int> best_W(n, INT_MAX); // best_W[i] = best weight of edge from i to visited node
    vector<int> best_A(n, -1);      // best_A[i] = best node to connect to i
    best_W[0] = 0;
    while (result.size() < n - 1)
    {
        int u = -1, v = -1, w = INT_MAX;
        for (int x = 0; x < n; x++)
        {
            if (!visited[x] && best_W[x] < w)
            {
                u = x;
                v = best_A[x];
                w = best_W[x];
            }
        }
        if (u == -1)
            return result;
        visited[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (!visited[v] && w < best_W[v])
            {
                best_W[v] = w;
                best_A[v] = u;
            }
        }
        result.push_back(edge(u, v, w));
    }
    return result;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ve> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(edge(u, v, w));
        adj[v].push_back(edge(v, u, w));
    }
    vector<edge> result = Prim(n, adj);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].u << " " << result[i].v << " " << result[i].w << endl;
    }
    return 0;
}