// có n chuồng bò và C con bò
// chuồng bò thú i ở tọa độ x[i]
// sắp xếp con bò vào chuồng bò thú i sao cho khoảng cách giữa 2 con bò liền kề nhau là lớn nhất
// 2<=c<=n<=100000
// 0<=x[i]<=10^9
#include <bits/stdc++.h>
int n, C;
int x[100000];
int s[100000]; // s[i] là chuồng chứa con bò thứ i
void input()
{
    scanf("%d%d", &n, &C);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
}
bool check(int d)
{
    
    s[1] = 1;
    for (int i = 2; i <= C; i++)
    {
        s[i] = -1;
        int k = s[i - 1];
        for (int j = k; j <= n; j++)
        {
            if (x[i] - x[j] >= d)
            {
                s[i] = j;
                break;
            }
        }
        if (s[i] == -1)
        {
            return false;
        }
    }
    return true;
}
int solution()
{
    int minDistance = 0;
    int maxDistance = x[n] - x[1];
    int res = 0;
    while (minDistance <= maxDistance)
    {
        int d = (minDistance + maxDistance) / 2;
        if (check(d))
        {
            res = d;
            minDistance = d + 1;
        }
        else
        {
            maxDistance = d - 1;
        }
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(0); // insert
    std::cin.tie(0);                   // these
    std::cout.tie(0);                  // lines
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        std::sort(x + 1, x + n + 1);
        std::cout << solution() << std::endl;
    }
}