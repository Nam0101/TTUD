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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int num;
    std::stack<int> st;
    std::string cmd;
    std::cin >> cmd;
    while (true)
    {
        if (cmd == "PUSH")
        {
            std::cin >> num;
            st.push(num);
        }
        else if (cmd == "#")
        {
            return 0;
        }
        else
        {
            if (st.empty())
            {
                std::cout << "NULL" << std::endl;
            }
            else
            {
                std::cout << st.top() << std::endl;
                st.pop();
            }
        }
        std::cin >> cmd;
    }
}