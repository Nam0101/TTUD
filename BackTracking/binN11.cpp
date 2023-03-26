// tạo chuỗi nhị phân có độ dài n không chứa 11
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];
void input()
{
    cin >> n;
}

void printArray()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            if (a[i] == 1 && a[i - 1] == 1)
            {
                continue;
            }
            printArray();
        }
        else
        {
            if (a[i] == 1 && a[i - 1] == 1)
            {
                continue;
            }
            Try(i + 1);
        }
    }
}
int main()
{
    input();
    Try(1);
}