// nhap mot mang cac chuoi tu ban phim khi den sao thi ket thuc nhap , neu ta an tu find cac ki tu thi in ra so chuoi co chua ki tu do neu nhap insert thi nhap them chuoi vao mang
#include <bits/stdc++.h>
using namespace std;
#define N 1000001
queue<string> q1;
queue<string> truyvan;
queue<int> ans;

int main()
{
    string s;
    cin >> s;
    while (s != "*")
    {
        q1.push(s);
        cin >> s;
    }
    string s1;
    cin >> s1;
    while (s1 != "***")
    {
        truyvan.push(s1);
        if (s1 == "find")
        {
            string hoi;
            cin >> hoi;
            queue<string> q3 = q1;
            while (!q3.empty())
            {
                string s2 = q3.front();
                q3.pop();
                int dem = 0;
                if (s2 == hoi)
                {
                    cout << "test " << s2 << endl;
                    dem = 1;
                }
                else
                {
                    dem = 0;
                }
                ans.push(dem);
            }
        }
        else
        {
            string them;
            cin >> them;
            queue<string> q3 = q1;
            while (!q3.empty())
            {
                string s2 = q3.front();
                q3.pop();
                int dem = 0;
                if (s2 == them)
                {
                    dem = 0;
                    q1.push(them);
                }
                else
                {
                    dem = 1;
                }
                ans.push(dem);
            }
        }
        cin >> s1;
    }
    while (!truyvan.empty())
    {
        string s2 = truyvan.front();
        truyvan.pop();
        int s3 = ans.front();
        ans.pop();
        cout << s3 << endl;
    }
}
