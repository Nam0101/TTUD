// có n điểm trên Oxy
// tìm 2 điểm có khoảng cách nhỏ nhất
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi std::vector<int>
int n;
struct Point
{
    double x, y;
    int id;
    Point(double x = 0, double y = 0, int id = 0)
    {
        this->x = x;
        this->y = y;
        this->id = id;
    }
} p[100000];
bool cmpX(Point a, Point b)
{
    return a.x < b.x;
}
bool cmpY(Point a, Point b)
{
    return a.y < b.y;
}
double distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
struct Solution
{
    int id1, id2;
    double distance;
    Solution(int id1 = 0, int id2 = 0, double distance = 0)
    {
        this->id1 = id1;
        this->id2 = id2;
        this->distance = distance;
    }
};
Solution slove(int first, int last)
{
    if (first >= last)
    {
        Solution best = Solution(-1, -1, 1e9);
        return best;
    }
    int mid = (first + last) / 2;
    Solution best1 = slove(first, mid);
    Solution best2 = slove(mid + 1, last);
    Solution best = best1.distance < best2.distance ? best1 : best2;

    double d = best.distance;
    std::vector<Point> v;
    for (int i = first; i <= last; i++)
    {
        if (abs(p[i].x - p[mid].x) < d)
        {
            v.pb(p[i]);
        }
    }
    std::sort(v.begin(), v.end(), cmpY);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j].y - v[i].y > d)
                break;
            double d1 = distance(v[i], v[j]);
            if (d1 < best.distance)
            {
                int id1 = v[i].id;
                int id2 = v[j].id;
                if (id1 > id2)
                {
                    std::swap(id1, id2);
                }
                best = Solution(id1, id2, d1);
            }
        }
    }
    return best;
}
int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    std::sort(p, p + n, cmpX);
    Solution best = slove(0, n - 1);
    std::cout << best.id1 << " " << best.id2 << " " << std::fixed << std::setprecision(6) << best.distance;
    return 0;
}