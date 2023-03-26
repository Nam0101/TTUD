#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1000000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
std::string P1, P2, T;
std::vector<char> res;
int length;
void input()
{
    std::cin >> P1 >> P2 >> T;
    length = P1.length();
}
void solution()
{
    int i = 0;

    while (T[i] != '\0')
    {
        //replace P1 in T by P2
        if (T[i] == P1[0])
        {
            int j = 0;
            while (T[i + j] == P1[j])
            {
                j++;
                if (j == length)
                {
                    for (int k = 0; k < length; k++)
                    {
                        T[i + k] = P2[k];
                    }
                    break;
                }
            }
        }

    }
}
int main(){
    input();
    solution();
    std::cout << T;
    return 0;
}