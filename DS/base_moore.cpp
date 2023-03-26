#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 256;

void badCharHeuristic(char *str, int size, int badchar[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[MAX];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            cout << "Pattern found at index " << s << endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main()
{
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    search(txt, pat);
    return 0;
}
