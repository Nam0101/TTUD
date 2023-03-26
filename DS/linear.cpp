#include <bits/stdc++.h>
using namespace std;

int countSol(int coeff[], int start,
             int end, int rhs)
{
    if (rhs == 0)
        return 1;
    int result = 0;

    for (int i = start; i <= end; i++)
        if (coeff[i] <= rhs)
            result += countSol(coeff, i, end,
                               rhs - coeff[i]);

    return result;
}

int main()
{
    int n, M;
    cin >> n >> M;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << countSol(arr, 0, n - 1, M) << endl;
}