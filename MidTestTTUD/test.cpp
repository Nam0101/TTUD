
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n;
    priority_queue<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push(x);
    }
    string cmd = " ";
    while (true)
    {
        cin >> cmd;
        if (cmd == "*")
            return 0;
        if (cmd == "delete-max")
        {
            int res = a.top();
            cout << res << endl;
            a.pop();
        }
        else if (cmd == "insert")
        {
            cin >> x;
            a.push(x);
        }
    }
    return 0;
}
