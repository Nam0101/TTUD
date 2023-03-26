#include <bits/stdc++.h>
using namespace std;

map<string, string> date;
string addDaysToDate(string days, int h)
{
    cout << days << " " << h << "\n";
    int y = stoi(days.substr(0, 4));
    // int m = stoi(days.substr(5, 2));
    // int d = stoi(days.substr(7, 2));
    cout << y << "\n";
    // d += h / 24;
    // h %= 24;
    // if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    // {
    //     if (d > 31)
    //     {
    //         d %= 31;
    //         m++;
    //     }
    // }
    // else if (m == 4 || m == 6 || m == 9 || m == 11)
    // {
    //     if (d > 30)
    //     {
    //         d %= 30;
    //         m++;
    //     }
    // }
    // else
    // {
    //     if (y % 4 == 0)
    //     {
    //         if (d > 29)
    //         {
    //             d %= 29;
    //             m++;
    //         }
    //     }
    //     else
    //     {
    //         if (d > 28)
    //         {
    //             d %= 28;
    //             m++;
    //         }
    //     }
    // }
    // if (m > 12)
    // {
    //     m %= 12;
    //     y++;
    // }
    string ans = "";
    // if (y < 10)
    //     ans += "000";
    // else if (y < 100)
    //     ans += "00";
    // else if (y < 1000)
    //     ans += "0";
    // ans += to_string(y);
    // ans += "-";
    // if (m < 10)
    //     ans += "0";
    // ans += to_string(m);
    // ans += "-";
    // if (d < 10)
    //     ans += "0";
    // ans += to_string(d);
    return ans;
}
pair<string, int> convert(string time, int sec)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    s += sec;
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
    h %= 24;
    string ans = "";
    if (h < 10)
        ans += "0";
    ans += to_string(h);
    ans += ":";
    if (m < 10)
        ans += "0";
    ans += to_string(m);
    ans += ":";
    if (s < 10)
        ans += "0";
    ans += to_string(s);
    return make_pair(ans, h);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    while (s != "*")
    {
        date[s] = "";
        cin >> s;
    }
    string time;
    int sec;
    do
    {
        cin >> s;
        if (s == "***")
            break;
        cin >> time >> sec;
        date[s] = convert(time, sec).first;
        int h = convert(time, sec).second;
        cout << h << "\n";
        // cout << s.length() << "\n";
        cout << addDaysToDate(s, h) << "\n";
        // string s2 = addDaysToDate(s, h);
        // if (date[s2] != "")
        // {
        //     cout << s2 << " " << date[s] << "\n";
        // }
    } while (true);
}
