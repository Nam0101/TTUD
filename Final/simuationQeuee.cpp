#include <bits/stdc++.h>
using namespace std;

int number;
string cmd;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> q;
    while (cin >> cmd)
    {
        if (cmd == "PUSH")
        {
            cin >> number;
            q.push(number);
        }
        else if (cmd == "POP")
        {
            if (q.empty())
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else
        {
            return 0;
        }
    }
}