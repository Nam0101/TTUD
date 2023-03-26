#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 20;     // Maximum number of vertices in the graph
const int INF = INT_MAX; // Infinity

int n, m, k;                      // Number of vertices, edges, and Steiner points
vector<pair<int, int>> adj[MAXN]; // Graph representation as adjacency list
int dp[1 << MAXN][MAXN];          // Dynamic programming table

// int steiner_tree()
// {
//     // Initialize dynamic programming table
//     for (int i = 0; i < (1 << k); i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             dp[i][j] = INF;
//         }
//     }
//     // Base case: Steiner points are directly connected to the tree
//     for (int i = 0; i < k; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             for (auto e : adj[j])
//             {
//                 int v = e.first, w = e.second;
//                 if (v == i)
//                 {
//                     dp[1 << i][j] = min(dp[1 << i][j], w);
//                 }
//             }
//         }
//     }
//     // Dynamic programming
//     for (int i = 1; i < (1 << k); i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             for (int S = i & (i - 1); S > 0; S = (S - 1) & i)
//             {
//                 dp[i][j] = min(dp[i][j], dp[S][j] + dp[i - S][j]);
//             }
//             if (dp[i][j] < INF)
//             {
//                 for (auto e : adj[j])
//                 {
//                     int v = e.first, w = e.second;
//                     dp[i][v] = min(dp[i][v], dp[i][j] + w);
//                 }
//             }
//         }
//     }
//     // Find minimum Steiner tree cost
//     int res = INF;
//     for (int i = 0; i < n; i++)
//     {
//         res = min(res, dp[(1 << k) - 1][i]);
//     }
//     return res;
// }
int steinerTree()
{
    // Initialize dynamic programming table
    for (int i = 0; i < (1 << k); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = INF;
        }
    }
    // Base case: Steiner points are directly connected to the tree
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto e : adj[j])
            {
                int v = e.first, w = e.second;
                if (v == i)
                {
                    dp[1 << i][j] = min(dp[1 << i][j], w);
                }
            }
        }
    }
    // Dynamic programming
    for (int i = 1; i < (1 << k); i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int S = i & (i - 1); S > 0; S = (S - 1) & i)
            {
                dp[i][j] = min(dp[i][j], dp[S][j] + dp[i - S][j]);
            }
            if (dp[i][j] < INF)
            {
                for (auto e : adj[j])
                {
                    int v = e.first, w = e.second;
                    dp[i][v] = min(dp[i][v], dp[i][j] + w);
                }
            }
        }
    }
    // Find minimum Steiner tree cost
    int res = INF;
    for (int i = 0; i < n; i++)
    {
        res = min(res, dp[(1 << k) - 1][i]);
    }
    return res;
}
// 6 10
// 1 2 1
// 1 3 2
// 1 5 5
// 2 4 7
// 2 5 6
// 3 4 30
// 3 5 4
// 4 5 8
// 4 6 3
// 5 6 7
// 4
// 1 2 3 4
// -> res =10

int main()
{
    // Read input
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        x--;
        adj[n].push_back({x, 0});
        adj[x].push_back({n, 0});
    }
    n++;
    // Compute Steiner tree
    int res = steinerTree();
    // Print result
    cout << res << endl;
}
