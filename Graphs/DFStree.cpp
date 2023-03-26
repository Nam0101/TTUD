#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
using namespace std;
vector<int> adj[100005], low(100005), num(100005, -1);
vector<bool> visited(100005, false);
vector<pii> bridges;
int curnum = 0;
void input()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void find_brigdes(int u, int p)
{
    low[u] = num[u] = ++curnum;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (num[v] == -1)
        {
            find_brigdes(v, u);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
        if (low[v] > num[u])
        {
            bridges.pb(mp(u, v));
        }
    }
}
void analyzeDFS(int u, int p)
{
    low[u] = num[u] = ++curnum;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == p)
            continue;
        if (num[v] == -1)
        {
            analyzeDFS(v, u);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
        if (low[v] > num[u])
        {
            bridges.pb(mp(u, v));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    analyzeDFS(1, -1);
    cout << bridges.size() << endl;
    // number of denoting point
    for (int i = 0; i < bridges.size(); i++)
    {
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }
    return 0;
}