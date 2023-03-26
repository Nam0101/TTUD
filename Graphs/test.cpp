#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int n, m, k;
vector<vector<int>> adj;
vector<int> terminals;

// Computes the shortest path between all pairs of nodes
vector<vector<int>> floyd_warshall()
{
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
        for (int j : adj[i])
        {
            dist[i][j] = dist[j][i] = 1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

// Computes the minimum Steiner tree
int steiner_tree()
{
    vector<vector<int>> dist = floyd_warshall();

    // dp[S][i] is the minimum distance from the terminal set S to node i
    vector<vector<int>> dp(1 << k, vector<int>(n, INF));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[1 << i][j] = dist[terminals[i]][j];
        }
    }

    for (int S = 1; S < (1 << k); S++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int T = S & (S - 1); T > 0; T = (T - 1) & S)
            {
                dp[S][i] = min(dp[S][i], dp[T][i] + dp[S - T][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            dp[S][i] += dist[i][terminals[__builtin_ctz(S)]];
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[(1 << k) - 1][i]);
    }

    return ans;
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> k;
    terminals.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> terminals[i];
        terminals[i]--;
    }

    int ans = steiner_tree();
    cout << ans << endl;

    return 0;
}
