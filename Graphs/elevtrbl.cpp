// xuất phát ở tầng s của nhà có f tầng. cần đến tầng g
// có thể đi lên u tầng hoặc xuống d tầng mỗi lần bấm nút
// tìm số lần bấm nút nhỏ nhất để đi từ s đến g
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1000000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int f, s, g, u, d;
std::queue<int> q;
std::vector<bool> visited;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> f >> s >> g >> u >> d;
    if (s == g)
    {
        std::cout << 0;
        return 0;
    }
    else
    {
        visited[s] = true;
        q.push(s);
        int res = 0;
        while (!q.empty())
        {
            int k = q.front();
            q.pop();

            if ((k + u) <= f && !visited[k + u])
            {
                visited[k + u] = true;
                q.push(k + u);
                res++;
            }
            if ((k - d) >= 1 && !visited[k - d])
            {
                visited[k - d] = true;
                q.push(k - d);
                res++;
            }
        }
        if (visited[g])
            std::cout << res;
        else
            std::cout << "use the stairs";
    }
}