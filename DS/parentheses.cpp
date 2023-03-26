#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii std::pair<int, int>
const long long MAX = 1e6 + 5;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
std::string s;
std::stack<char> st;
void input()
{
    std::cin >> s;
}
bool parenthese()
{
    st.push(s[0]);
    ft(i, 1, s.size() - 1)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                char top = st.top();
                if (s[i] == ')' && top == '(')
                {
                    st.pop();
                }
                else if (s[i] == ']' && top == '[')
                {

                    st.pop();
                }
                else if (s[i] == '}' && top == '{')
                {

                    st.pop();
                }
                else
                {
                    return st.empty();
                }
            }
        }
    }
    return st.empty();
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    std::cout << parenthese();
}