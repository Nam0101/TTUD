#include <iostream>

using namespace std;

int count_partitions(int n, int m)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m == 0)
        return 0;
    return count_partitions(n, m - 1) + count_partitions(n - m, m);
}
// cải tiến bằng quy hoạch động
// int dp[51][51]; // dp[i][j] = so cach chon các số sao cho tong bang i va so lon nhat la j
// void slove()
// {
//     dp[0][0] = 1;
//     ft(i, 1, 50)
//     {
//         dp[i][0] = 0;
//     }
//     ft(i, 1, 50)
//     {
//         ft(j, 1, 50)
//         {
//             dp[i][j] = dp[i][j - 1];
//             if (i >= j)
//             {
//                 dp[i][j] += dp[i - j][j];
//             }
//         }
//     }
// }

int main()
{
    int n;
    cin >> n;
    cout << count_partitions(n, n) % 1000000007;
    // n là số cần đạt được, m là số lớn nhất có thể chọn
    return 0;
}
