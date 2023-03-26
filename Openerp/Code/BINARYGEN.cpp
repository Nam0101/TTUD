#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    string s;
    cin >> n;
    // cin >> s;
    for (int i = 0; i < n; i++)
        s += rand() % 2 + 48;
    cout << s << endl;
    int car = 1;
    bool f = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            f = true;
        }
        int tmp = s[i] - 48 + car;
        if (tmp >= 2)
        {
            car = 1;
        }
        else
        {
            car = 0;
        }

        s[i] = tmp % 2 + 48;
    }
    cout << (f ? s : "-1");
}
