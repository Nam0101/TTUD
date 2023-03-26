#include <iostream>
#include <string>
#include <vector>

using namespace std;

void build_lps(string pattern, vector<int> &lps)
{
    int n = pattern.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m, 0);
    build_lps(pattern, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    kmp(text, pattern);
    return 0;
}
