#include <bits/stdc++.h>
using namespace std;

int n, k;
void input()
{
    cin >> n >> k;
}
bool isPrime[4001];
vector<int> prime;
void sang()
{
    for (int i = 2; i <= n; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!isPrime[i])
        {
            prime.push_back(i);
        }
    }
}
int res = 0;
bool used[4001];
void Try(int i, int sum, int count)
{
    if (sum == n)
    {
        res++;
        for (int i = 0; i < prime.size(); i++)
        {
            if (used[i])
            {
                cout << prime[i] << " ";
            }
        }
        cout << endl;
        return;
        return;
    }
    if (i >= prime.size() || sum > n || count >= k)
    {
        return;
    }
    // dùng dưới k số
    if (!used[i])
    {
        used[i] = true;
        Try(i + 1, sum + prime[i], count + 1);
        used[i] = false;
    }
    Try(i + 1, sum, count);
}

int main()
{
    input();
    sang();
    Try(0, 0, 0);
    cout << res;
    return 0;
}