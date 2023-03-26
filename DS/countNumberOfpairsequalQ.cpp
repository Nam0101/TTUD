#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1e6 + 5;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
int n, q;
int count;
int a[MAX];
void input()
{
    std::cin >> n >> q;
    ft(i, 1, n) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
}
void solution()
{
    int left = 1;
    int right = n;
    while (left <= right)
    {
        if (a[left] + a[right] == q)
        {
            count++;
            left++;
            right--;
        }
        else if (a[left] + a[right] < q)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    solution();

    std::cout << count-1 << std::endl;
    return 0;
}