// Given a positive integer n and n positive integers a1,a2,...,an
// Compute the number of positive integer solutions to the equation: a1X+a2Y+...+anZ=n
// Input
// Dòng 1: n và M
// Dòng 2: a1,a2,...,an
// Output
// Số nghiệm nguyên dương
// Ví dụ
// Input
// 3 5
// 1 1 1
// Output
// 6
// using backtracking
#include <bits/stdc++.h>
using namespace std;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
int n, M;
int a[21];
int res = 0;
long long s[21];
long long sum = 0;
void Try(int Index)
{
    if (Index == n + 1)
    {
        if (sum == M)
            res++;
        return;
    }
    int limit = (M - sum - s[Index + 1]) / a[Index];
    ft(i, 1, limit)
    {
        s[Index] = i;
        sum += i * a[Index];
        Try(Index + 1);
        sum -= i * a[Index];
        s[Index] = 0;
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> M;
    ft(i, 1, n) cin >> a[i];
    fdt(i, n, 1) s[i] = s[i + 1] + a[i];
    Try(1);
    cout << res;
    return 0;
}