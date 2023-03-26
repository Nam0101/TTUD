#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const long long MAX = 50;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
struct edge
{
    int v, w;
    edge(int v, int w) : v(v), w(w) {}
};
int n, m, k;
std::vector<edge> adj[MAX];
bool visited[MAX];
std::vector<int> path;
bool visitedPath[MAX];
void input()
{
    int u, v, w;
    std::cin >> n >> m;
    ft(i, 1, m)
    {
        std::cin >> u >> v >> w;
        adj[u].pb(edge(v, w));
        adj[v].pb(edge(u, w));
    }
    std::cin >> k;
    ft(i, 1, k)
    {
        std::cin >> u;
        path.pb(u);
    }
}
void steierTree()
{

    int dp[1 << k][n];
    int INF = 1e9;
    ft(i, 0, (1 << k) - 1)
    {
        ft(j, 0, n - 1)
        {
            dp[i][j] = INF;
        }
    }
    ft(i, 0, k - 1)
    {
        dp[1 << i][path[i]] = 0;
    }
    ft(i, 1, (1 << k) - 1)
    {
        ft(j, 0, n - 1)
        {
            for (int S = i & (i - 1); S > 0; S = (S - 1) & i)
            {
                int sum = dp[S][j] + dp[i - S][j];
                dp[i][j] = std::min(dp[i][j], sum);
            }
            if (dp[i][j] < INF)
            {
                for (auto e : adj[j])
                {
                    int v = e.v, w = e.w;
                    dp[i][v] = std::min(dp[i][v], dp[i][j] + w);
                }
            }
        }
    }
    int res = INF;
    ft(i, 0, n - 1)
    {
        res = std::min(res, dp[(1 << k) - 1][i]);
    }
    std::cout << res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    steierTree();
    return 0;
}