#include <bits/stdc++.h>
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
using namespace std;
int test_case;
int n;
int a[1000005];
void input()
{
    std::cin >> n;
    ft(i, 1, n)
    {
        std::cin >> a[i];
    }
}
// Cho dãy số nguyên a. Dãy con của a là dãy thu được bằng cách xóa đi một số phần tử của a (có thể không xóa
// phần tử nào, cũng có thể xóa hết tất cả). Một dãy con được gọi là đẹp nếu phần tử đứng sau lớn hơn phần tử
// đứng trước đúng một đơn vị
void solution()
{
    int dp[n + 1]; // dp[i] là độ dài dãy con đẹp tăng dần kết thúc tại a[i]
    dp[1] = 1;     // từ 1->1 có 1 phần tử -> dãy có độ dài 1
    ft(i, 2, n)    // duyệt từ 2->n
    {
        dp[i] = 1;      // dp[i] =1 -> là có mỗi cái số đấy
        ft(j, 1, i - 1) // từ 1->i-1
        {
            if (a[i] - a[j] == 1) // nếu mà cái a[i] -a[j] ==1 có thể là dãy đẹp -> có thể thêm a[i] vào dãy đẹp
            {
                // cout << "a[i] = " << a[i] << " a[j] = " << a[j] << endl;
                dp[i] = max(dp[i], dp[j] + 1); // cập nhật cái dp[i] = max(dp[i], dp[j] + 1)
                // cout << "dp[i] = " << dp[i] << endl;
            }
        }
    }
    int res = 0;
    ft(i, 1, n)
    {
        res = max(res, dp[i]);
    }
    std::cout << res << std::endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    std::cin >> test_case;
    while (test_case--)
    {
        input();
        solution();
    }
}