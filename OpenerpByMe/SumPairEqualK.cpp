#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1000000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
int n, k;
ll a[MAX];
void input()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
}
ll count = 0;
// void solve()
// {
//     // đếm số cặp có tổng bằng k
//     int tmp = k / 2;

//     for (int i = 0; a[i] <= tmp; i++)
//     {
//         for (int j = n - 1; a[j] > tmp; j--)
//         {
//             // std::cout << "a[" << i << "] " << a[i] << " a[" << j << "] " << a[j] << std::endl;
//             if (a[i] + a[j] == k)
//                 count++;
//             else if (a[i] + a[j] < k)
//                 break;
//             else
//                 continue;
//         }
//     }
// }
int Count;
void slove()
{
    map<int, int> Hash;
    for (int i = 0; i < n; i++)
    {
        if (Hash.find(k - a[i]) != Hash.end())
            Count += Hash[k - a[i]];
        Hash[a[i]]++;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    input();
    std::sort(a, a + n);
    // solve();
    slove();
    std::cout << Count;
    return 0;
}