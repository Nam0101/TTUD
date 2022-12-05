// Cho một danh sách các hình chữ nhật 1, 2,…, n. Hãy tìm diện tích hình chữ nhật nhỏ nhất bao tất cả các hình chữ nhật trong danh sách trên
// Dữ liệu
// · Dòng 1: chứa số nguyên dương n (1 <= n <= 1000)
// · Dòng i+1 (i=1,…,n): chứa 4 số nguyên dương x1,y1, x2,y2 trong đó (x1,y1) và (x2,y2) là tọa độ 2 đỉnh đối của hình chữ nhật thứ i (1 <= x1, y1, x2, y2 <= 100)
// Kết quả
// · Ghi ra diện tích của hình chữ nhật nhỏ nhất tìm được
// Ví dụ
// Dữ liệu
// 3
// 2 4 2 7
// 3 2 4 7
// 1 2 5 2
// Kết quả
// 20
// Giải thích
// Hình chữ nhật nhỏ nhất bao tất cả các hình chữ nhật trong danh sách trên là hình chữ nhật có 2 đỉnh đối là (1,2) và (5,7)
#include <bits/stdc++.h>
using namespace std;

int n;
int x1[1001], y1[1001], x2[1001], y2[1001];
int res = 1000000000;
void try1(int i)
{
    if (i > n)
    {
        int minx = 1000000000, miny = 1000000000, maxx = -1000000000, maxy = -1000000000;
        for (int j = 1; j <= n; j++)
        {
            minx = min(minx, x1[j]);
            miny = min(miny, y1[j]);
            maxx = max(maxx, x2[j]);
            maxy = max(maxy, y2[j]);
        }
        res = min(res, (maxx - minx) * (maxy - miny));
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        swap(x1[i], x1[j]);
        swap(y1[i], y1[j]);
        swap(x2[i], x2[j]);
        swap(y2[i], y2[j]);
        try1(i + 1);
        swap(x1[i], x1[j]);
        swap(y1[i], y1[j]);
        swap(x2[i], x2[j]);
        swap(y2[i], y2[j]);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    try1(1);
    cout << res;
    return 0;
}