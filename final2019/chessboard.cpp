#include <bits/stdc++.h>
#define maxN 1000000000
using namespace std;

int n, m;
void input()
{
    cin >> n >> m;
}

int main()
{
    input();
    int k = sqrt(m + n);
    int min_m = min(m, n);
    while (k * (k + 1) / 2 > min_m)
        k--;
    cout << k;
}