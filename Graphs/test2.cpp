#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e6 + 5;
int n, m, S, T, tot = 1, h[N], cur[N], d[N], q[N];
struct edge
{
    int v, w, nxt;
} e[M << 1];
void add(int u, int v, int w) { e[++tot] = (edge){v, w, h[u]}, h[u] = tot; }
bool bfs()
{
    memset(d, -1, sizeof(d)), d[S] = 0, q[0] = S;
    for (int l = 0, r = 0; l <= r; l++)
    {
        int u = q[l];
        for (int i = h[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (e[i].w && d[v] == -1)
                d[v] = d[u] + 1, q[++r] = v;
        }
    }
    return d[T] != -1;
}
int dfs(int u, int lim)
{
    if (u == T)
        return lim;
    int res = lim, tmp;
    for (int &i = cur[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (e[i].w && d[v] == d[u] + 1 && (tmp = dfs(v, min(res, e[i].w))))
        {
            e[i].w -= tmp, e[i ^ 1].w += tmp, res -= tmp;
            if (!res)
                break;
        }
    }
    return lim - res;
}
int dinic()
{
    int res = 0;
    while (bfs())
        memcpy(cur, h, sizeof(h)), res += dfs(S, 2e9);
    return res;
}
int main()
{
    scanf("%d%d", &n, &m), S = n + 2, T = n + 3;
    for (int i = 1, u, v, w; i <= m; i++)
        scanf("%d%d%d", &u, &v, &w), add(u, v, w), add(v, u, 0);
    for (int i = 2; i <= n + 1; i++)
        if (i & 1)
            add(S, i, 2e9), add(i, S, 0);
        else
            add(i, T, 2e9), add(T, i, 0);
    printf("%d\n", dinic());
}