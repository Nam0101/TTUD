#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
vector<int> adj2[1005];
bool visited[1005];
bool visited2[1005];
stack<int> st;
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }
}
void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
    st.push(u);
}
void DFS2(int u)
{
    visited2[u] = true;
    cout << u << " ";
    for (int v : adj2[u])
    {
        if (!visited2[v])
        {
            DFS2(v);
        }
    }
}
int main()
{
    freopen("kosaraju.txt", "r", stdin);
    int Count = 0;
    input();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited2[u])
        {
            cout << "thanh phan lien thong thu " << Count + 1 << ": " << endl;
            DFS2(u);
            cout << endl;
            Count++;
        }
    }
}