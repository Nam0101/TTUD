// Given 2 positive integers k and n. Write a program tat generates all k-combinations of 1, 2, ..., n in a lexicographic order. Example Input 2 4 Output 1 2 1 3 1 4 2 3 2 4 3 4
// Path: Final\GenK-N.cpp
#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector<int> v;
void print()
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int getLastInvector()
{
    if (v.size() == 0)
        return 0;
    return v[v.size() - 1];
}
void Try(int i)
{
    if (i == k)
    {
        print();
        return;
    }
    for (int j = getLastInvector() + 1; j <= n; j++)
    {
        v.push_back(j);
        Try(i + 1);
        v.pop_back();
    }
}
int main()
{
    cin >> k >> n;
    Try(0);
    return 0;
}