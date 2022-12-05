// At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. The load of a teacher is the number of courses assigned to her/him. How to assign nn courses to mm teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
// Input
// The input consists of following lines
// Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
// Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
// Line m+2: contains an integer k
// Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
// Output
// The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
// Example
// Input
// 4 12
// 5 1 3 5 10 12
// 5 9 3 4 8 12
// 6 1 2 3 4 9 7
// 7 1 2 3 5 6 10 11
// 25
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 2 6
// 3 5
// 3 7
// 3 10
// 4 6
// 4 9
// 5 6
// 5 7
// 5 8
// 6 8
// 6 9
// 7 8
// 7 10
// 7 11
// 8 9
// 8 11
// 8 12
// 9 12
// 10 11
// 11 12
// Output
// 3

#include <bits/stdc++.h>
using namespace std;
// n teachers, m courses
int n, m;
bool a[11][31];
bool conflict[31][31];
int res = -1;
int x[31];
int Max = -1;
int numOfTeacher = n;
vector<int> P[11]; // P[i] is the list of courses assigned to teacher i
bool check(int teacher, int course)
{
    if (a[teacher][course] == false)
        return false;
    for (int i = 0; i < P[teacher].size(); i++)
        if (conflict[course][P[teacher][i]] == true)
            return false;
    if (Max >= res)
        return false;
    if (numOfTeacher < course)
        return false;
    return true;
}
void Try(int couse_index)
{
    if (couse_index > n)
    {
        // for (int i = 1; i <= m; i++)
        // {
        //     if (P[i].size() < 1)
        //         return;
        // }
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int couse : P[i])
        //     {
        //         if (a[i][couse] == false)
        //             return;
        //     }
        // }
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int couse : P[i])
        //     {
        //         for (int couse2 : P[i])
        //         {
        //             if ((couse != couse2) && conflict[couse][couse2])
        //                 return;
        //         }
        //     }
        // }

        res = min(res, Max);
        return;
    }
    for (int teacher_index = 1; teacher_index <= n; teacher_index++)
    {
        x[couse_index] = teacher_index;
        int pre_numOfTeacher = numOfTeacher;
        if (P[teacher_index].size() == 0)
        {
            numOfTeacher--;
        }
        P[teacher_index].push_back(couse_index);
        int prev = Max;
        Max = max(Max, (int)P[teacher_index].size());
        if (check(teacher_index, couse_index))
        {
            Try(couse_index + 1);
        }
        x[couse_index] = 0;
        numOfTeacher = pre_numOfTeacher;
        P[teacher_index].pop_back();
        Max = prev;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int course;
            cin >> course;
            a[i][course] = true;
        }
    }

    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        conflict[c1][c2] = true;
        conflict[c2][c1] = true;
    }

    res = m;
    Try(1);
    cout << res;

    return 0;
    
}