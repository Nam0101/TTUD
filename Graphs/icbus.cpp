#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;

const int INF = 1e9;
const int MAXN = 5005;

int n, m, c[MAXN], d[MAXN], dist[MAXN], used[MAXN];
vector<int> adj[MAXN];
vector<pii> edge;

void dijkstra() {
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    pq.push(mp(0, 1));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (used[u]) continue;
        used[u] = true;

        for (int v : adj[u]) {
            int w = c[u];
            if (d[u] < v) w += c[u] * (v - d[u]);
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i] >> d[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dijkstra();

    cout << dist[n] << "\n";

    return 0;
}
