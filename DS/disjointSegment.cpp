#include <bits/stdc++.h>
#define pair pair<int, int>
using namespace std;
int n;
vector<pair> segments;
struct disjointSet
{
    vector<int> parent;
    disjointSet(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y)
    {
        parent[find(x)] = find(y);
    }
};
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        segments.push_back({a, b});
    }
}

void solution()
{
    // Sort segments by right end point
    sort(segments.begin(), segments.end(), [](pair a, pair b)
         { return a.second < b.second; });
    disjointSet ds(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int x = ds.find(i);
        if (x == n)
        {
            continue;
        }
        count++;
        ds.merge(x, x + 1);
    }
}
int main()
{
    input();
    solution();
    return 0;
}