#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start, end;
};

bool compareIntervals(Interval i1, Interval i2)
{
    return (i1.end < i2.end);
}

void printMaxNonOverlappingIntervals(vector<Interval> intervals)
{
    sort(intervals.begin(), intervals.end(), compareIntervals);
    vector<Interval> maxIntervals;
    maxIntervals.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start >= maxIntervals[maxIntervals.size() - 1].end)
        {
            maxIntervals.push_back(intervals[i]);
        }
    }
    cout << "Maximum non-overlapping intervals:" << endl;
    for (auto i : maxIntervals)
    {
        cout << "[" << i.start << ", " << i.end << "]" << endl;
    }
}

int main()
{
    vector<Interval> intervals = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}};
    printMaxNonOverlappingIntervals(intervals);
    return 0;
}
