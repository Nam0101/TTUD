// tạo chuỗi binary có độ dài n không chứa 11
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
    if (i == n)
    {
        printArray();
        return;
    }
    a[i] = 0;
    Try(i + 1);
    a[i] = 1;
    if (a[i - 1] != 1)
        Try(i + 1);
}
int main()
{
    input();
    Try(1);
}