#include <bits/stdc++.h>
using namespace std;
int n;
int M[30][1000000];
int A[1000000];
void preprocessing()
{
    for (int j = 0; (1 << j) <= n; j++)
    {
        for (int i = 0; i < n; i++)
            M[j][i] = -1;
    }

    for (int i = 0; i < n; i++)
        M[0][i] = i;
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]])
            {
                M[j][i] = M[j - 1][i];
            }
            else
            {
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
            }
        }
    }
}
int rmq(int i, int j)
{
    int k = log2(j - i + 1);
    int p2k = (1 << k); // pow(2,k);
    if (A[M[k][i]] <= A[M[k][j - p2k + 1]])
    {
        return M[k][i];
    }
    else
    {
        return M[k][j - p2k + 1];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    preprocessing();

    int ans = 0;
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int I, J;
        scanf("%d%d", &I, &J);
        ans += A[rmq(I, J)];
    }
    cout << ans;
    return 0;
}