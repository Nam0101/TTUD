#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;
vector<int> adj[100005];
vector<int> comp(100005, -1);
int n, m;
int cur_comp;
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void Find_component(int u)
{
    if (comp[u] != -1)
        return;
    comp[u] = cur_comp;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        Find_component(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for (int i = 1; i <= n; i++)
    {
        if (comp[i] == -1)
        {
            Find_component(i);
            cur_comp++;
        }
    }
    cout << cur_comp << endl;
    return 0;
}