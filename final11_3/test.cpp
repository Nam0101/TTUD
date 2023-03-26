#include <bits/stdc++.h>
using namespace std;

const int max_khoang_cach = 100;

struct Arc
{
    int u, v, w;
    Arc(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator<(const Arc &O) const
    {
        return w < O.w;
    }
};

int N, M, K;
vector<Arc> Arcs;
vector<int> nodes(K);
vector<Arc> S;
int root[max_khoang_cach];
int i = 0;
void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Arcs.push_back(Arc(u, v, w));
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> nodes[i];
    }
}
int find(int u)
{
    return root[u] == u ? u : root[u] = find(root[u]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    input();
    for (int i = 0; i < K; i++)
    {
        for (int j = i + 1; j < K; j++)
        {
            int u = nodes[i], v = nodes[j];
            auto it = find_if(Arcs.begin(), Arcs.end(), [=](Arc &e)
                              { return (e.u == u && e.v == v) || (e.u == v && e.v == u); });
            if (it != Arcs.end())
            {
                cout << it->u << " " << it->v << " " << it->w << endl;
                S.push_back(*it);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        root[i] = i;
    }
    sort(S.begin(), S.end());
    for (int i = 1; i <= N; i++)
    {
        root[i] = i;
    }
    int khoang_cach = 0;
    for (const auto &e : S)
    {
        int u = find(e.u), v = find(e.v), w = e.w;
        if (u != v)
        {
            root[u] = v;
            khoang_cach += w;
        }
    }
    cout << khoang_cach << endl;
    return 0;
}
