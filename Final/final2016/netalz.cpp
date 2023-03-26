#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n, m;
vector<int> adj[MAXN];
vector<bool> visited(MAXN, false);
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
vector<int> dist(MAXN, INT_MAX);
void dijiktra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        if (visited[u])
            continue;
        visited[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }
}
int main()
{
    input();
    int e[MAXN];
    for (int i = 1; i <= n; i++)
    {
        dijiktra(i);
        for (int j = 1; j <= n; j++)
        {
            e[i] = max(e[i], dist[j]);
        }
        visited.assign(MAXN, false);
        dist.assign(MAXN, INT_MAX);
    }
    int res;
    for (int i = 1; i <= n; i++)
    {
        res = min(res, e[i]);
    }
    cout << res;
    return 0;
}