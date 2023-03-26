// de quy quay lui
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int N, K, Q;
int d[MAX];
int x[MAX];
int y[MAX];
int load[MAX];
bool visited[MAX];
int segment;

// int res = 0;
void input()
{
    cin >> N >> K >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> d[i];
    }
}

void solution()
{
    for (int k = 1; k <= K; k++)
    {
        cout << "Route[" << k << "]:0";
        int v = y[k];
        while (v > 0)
        {
            cout << " " << v;
            v = x[v];
        }
        cout << " -----------------------------" << endl;
    }
}

bool checkX(int v, int u, int k)
{
    if (v == 0)
        return true;
    if (visited[v] == true)
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}

void TryX(int u, int k)
{
    for (int v = 0; v <= N; v++)
    {
        if (checkX(v, u, k))
        {
            cout << "v = " << v << " u = " << u << " k = " << k << endl;
            x[k] = v;
            load[k] += d[v];
            visited[v] = true;
            segment += 1;
            if (v == 0)
            {
                if (k == K)
                {
                    if (segment == N + K)
                    {
                        solution();
                    }
                    else
                    {
                        TryX(y[k + 1], k + 1);
                    }
                }
            }
            else
            {
                TryX(v, k);
            }
            visited[v] = false;
            load[k] -= d[v];
            segment -= 1;
        }
    }
}

bool checkY(int v, int k)
{
    if (visited[v] == true)
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}

void TryY(int k)
{
    for (int v = y[k - 1] + 1; v <= N; v++)
    {
        if (checkY(v, k))
        {
            cout << "v = " << v << " k = " << k << endl;
            y[k] = v;
            load[k] += d[v];
            visited[v] = true;
            segment += 1;
            if (k == K)
            {
                TryX(y[1], 1);
            }
            else
            {
                TryY(k + 1);
            }
            load[k] -= d[v];
            visited[v] = false;
            segment -= 1;
        }
    }
}

void solve()
{
    for (int i = 1; i <= K; i++)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= K; i++)
    {
        load[i] = 0;
    }
    segment = 0;
    y[0] = 0;
    TryY(1);
}

int main()
{
    input();
    solve();
    return 0;
}