// input 3
// output 1 2 3
//         1 3 2
//         2 1 3
//         2 3 1
//         3 1 2
//         3 2 1

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
        cout << a[i] << " ";
    }
    
    cout << endl;
}
void Try(int i)
{
    if (i == n + 1)
    {
        printArray();
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        a[i] = j;
        bool ok = true;
        for (int k = 1; k < i; k++)
        {
            if (a[k] == a[i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            Try(i + 1);
        }
    }
}
int main()
{
    input();
    Try(1);
}
