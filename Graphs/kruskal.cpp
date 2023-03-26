#include <bits/stdc++.h>
using namespace std;

int n, m;
struct edge
{
    int u, v, w;
    bool operator<(const edge &p) const
    {
        return w < p.w;
    }
};
int parent[1001], sz[1001];
void make_set()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
bool union_set(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}
vector<edge> edges;
void input()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void kruskal()
{
    // tạo cây khung nhỏ nhất
    vector<edge> result;
    int d = 0;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        if (result.size() == n - 1)
            break;
        edge e = edges[i]; // min
        if (union_set(e.u, e.v))
        {
            result.push_back(e);
            d += e.w;
        }
    }
    if (result.size() != n - 1)
        cout << "Khong Lien Thong";
    else
    {
        cout << d << endl;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("kruskal.inp", "r", stdin);
    // freopen("kruskal.out", "w", stdout);
    input();
    make_set();
    kruskal();
    return 0;
}