#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 100005;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
std::string Insert = "insert";
std::string Delete = "delete-max";
int n;
int number;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> n;
    std::priority_queue<int> prio_queue;
    ft(i, 1, n)
    {
        std::cin >> number;
        prio_queue.push(number);
    }
    std::string s;
    do
    {
        std::cin >> s;
        if (s == "insert")
        {
            int x;
            std::cin >> x;
            prio_queue.push(x);
        }
        if (s == "delete-max")
        {
            std::cout << prio_queue.top() << std::endl;
            prio_queue.pop();
        }
    } while (s != "*");

    return 0;
}