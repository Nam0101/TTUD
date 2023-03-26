#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1000000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
std::map<std::string, int> m;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string input;
    std::string cmd;
    std::string search;
    std::cin >> input;
    while (input != "*")
    {
        m[input] = 1;
        std::cin >> input;
    }
    std::cin >> cmd;
    while (cmd != "***")
    {
        if (cmd == "find")
        {
            std::cin >> search;
            std::cout << m[search] << std::endl;
        }
        if (cmd == "insert")
        {
            std::cin >> search;
            if (m[search] == 0)
            {
                m[search] = 1;
                std::cout << 1 << std::endl;
            }
            else
            {
                std::cout << 0 << std::endl;
            }
        }
        std::cin >> cmd;
    }
}