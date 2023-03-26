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
int n;
int a[MAX];
long long evenPrevious, oddPrevious, evenPresent, oddPresent;
void input()
{

    std::cin >> n;
    ft(i, 0, n - 1)
    {
        std::cin >> a[i];
    }
}

ll res = 0;
void solution()
{
    ft(i, 0, n - 1)
    {
        if (a[i] & 1)
        {
            if (i - 1 >= 0)
            {
                oddPresent = (oddPrevious + evenPrevious + 1) % 1000000007;
                evenPresent = (evenPrevious + oddPrevious) % 1000000007;
            }
            else
            {
                oddPresent = 1;
                evenPresent = 0;
            }
            oddPrevious = oddPresent;
            evenPrevious = evenPresent;
        }
        else
        {
            if ((i - 1) >= 0)
            {
                evenPresent = (evenPrevious + evenPrevious + 1) % 1000000007;
                oddPresent = (oddPrevious + oddPrevious) % 1000000007;
            }
            else
            {
                oddPresent = 0;
                evenPresent = 1;
            }
            oddPrevious = oddPresent;
            evenPrevious = evenPresent;
        }
    }
}
int main()
{
    // open daychan.txt
    // freopen("Daychan.txt", "r", stdin);
    input();

    solution();
    std::cout << evenPresent % 1000000007;
    return 0;
}