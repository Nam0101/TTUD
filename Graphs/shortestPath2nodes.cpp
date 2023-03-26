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
struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
std::vector<edge> adj[100000];
std::vector<int> dist(100000, INT_MAX);
int start, endNode;

bool operator<(edge a, edge b)
{
    return a.w > b.w;
}
void input()
{
    std::cin >> n >> m;
    ft(i, 1, m)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb(edge(u, v, w));
    }
    std::cin >> start >> endNode;
}
void dijiktra(int start)
{
    dist[start] = 0;
    std::priority_queue<edge> pq;
    pq.push(edge(start, start, 0));
    while (!pq.empty())
    {
        edge ed = pq.top();
        pq.pop();
        for (int i = 0; i < adj[ed.v].size(); i++)
        {
            edge e = adj[ed.v][i];
            if (dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = dist[e.u] + e.w;
                pq.push(e);
            }
        }
    }
}
int main()
{
    input();
    dijiktra(start);
    std::cout << dist[endNode] << std::endl;
    return 0;
}