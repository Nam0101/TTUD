#include <bits/stdc++.h>

using namespace std;
int test_case;
int n, m;
int Count = 0;
int num;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    std::cin >> test_case;
    while (test_case--)
    {
        unordered_set<int> set1;
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> num;
            set1.insert(num);
        }
        std::cin >> m;
        for (int i = 1; i <= m; i++)
        {
            std::cin >> num;
            if (set1.find(num) != set1.end())
            {
                Count++;
            }
        }
        std::cout << Count << std::endl;
        Count = 0;
    }
    return 0;
}