#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e9;
int main()
{
    freopen("input.txt", "w", stdout);
    int test_case = 4;
    cout << test_case << endl;
    for (int i = 0; i < test_case; i++)
    {
        int n = rand() % 10000 + 1;
        cout << n << endl;
        for (int j = 0; j < n; j++)
        {
            int x = rand() % MAXN + 1;
            cout << x << " ";
        }
    }
}