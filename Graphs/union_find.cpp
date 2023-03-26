#include <bits/stdc++.h>
using namespace std;

struct union_find
{
    vector<int> parent;
    union_find(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot)
        {
            parent[xroot] = yroot;
        }
    }
};
struct edge
{
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(edge const &other)
    {
        return w < other.w;
    }
};
bool comp(edge e1, edge e2)
{
    return e1.w < e2.w;
}
// kruskal algorithm
vector<edge> MST(int n, vector<edge> edges)
{
    vector<edge> result;
    union_find uf(n);
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0; i < edges.size(); i++)
    {
        edge e = edges[i];
        if (uf.find(e.u) != uf.find(e.v))
        {
            uf.unite(e.u, e.v);
            result.push_back(e);
        }
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("kruskal.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge e1 = edge(u, v, w);
        edges.push_back(e1);
        edge e2 = edge(v, u, w);
        edges.push_back(e2);
    }
    vector<edge> result = MST(n, edges);
    long long sum = 0;
    for (int i = 0; i < result.size(); i++)
    {
        edge e = result[i];
        sum += e.w;
    }
    cout << sum << endl;
}